//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd;
    int newsockfd;
    int portno = 8080;
    struct sockaddr_in serveraddr;
    struct sockaddr_in clientaddr;
    int addrlen = sizeof(clientaddr);
    char buffer[1024];
    int bytes_received;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(portno);

    // Bind address to socket
    if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", portno);

    while (1) {
        // Accept incoming connection
        newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, (socklen_t*)&addrlen);
        if (newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted\n");

        // Send welcome message to client
        send(newsockfd, "Welcome to the server!\n", 24, 0);

        // Receive data from client
        bytes_received = recv(newsockfd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            printf("Connection closed by client or error: %s\n", strerror(errno));
            close(newsockfd);
            continue;
        }

        // Echo received data back to client
        send(newsockfd, buffer, bytes_received, 0);

        // Close connection
        close(newsockfd);
    }

    return 0;
}