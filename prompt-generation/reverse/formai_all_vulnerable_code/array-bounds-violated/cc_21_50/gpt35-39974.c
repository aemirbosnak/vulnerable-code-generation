//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    // check if enough command-line arguments are provided
    if (argc < 3) {
        printf("Usage: ftpclient <server address> <port number>\n");
        exit(1);
    }

    char *server_addr = argv[1];
    int port_no = atoi(argv[2]);
    
    // create socket
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Failed to create socket");
        exit(1);
    }
    
    // construct server address structure
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_addr);
    server.sin_port = htons(port_no);
    
    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("Failed to connect to server");
        exit(1);
    }
    printf("Connected to server %s:%d\n", server_addr, port_no);
    
    char buf[BUFSIZE];
    memset(buf, 0, BUFSIZE);
    ssize_t num_bytes;
    int file_fd;
    
    // receive welcome message from server
    if ((num_bytes = recv(sockfd, buf, BUFSIZE-1, 0)) == -1) {
        perror("Failed to receive message from server");
        exit(1);
    }
    buf[num_bytes] = '\0';
    printf("%s\n", buf);
    
    // login to server
    printf("Enter your username: ");
    fgets(buf, BUFSIZE, stdin);
    buf[strcspn(buf, "\n")] = 0;
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("Failed to send username to server");
        exit(1);
    }

    printf("Enter your password: ");
    fgets(buf, BUFSIZE, stdin);
    buf[strcspn(buf, "\n")] = 0;
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("Failed to send password to server");
        exit(1);
    }
    
    // receive login success message from server
    memset(buf, 0, BUFSIZE);
    if ((num_bytes = recv(sockfd, buf, BUFSIZE-1, 0)) == -1) {
        perror("Failed to receive message from server");
        exit(1);
    }
    buf[num_bytes] = '\0';
    printf("%s\n", buf);
    
    // enter command loop
    while (1) {
        printf("Enter command (get <file_name> | put <file_name> | exit): ");
        fgets(buf, BUFSIZE, stdin);
        buf[strcspn(buf, "\n")] = 0;
        
        // exit command
        if (strcmp(buf, "exit") == 0) {
            if (send(sockfd, buf, strlen(buf), 0) == -1) {
                perror("Failed to send exit command to server");
                exit(1);
            }
            break;
        }
        
        // get command
        if (strstr(buf, "get ") == buf) {
            // send get command to server
            if (send(sockfd, buf, strlen(buf), 0) == -1) {
                perror("Failed to send get command to server");
                exit(1);
            }

            // receive file size
            memset(buf, 0, BUFSIZE);
            if ((num_bytes = recv(sockfd, buf, BUFSIZE-1, 0)) == -1) {
                perror("Failed to receive message from server");
                exit(1);
            }
            buf[num_bytes] = '\0';
            int file_size = atoi(buf);
            
            // receive file data and save to disk
            char filename[BUFSIZE];
            char *temp = buf + 4; // start of file name in buf
            strcpy(filename, temp);
            filename[strlen(temp)] = '\0';
            file_fd = open(filename, O_WRONLY | O_CREAT, 0644);
            if (file_fd == -1) {
                perror("Failed to create file");
                exit(1);
            }
            memset(buf, 0, BUFSIZE);
            int total_bytes = 0;
            while (total_bytes < file_size) {
                if ((num_bytes = recv(sockfd, buf, BUFSIZE-1, 0)) == -1) {
                    perror("Failed to receive message from server");
                    exit(1);
                }
                total_bytes += num_bytes;
                write(file_fd, buf, num_bytes);
                memset(buf, 0, BUFSIZE);
            }
            close(file_fd);
            printf("File %s downloaded successfully\n", filename);
        }
        
        // put command
        else if (strstr(buf, "put ") == buf) {
            // send put command to server
            if (send(sockfd, buf, strlen(buf), 0) == -1) {
                perror("Failed to send put command to server");
                exit(1);
            }
            
            // get file size
            char filename[BUFSIZE];
            char *temp = buf + 4; // start of file name in buf
            strcpy(filename, temp);
            filename[strlen(temp)] = '\0';
            file_fd = open(filename, O_RDONLY);
            if (file_fd == -1) {
                perror("Failed to open file");
                exit(1);
            }
            int file_size = lseek(file_fd, 0, SEEK_END);
            lseek(file_fd, 0, SEEK_SET);
            sprintf(buf, "%d", file_size);
            if (send(sockfd, buf, strlen(buf), 0) == -1) {
                perror("Failed to send file size to server");
                exit(1);
            }
            
            // send file data
            int total_bytes = 0;
            while (total_bytes < file_size) {
                num_bytes = read(file_fd, buf, BUFSIZE-1);
                if (num_bytes == -1) {
                    perror("Failed to read file");
                    exit(1);
                }
                total_bytes += num_bytes;
                if (send(sockfd, buf, num_bytes, 0) == -1) {
                    perror("Failed to send file data to server");
                    exit(1);
                }
            }
            close(file_fd);
            printf("File %s uploaded successfully\n", filename);
        }
        
        else {
            printf("Invalid command\n");
        }
    }
    
    // close socket
    close(sockfd);
    return 0;
}