//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT_NUMBER 80
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *host = "www.example.com"; // default host
    char *path = "/"; // default path
    int sock_fd, bytes_sent, bytes_recv;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // parse arguments
    if (argc > 1) {
        host = argv[1];
    }
    if (argc > 2) {
        path = argv[2];
    }

    // create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // resolve hostname
    server = gethostbyname(host);
    if (server == NULL) {
        perror("Error resolving hostname");
        return 1;
    }

    // setup server address
    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT_NUMBER);

    // connect to server
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // construct request
    char request[MAX_BUFFER_SIZE];
    snprintf(request, MAX_BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    // send request
    bytes_sent = send(sock_fd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("Error sending request");
        return 1;
    }

    // receive response
    char response[MAX_BUFFER_SIZE];
    bytes_recv = recv(sock_fd, response, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_recv < 0) {
        perror("Error receiving response");
        return 1;
    }
    response[bytes_recv] = '\0';

    // print response
    printf("Response from server:\n%s", response);

    // close socket
    close(sock_fd);

    return 0;
}