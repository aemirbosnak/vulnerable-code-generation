//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 512

// Function to connect to the FTP server
int connect_to_server(char *ip_address, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    // Set server address details
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_port = htons(port);
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }
    
    // Receive connection acknowledgement
    char buffer[BUF_SIZE];
    bzero(buffer, BUF_SIZE);
    recv(sockfd, buffer, BUF_SIZE, 0);
    printf("%s", buffer);
    return sockfd;
}

int main(int argc, char *argv[]) {
    // Check if server IP address and port are passed as command line arguments
    if (argc != 3) {
        printf("Usage: %s <server_ip_address> <port_number>\n", argv[0]);
        exit(1);
    }
    
    int sockfd = connect_to_server(argv[1], atoi(argv[2]));
    char command[BUF_SIZE];
    char buffer[BUF_SIZE];
    char filename[BUF_SIZE];
    int n;
    
    while (1) {
        printf("Enter command (get/put/list/quit): ");
        bzero(command, BUF_SIZE);
        scanf("%s", command);
        
        // Send command to server
        send(sockfd, command, strlen(command), 0);
        
        if (strncmp(command, "get", 3) == 0) {
            // Receive filename from server
            bzero(buffer, BUF_SIZE);
            recv(sockfd, buffer, BUF_SIZE, 0);
            if (strcmp(buffer, "File not found") == 0) {
                printf("File not found on server.\n");
            }
            else {
                printf("File found on server. Starting download...\n");
                
                // Create file in client
                bzero(filename, BUF_SIZE);
                strncpy(filename, buffer, strlen(buffer)-1);
                FILE *fp = fopen(filename, "wb");
                if (fp == NULL) {
                    perror("Failed to create file on client");
                    exit(1);
                }
                
                // Receive file contents from server and write to file in chunks
                bzero(buffer, BUF_SIZE);
                int bytes_received = 0;
                while ((n = recv(sockfd, buffer, BUF_SIZE, 0)) > 0) {
                    bytes_received += n;
                    fwrite(buffer, sizeof(char), n, fp);
                    bzero(buffer, BUF_SIZE);
                }
                if (n == 0) {
                    printf("File download successful. %d bytes received.\n", bytes_received);
                }
                else {
                    perror("Failed to receive file from server");
                }
                fclose(fp);
            }
        }
        else if (strncmp(command, "put", 3) == 0) {
            // Receive filename from user
            bzero(filename, BUF_SIZE);
            scanf("%s", filename);
            
            // Check if file exists on client
            struct stat st;
            if (stat(filename, &st) != 0) {
                printf("File not found on client.\n");
            }
            else {
                // Send file contents to server in chunks
                printf("File found on client. Starting upload...\n");
                FILE *fp = fopen(filename, "rb");
                if (fp == NULL) {
                    perror("Failed to read file on client");
                    exit(1);
                }
                bzero(buffer, BUF_SIZE);
                int bytes_sent = 0;
                while ((n = fread(buffer, sizeof(char), BUF_SIZE, fp)) > 0) {
                    bytes_sent += n;
                    send(sockfd, buffer, n, 0);
                    bzero(buffer, BUF_SIZE);
                }
                if (n == 0) {
                    printf("File upload successful. %d bytes sent.\n", bytes_sent);
                }
                else {
                    perror("Failed to send file to server");
                }
                fclose(fp);
            }
        }
        else if (strncmp(command, "list", 4) == 0) {
            // Receive list of files from server
            bzero(buffer, BUF_SIZE);
            int bytes_received = 0;
            while ((n = recv(sockfd, buffer, BUF_SIZE, 0)) > 0) {
                bytes_received += n;
                printf("%s", buffer);
                bzero(buffer, BUF_SIZE);
            }
            if (n == 0) {
                printf("List of files received. %d bytes received.\n", bytes_received);
            }
            else {
                perror("Failed to receive list of files from server");
            }
        }
        else if (strncmp(command, "quit", 4) == 0) {
            // Send quit command to server and close connection
            send(sockfd, "quit", 4, 0);
            close(sockfd);
            printf("Connection closed.\n");
            exit(0);
        }
        else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}