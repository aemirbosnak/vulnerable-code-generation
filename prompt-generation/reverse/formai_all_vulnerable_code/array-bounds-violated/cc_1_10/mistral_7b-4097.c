//MISTRAL-7B DATASET v1.0 Category: TCP/IP Programming ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12345
#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, numbytes;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char *greeting = "Hello, Server! It's the GreetingClient here!";

    // Initialize variables
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    printf("Socket created\n");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    printf("Connected to the server\n");

    // Send a greeting message to the server
    if (send(sockfd, greeting, strlen(greeting), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    printf("Greeting message sent to the server\n");

    // Receive the server's response
    numbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (numbytes < 0) {
        perror("ERROR receiving message");
        exit(1);
    }
    buffer[numbytes] = '\0';
    printf("Server's response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}