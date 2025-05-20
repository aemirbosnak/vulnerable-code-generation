//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MYPORT "8080"
#define MAX 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, sd;
    char buffer[MAX], *message = "Welcome to the server!";
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Socket failed");

    puts("Socket created");

    // Set the socket options
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *) 1, sizeof(int));
    setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, (char *) 1, sizeof(int));

    // Fill server address structure
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(MYPORT));

    // Bind the server address to socket
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("Bind failed");

    puts("Bind done");

    // Listen to the socket
    if (listen(sockfd, 3) < 0)
        error("Listen failed");

    puts("Server is listening");

    while(1) {
        // Accept the client request
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("Accept failed");

        puts("Client connected");

        // Send welcome message to client
        send(newsockfd, message, strlen(message), 0);

        // Receive message from client
        bzero(buffer, MAX);
        sd = recv(newsockfd, buffer, MAX, 0);
        if (sd <= 0) {
            puts("No message received");
            close(newsockfd);
            continue;
        }

        // Print the received message
        buffer[sd] = '\0';
        printf("Received message : %s\n", buffer);

        // Close the socket
        close(newsockfd);
    }

    return 0;
}