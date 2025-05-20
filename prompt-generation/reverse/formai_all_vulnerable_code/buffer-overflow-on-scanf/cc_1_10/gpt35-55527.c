//FormAI DATASET v1.0 Category: Networking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    printf("Welcome to my C Networking example program!\n");
    printf("In this program, we'll create a simple TCP client.\n\n");

    // Let's start by creating the socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: unable to create socket!\n");
        return -1;
    }

    // Set up the server address structure.
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Error: invalid address or address not supported!\n");
        return -1;
    }

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: unable to connect to server!\n");
        return -1;
    }
    printf("Connected to server successfully!\n");

    // Send a message to the server.
    char message[100];
    printf("Enter a message to send to the server: ");
    scanf("%s", message);
    int message_len = strlen(message);
    if (send(sockfd, message, message_len, 0) != message_len) {
        printf("Error: unable to send message to server!\n");
        return -1;
    }
    printf("Message sent to server successfully!\n");

    // Receive a message from the server.
    char buffer[100];
    int buffer_len;
    if ((buffer_len = recv(sockfd, buffer, 100, 0)) < 0) {
        printf("Error: unable to receive message from server!\n");
        return -1;
    }
    printf("Received message from server: %.*s\n", buffer_len, buffer);

    // Close the socket and exit.
    close(sockfd);
    printf("Thank you for trying out my C Networking example program!\n");

    return 0;
}