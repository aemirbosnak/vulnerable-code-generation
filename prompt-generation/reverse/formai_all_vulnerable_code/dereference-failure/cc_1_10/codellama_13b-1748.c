//Code Llama-13B DATASET v1.0 Category: Networking ; Style: high level of detail
// A simple C networking example program that sends a message to a server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080 // port number

int main(int argc, char *argv[]) {
    int sockfd; // socket file descriptor
    struct sockaddr_in serv_addr; // server address structure
    struct hostent *server; // server information structure
    char message[] = "Hello, World!"; // message to send

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // set up server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    server = gethostbyname("www.example.com");
    if (server == NULL) {
        perror("server lookup failed");
        exit(1);
    }
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        exit(1);
    }

    // send message
    send(sockfd, message, strlen(message), 0);

    // receive response
    char buffer[1024];
    int n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("receive failed");
        exit(1);
    }
    printf("Received: %s\n", buffer);

    // close socket
    close(sockfd);

    return 0;
}