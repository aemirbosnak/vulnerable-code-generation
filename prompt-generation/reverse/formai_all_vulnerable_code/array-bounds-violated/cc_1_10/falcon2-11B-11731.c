//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address and port
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address and port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    // Accept a single connection
    int connfd = accept(sockfd, NULL, NULL);
    if (connfd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Receive data from the client
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytes_read = recv(connfd, buffer, sizeof(buffer), 0);
    if (bytes_read < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_read] = '\0';

    // Print the received data
    printf("Received data: %s\n", buffer);

    // Send a response to the client
    send(connfd, "Thank you for your message!\n", strlen("Thank you for your message!\n"), 0);

    // Close the socket
    close(sockfd);
    return 0;
}