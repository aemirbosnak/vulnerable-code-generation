//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * Sends an HTTP GET request to the given host and port,
 * with the specified path. The server response is printed
 * to standard output.
 */
void http_get(char* host, int port, char* path) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;
    char buffer[BUFFER_SIZE];

    // Resolve the hostname to an IP address
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host '%s'\n", host);
        exit(1);
    }

    // Open a socket to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: could not create socket");
        exit(1);
    }

    // Initialize the server address struct
    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: could not connect to server");
        exit(1);
    }

    // Send the HTTP GET request
    snprintf(buffer, BUFFER_SIZE, "GET %s HTTP/1.0\r\nHost: %s:%d\r\n\r\n", path, host, port);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error: could not send request");
        exit(1);
    }

    // Receive the response and print to stdout
    while ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    printf("\n");

    // Clean up
    close(sockfd);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <path>\n", argv[0]);
        exit(1);
    }

    char* host = argv[1];
    int port = atoi(argv[2]);
    char* path = argv[3];

    http_get(host, port, path);

    return 0;
}