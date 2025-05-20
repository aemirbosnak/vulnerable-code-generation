//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo *server_info;
    struct sockaddr *server_addr;
    char *hostname = "www.google.com";
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Get address information for the hostname
    if ((server_info = getaddrinfo(hostname, NULL, NULL, NULL)) == NULL) {
        fprintf(stderr, "Error getting address information for %s\n", hostname);
        exit(1);
    }

    // Create a socket
    sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        fprintf(stderr, "Error connecting to %s\n", hostname);
        exit(1);
    }

    // Send a ping request
    send(sockfd, "PING", strlen("PING"), 0);

    // Receive the response
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        fprintf(stderr, "Error receiving response from %s\n", hostname);
        exit(1);
    }

    // Close the socket
    close(sockfd);

    // Print the response
    printf("Response from %s:\n%s", hostname, buffer);

    return 0;
}