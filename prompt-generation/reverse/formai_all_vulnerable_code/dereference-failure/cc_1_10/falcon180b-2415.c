//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *hostname = "www.example.com";
    int port = 80;
    char *request_path = "/index.html";
    char *request_method = "GET";
    int socket_fd;
    struct addrinfo hints, *servinfo;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int status;

    printf("Building HTTP client...\n");

    // Initialize socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    // Set up address structure
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Look up server address
    status = getaddrinfo(hostname, NULL, &hints, &servinfo);
    if (status!= 0) {
        printf("Error: Failed to look up server address\n");
        exit(1);
    }

    // Connect to server
    status = connect(socket_fd, servinfo->ai_addr, servinfo->ai_addrlen);
    if (status == -1) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    // Send request
    snprintf(buffer, BUFFER_SIZE, "%s %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n",
             request_method, request_path, hostname);
    bytes_received = send(socket_fd, buffer, strlen(buffer), 0);
    if (bytes_received == -1) {
        printf("Error: Failed to send request\n");
        exit(1);
    }

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error: Failed to receive response\n");
        exit(1);
    }

    // Print response
    printf("HTTP response:\n%s", buffer);

    // Close socket
    close(socket_fd);

    return 0;
}