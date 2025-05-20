//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFS 1024
#define PORT 8000

char buffer[BUFS];
char command[BUFS];

int create_socket(char* ip) {
    struct sockaddr_in server;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("Error: Could not create socket!");
        exit(1);
    }

    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error: Could not connect to FTP server!");
        exit(1);
    }

    return sock;
}

void recv_file(int sock, char* file) {
    int fd = open(file, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if(fd == -1) {
        perror("Error: Could not open file for writing!");
        exit(1);
    }

    int n = recv(sock, buffer, BUFS, 0);
    while(n > 0) {
        int written = write(fd, buffer, n);
        if(written < 0) {
            perror("Error: Could not write to file!");
            exit(1);
        }

        n = recv(sock, buffer, BUFS, 0);
    }

    printf("File downloaded successfully!\n");
}

void send_file(int sock, char* file) {
    int fd = open(file, O_RDONLY);
    if(fd == -1) {
        perror("Error: Could not open file for reading!");
        exit(1);
    }

    int n = read(fd, buffer, BUFS);
    while(n > 0) {
        int sent = send(sock, buffer, n, 0);
        if(sent < 0) {
            perror("Error: Could not send file data!");
            exit(1);
        }

        n = read(fd, buffer, BUFS);
    }

    printf("File uploaded successfully!\n");
}

void process_command(int sock) {
    int exit_flag = 0;

    while(!exit_flag) {
        memset(command, 0, BUFS);
        printf("FTP Client$ ");
        fgets(command, BUFS, stdin);

        if(strncmp(command, "cd", 2) == 0) {

            if(send(sock, command, strlen(command), 0) < 0) {
                perror("Error: Could not send data to server!");
                exit(1);
            }

            memset(buffer, 0, BUFS);
            if(recv(sock, buffer, BUFS, 0) < 0) {
                perror("Error: Could not receive data from server!");
                exit(1);
            }

            printf("%s\n", buffer);
        }

        else if(strncmp(command, "ls", 2) == 0) {
            if(send(sock, command, strlen(command), 0) < 0) {
                perror("Error: Could not send data to server!");
                exit(1);
            }

            memset(buffer, 0, BUFS);
            if(recv(sock, buffer, BUFS, 0) < 0) {
                perror("Error: Could not receive data from server!");
                exit(1);
            }

            printf("%s\n", buffer);
        }

        else if(strncmp(command, "get", 3) == 0) {
            char file[BUFS];
            sscanf(command+4, "%s", file);

            if(send(sock, command, strlen(command), 0) < 0) {
                perror("Error: Could not send data to server!");
                exit(1);
            }

            recv_file(sock, file);
        }

        else if(strncmp(command, "put", 3) == 0) {
            char file[BUFS];
            sscanf(command+4, "%s", file);

            if(send(sock, command, strlen(command), 0) < 0) {
                perror("Error: Could not send data to server!");
                exit(1);
            }

            send_file(sock, file);
        }

        else if(strncmp(command, "quit", 4) == 0) {
            if(send(sock, command, strlen(command), 0) < 0) {
                perror("Error: Could not send quit command to server!");
                exit(1);
            }

            exit_flag = 1;
        }
  
        else {
            printf("Invalid command!\n");
        }
    }
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: ./ftp-client <server ip-address>\n");
        exit(1);
    }

    int sock = create_socket(argv[1]);

    printf("Connected to FTP server.\n\n");

    process_command(sock);

    printf("Closing connection...\n");

    close(sock);

    return 0;
}