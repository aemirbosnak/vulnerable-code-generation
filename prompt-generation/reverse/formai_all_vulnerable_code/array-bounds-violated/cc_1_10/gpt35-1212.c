//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to send HTTP request
void send_request(int sockfd, const char *hostname, const char *path) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    send(sockfd, buffer, strlen(buffer), 0);
}

// Function to receive HTTP response
void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        printf("Error receiving response\n");
    }
}

int main() {
    const char *hostname = "www.example.com";
    const char *path = "/";

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: could not resolve hostname\n");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    send_request(sockfd, hostname, path);
    receive_response(sockfd);

    close(sockfd);

    return 0;
}