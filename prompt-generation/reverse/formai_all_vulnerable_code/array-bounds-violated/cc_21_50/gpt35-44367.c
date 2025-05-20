//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, data_sockfd, recv_bytes, send_bytes, ret;
    struct sockaddr_in serveraddr, data_serveraddr;
    char buffer[BUFFER_SIZE], command[BUFFER_SIZE], filename[BUFFER_SIZE], mode[] = "octet";
    ssize_t file_size = 0, wrote_bytes = 0;
    bool is_connected = false;

    // check for correct arguments
    if (argc != 3) {
        printf("Usage: %s <server IP> <port number>\n", argv[0]);
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // initialize server address struct
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &(serveraddr.sin_addr)) <= 0) {
        perror("Error converting IP address");
        exit(1);
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    is_connected = true;

    // main loop
    while (true) {
        // get user input
        printf("ftp-client> ");
        fgets(command, BUFFER_SIZE, stdin);

        // remove newline character
        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

        // check for exit command
        if (strcmp(command, "exit") == 0) {
            if (is_connected) {
                close(sockfd);
            }
            exit(0);
        }

        // send command to server
        send_bytes = send(sockfd, command, strlen(command), 0);
        if (send_bytes == -1) {
            perror("Error sending command");
            continue;
        }

        // parse command
        sscanf(command, "%s %s", buffer, filename);

        // handle get command
        if (strcmp(buffer, "get") == 0) {
            // receive size of file to be transferred
            recv_bytes = recv(sockfd, &file_size, sizeof(file_size), 0);
            if (recv_bytes == -1) {
                perror("Error receiving file size");
                continue;
            }
            if (file_size == -1) {
                printf("Error: file not found on server\n");
                continue;
            }
            printf("Receiving file %s, %zd bytes\n", filename, file_size);

            // open file for writing
            int fd = open(filename, O_CREAT | O_WRONLY, 0644);
            if (fd == -1) {
                perror("Error creating file");
                continue;
            }

            // receive file data
            wrote_bytes = 0;
            while (wrote_bytes < file_size) {
                ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
                if (ret == -1) {
                    perror("Error receiving file data");
                    close(fd);
                    continue;
                }
                if (ret == 0) {
                    break;
                }
                int written_bytes = write(fd, buffer, ret);
                if (written_bytes == -1) {
                    perror("Error writing to file");
                    close(fd);
                    continue;
                }
                wrote_bytes += written_bytes;
                printf("\rReceived %zd / %zd bytes", wrote_bytes, file_size);
                fflush(stdout);
            }

            // close file
            close(fd);

            // print message
            printf("\nFile %s received successfully\n", filename);
        }

        // handle put command
        if (strcmp(buffer, "put") == 0) {
            // open file for reading
            int fd = open(filename, O_RDONLY);
            if (fd == -1) {
                printf("Error: file %s not found\n", filename);
                continue;
            }

            // get file size
            file_size = lseek(fd, 0, SEEK_END);
            if (file_size == -1) {
                perror("Error reading file size");
                close(fd);
                continue;
            }
            lseek(fd, 0, SEEK_SET);

            // send size of file to server
            send_bytes = send(sockfd, &file_size, sizeof(file_size), 0);
            if (send_bytes == -1) {
                perror("Error sending file size");
                close(fd);
                continue;
            }

            // send file data
            printf("Sending file %s, %zd bytes\n", filename, file_size);
            wrote_bytes = 0;
            while (wrote_bytes < file_size) {
                ret = read(fd, buffer, BUFFER_SIZE);
                if (ret == -1) {
                    perror("Error reading from file");
                    close(fd);
                    continue;
                }
                if (ret == 0) {
                    break;
                }
                ret = send(sockfd, buffer, ret, 0);
                if (ret == -1) {
                    perror("Error sending file data");
                    close(fd);
                    continue;
                }
                wrote_bytes += ret;
                printf("\rSent %zd / %zd bytes", wrote_bytes, file_size);
                fflush(stdout);
            }

            // close file
            close(fd);

            // print message
            printf("\nFile %s sent successfully\n", filename);
        }
    }

    return 0;
}