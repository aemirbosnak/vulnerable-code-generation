//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments is provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Set up the address structure
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton: Address not supported\n");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send a message to the server
    char message[] = "Hello, world!";
    send(sockfd, message, strlen(message), 0);

    // Receive a response from the server
    char response[1024];
    int n = recv(sockfd, response, sizeof(response), 0);
    response[n] = '\0';

    // Print the response
    printf("Received: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}