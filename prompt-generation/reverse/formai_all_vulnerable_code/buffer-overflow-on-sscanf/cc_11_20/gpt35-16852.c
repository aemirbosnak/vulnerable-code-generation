//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];

    // First we need to parse the URL to get the protocol, hostname and path
    char protocol[BUFFER_SIZE], hostname[BUFFER_SIZE], path[BUFFER_SIZE];
    int port = 80;
    if (sscanf(url, "%[^:]://%[^/]/%s", protocol, hostname, path) == 3) {
        // URL has protocol, hostname and path
        if (strcmp(protocol, "http") == 0) {
            port = 80;
        } else {
            fprintf(stderr, "Unsupported protocol: %s\n", protocol);
            return 2;
        }
    } else if (sscanf(url, "%[^/]/%s", hostname, path) == 2) {
        // URL has only hostname and path, assume http protocol
        port = 80;
    } else {
        fprintf(stderr, "Invalid URL: %s\n", url);
        return 3;
    }

    // Next we need to resolve the hostname to an IP address
    struct hostent *he;
    if ((he = gethostbyname(hostname)) == NULL) {
        herror("gethostbyname");
        return 4;
    }
    char *ip = inet_ntoa(*(struct in_addr *)he->h_addr);

    // Let's create a socket and connect to the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 5;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 6;
    }

    // Now we can prepare and send the HTTP request
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("send");
        return 7;
    }

    // Finally we can receive and print the response
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
    if (bytes_received < 0) {
        perror("recv");
        return 8;
    }

    // Close the socket and exit
    close(sock);
    return 0;
}