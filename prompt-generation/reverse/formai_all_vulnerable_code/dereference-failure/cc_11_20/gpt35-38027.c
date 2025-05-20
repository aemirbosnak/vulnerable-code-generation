//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_REQUEST_SIZE 2048

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];

    // Parsing the URL to extract protocol, hostname and path
    char *protocol = strtok(url, ":");
    char *hostname = strtok(NULL, "/");
    char *path = strtok(NULL, "");

    if (protocol == NULL || hostname == NULL || path == NULL) {
        printf("Invalid URL: %s\n", url);
        return 1;
    }

    // Resolving hostname to IP address
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        printf("Failed to resolve hostname: %s\n", hostname);
        return 1;
    }

    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;
    char *ip_address = inet_ntoa(*addr_list[0]);

    printf("Protocol: %s\n", protocol);
    printf("Hostname: %s\n", hostname);
    printf("IP Address: %s\n", ip_address);
    printf("Path: %s\n", path);

    // Creating HTTP request
    char request[MAX_REQUEST_SIZE];
    sprintf(request, "GET /%s HTTP/1.1\r\n", path);
    strcat(request, "Host: ");
    strcat(request, hostname);
    strcat(request, "\r\n");
    strcat(request, "Connection: close\r\n");
    strcat(request, "\r\n");

    // Creating socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    // Connecting to server
    struct sockaddr_in server_addr;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    if (connect(socket_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to server\n");
        return 1;
    }

    // Sending HTTP request to server
    if (send(socket_fd, request, strlen(request), 0) < 0) {
        printf("Failed to send HTTP request\n");
        return 1;
    }

    // Receiving HTTP response from server
    char response[MAX_REQUEST_SIZE];
    int recv_size = 0;
    while ((recv_size = recv(socket_fd, response, MAX_REQUEST_SIZE, 0)) > 0) {
        printf("%.*s", recv_size, response);
    }

    if (recv_size == -1) {
        printf("Failed to receive HTTP response\n");
        return 1;
    }

    close(socket_fd);

    return 0;
}