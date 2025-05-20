//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 80
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char hostname[MAX_LINE];
    char filename[MAX_LINE];

    if (sscanf(url, "http://%[^/]/%s", hostname, filename) != 2) {
        printf("Invalid URL\n");
        return 1;
    }

    printf("Connecting to %s...\n", hostname);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        printf("Invalid hostname\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    char request[MAX_LINE];
    snprintf(request, MAX_LINE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", filename, hostname);

    if (send(sock, request, strlen(request), 0) < 0) {
        printf("Error sending request\n");
        return 1;
    }

    char response[MAX_LINE];
    int bytes_received = recv(sock, response, MAX_LINE, 0);
    if (bytes_received < 0) {
        printf("Error receiving response\n");
        return 1;
    }

    printf("Response:\n%s", response);

    close(sock);

    return 0;
}