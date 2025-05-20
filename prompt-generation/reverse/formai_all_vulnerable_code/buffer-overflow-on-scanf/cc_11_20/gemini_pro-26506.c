//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define BUFF_SIZE 1024

void main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buff[BUFF_SIZE];

    // Check for arguments
    if (argc < 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive initial message
    n = recv(sockfd, buff, BUFF_SIZE, 0);
    if (n < 0) {
        perror("Error receiving initial message");
        exit(1);
    }

    printf("%s\n", buff);

    // Send login credentials
    printf("Enter username: ");
    scanf("%s", buff);
    n = send(sockfd, buff, strlen(buff), 0);
    if (n < 0) {
        perror("Error sending username");
        exit(1);
    }

    printf("Enter password: ");
    scanf("%s", buff);
    n = send(sockfd, buff, strlen(buff), 0);
    if (n < 0) {
        perror("Error sending password");
        exit(1);
    }

    // Receive login response
    n = recv(sockfd, buff, BUFF_SIZE, 0);
    if (n < 0) {
        perror("Error receiving login response");
        exit(1);
    }

    printf("%s\n", buff);

    // Enter FTP loop
    while (1) {
        // Print FTP prompt
        printf("ftp> ");

        // Read user command
        scanf("%s", buff);

        // Send command to server
        n = send(sockfd, buff, strlen(buff), 0);
        if (n < 0) {
            perror("Error sending command");
            exit(1);
        }

        // Receive response from server
        n = recv(sockfd, buff, BUFF_SIZE, 0);
        if (n < 0) {
            perror("Error receiving response");
            exit(1);
        }

        // Print response to user
        printf("%s\n", buff);

        // Check for quit command
        if (strcmp(buff, "QUIT") == 0) {
            break;
        }
    }

    // Close socket
    close(sockfd);
}