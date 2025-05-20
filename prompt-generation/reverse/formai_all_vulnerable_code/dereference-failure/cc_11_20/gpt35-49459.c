//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[2]);
    if (port <= 0 || port > 65535) {
        printf("Invalid port number: %d\n", port);
        return 1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket!\n");
        return 1;
    }

    // Connect to server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Failed to connect to server!\n");
        return 1;
    }
    printf("Connected to the server!\n");

    // Start requesting files
    while (1) {
        printf("Enter command (1: list files, 2: download file, 3: exit): ");
        int command;
        scanf("%d", &command);

        if (command == 1) {
            // Send request for file list
            char buffer[] = "LIST";
            send(sockfd, buffer, strlen(buffer), 0);

            // Receive file list
            char recv_buffer[BUFFER_SIZE];
            int bytes_received = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);
            if (bytes_received < 0) {
                printf("Failed to receive file list!\n");
                continue;
            }
            printf("File list:\n%s\n", recv_buffer);
        } else if (command == 2) {
            // Get file name input
            printf("Enter file name: ");
            char file_name[BUFFER_SIZE];
            scanf("%s", file_name);

            // Send file request
            char buffer[BUFFER_SIZE];
            sprintf(buffer, "DOWNLOAD %s", file_name);
            send(sockfd, buffer, strlen(buffer), 0);

            // Check if file exists
            int file_exists = 0;
            int bytes_received = recv(sockfd, &file_exists, sizeof(file_exists), 0);
            if (bytes_received < 0) {
                printf("Failed to receive file info!\n");
                continue;
            }
            if (!file_exists) {
                printf("File does not exist!\n");
                continue;
            }

            // Receive file contents
            FILE *fp = fopen(file_name, "wb");
            if (!fp) {
                printf("Failed to create file!\n");
                continue;
            }
            while (1) {
                char buffer[BUFFER_SIZE];
                int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
                if (bytes_received <= 0) {
                    break;
                }
                fwrite(buffer, sizeof(char), bytes_received, fp);
            }
            fclose(fp);
            printf("Download complete!\n");
        } else if (command == 3) {
            // Send exit command and close socket
            char buffer[] = "EXIT";
            send(sockfd, buffer, strlen(buffer), 0);
            printf("Exiting...\n");
            close(sockfd);
            break;
        } else {
            // Invalid command
            printf("Invalid command!\n");
        }
    }

    return 0;
}