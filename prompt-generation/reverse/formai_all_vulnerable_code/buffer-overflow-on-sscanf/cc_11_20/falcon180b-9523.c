//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define MAX_HOST 256
#define MAX_PORT 6

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char host[MAX_HOST];
    char port[MAX_PORT];
    char *url;
    char *method;
    char *version;
    char *request;
    char response[MAX_LINE];
    int n;

    // Check for correct number of arguments
    if (argc!= 4) {
        printf("Usage: %s <method> <url> <version>\n", argv[0]);
        return 1;
    }

    // Set method, URL, and version
    method = argv[1];
    url = argv[2];
    version = argv[3];

    // Parse URL
    if (sscanf(url, "http://%[^:/]:%s", host, port)!= 3) {
        printf("Invalid URL\n");
        return 1;
    }

    // Convert port to integer
    if (sscanf(port, "%d", &n)!= 1 || n <= 0 || n > 65535) {
        printf("Invalid port\n");
        return 1;
    }

    // Build request
    sprintf(request, "%s %s HTTP/%s\r\nHost: %s:%d\r\nConnection: close\r\n\r\n",
            method, url, version, host, n);

    // Connect to server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(n);
    inet_pton(AF_INET, host, &server.sin_addr);

    // Send request
    if (send(sock, request, strlen(request), 0) == -1) {
        printf("Error sending request\n");
        close(sock);
        return 1;
    }

    // Receive response
    n = 0;
    while ((n < MAX_LINE - 1) && (recv(sock, response + n, 1, 0)!= -1)) {
        if (response[n] == '\r') {
            response[n] = '\0';
            break;
        }
        n++;
    }
    close(sock);

    // Print response
    printf("Response:\n%s\n", response);

    return 0;
}