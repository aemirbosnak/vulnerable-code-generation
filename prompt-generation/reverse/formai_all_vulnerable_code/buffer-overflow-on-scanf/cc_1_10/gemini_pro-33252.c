//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main() {
    // Initialize variables
    int sockfd, port, i;
    struct sockaddr_in serv_addr;
    char buff[BUFF_SIZE];

    // Prompt for hostname and port number
    printf("Enter hostname: ");
    scanf("%s", buff);
    printf("Enter port number: ");
    scanf("%d", &port);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set server address and port number
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(buff);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        return -1;
    }

    // Send a message to the server
    strcpy(buff, "Hello, server!");
    if (send(sockfd, buff, strlen(buff), 0) < 0) {
        perror("Error sending message to server");
        close(sockfd);
        return -1;
    }

    // Receive a message from the server
    if (recv(sockfd, buff, BUFF_SIZE, 0) < 0) {
        perror("Error receiving message from server");
        close(sockfd);
        return -1;
    }

    // Print the message from the server
    printf("Message from server: %s\n", buff);

    // Close the socket
    close(sockfd);

    return 0;
}