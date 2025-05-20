//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: sophisticated
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Configure the server address.
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    char client_message[255];
    printf("Enter your message: ");
    scanf(" %s", client_message);

    // Send the message to the server.
    if (write(sockfd, client_message, strlen(client_message)) == -1) {
        perror("write");
        exit(1);
    }

    // Receive the response from the server.
    char server_response[255];
    if (read(sockfd, server_response, sizeof(server_response)) == -1) {
        perror("read");
        exit(1);
    }

    // Print the response from the server.
    printf("Response from the server: %s\n", server_response);

    // Close the socket.
    close(sockfd);

    return 0;
}