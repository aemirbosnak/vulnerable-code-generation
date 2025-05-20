//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 2048

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in addr;
    char buffer[BUF_SIZE];
    ssize_t n;

    if (argc != 3) {
        printf("Usage: ./ftpclient <IpAddress> <Port>");
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set server information
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1) {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }

    printf("Successfully connected to server!\n");

    // Receive welcome message from server
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    if (n == -1) {
        perror("Failed to receive welcome message");
        exit(EXIT_FAILURE);
    }
    printf("Welcome message from server: %.*s\n", (int)n, buffer);

    while (1) {
        // Get user input
        printf("Enter command (quit/get <filename>): ");
        fgets(buffer, BUF_SIZE, stdin);

        // Send command to server
        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("Failed to send command to server");
            exit(EXIT_FAILURE);
        }

        // Check if user wants to quit
        if (strncmp(buffer, "quit", strlen("quit")) == 0) {
            printf("Closing connection...\n");
            close(sockfd);
            break;
        }

        // Check if user wants to get file
        if (strncmp(buffer, "get", strlen("get")) == 0) {
            FILE *fp;
            char filepath[100], filename[100];
            int filesize;

            // Get remote filename
            sscanf(buffer, "%*[^\"]\"%99[^\"]", filename);
            snprintf(filepath, sizeof(filepath), "./downloads/%s", filename);

            // Receive filesize from server
            n = recv(sockfd, buffer, BUF_SIZE, 0);
            if (n == -1) {
                perror("Failed to receive filesize from server");
                exit(EXIT_FAILURE);
            }
            sscanf(buffer, "%d", &filesize);

            // Create file to save downloaded data
            fp = fopen(filepath, "wb");
            if (fp == NULL) {
                perror("Failed to create/write file");
                exit(EXIT_FAILURE);
            }

            // Receive file data from server and write it to file
            int bytes_received = 0;
            while (bytes_received < filesize) {
                n = recv(sockfd, buffer, BUF_SIZE, 0);
                if (n == -1) {
                    perror("Failed to receive file data from server");
                    exit(EXIT_FAILURE);
                }
                fwrite(buffer, sizeof(char), n, fp);
                bytes_received += n;
            }
            fclose(fp);

            printf("File saved as %s\n", filepath);
        }

        // Receive response from server
        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n == -1) {
            perror("Failed to receive response from server");
            exit(EXIT_FAILURE);
        }
        printf("Response from server: %.*s\n", (int)n, buffer);
    }

    return 0;
}