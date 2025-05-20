//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: enthusiastic
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFSIZE];
    int bytes_sent, bytes_received;

    // Checking the parameters
    if (argc != 3) {
        printf("Usage: %s <Server IP> <Port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Clear the server address structure before using it
    memset(&servaddr, 0, sizeof(servaddr));

    // Fill in the server address information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("Invalid IP address");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to server at %s:%s\n", argv[1], argv[2]);

    // Main communication loop
    while (1) {
        printf("Enter some text: ");
        fgets(buffer, BUFSIZE, stdin);

        bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
        if (bytes_sent == -1) {
            perror("Data sending failed");
            exit(1);
        }

        bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
        if (bytes_received == -1) {
            perror("Data receiving failed");
            exit(1);
        }
        buffer[bytes_received] = '\0';

        printf("Server response: %s", buffer);
    }

    close(sockfd);
    return 0;
}