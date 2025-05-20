//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    int sockfd, bytes_received;
    struct sockaddr_in serveraddr;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    char *url, *path, *host;
    int port = 80;

    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    url = argv[1];

    // Parse url to get host, path and port if specified
    if (strstr(url, "http://") == url) {
        url += strlen("http://");
    }
    host = strsep(&url, "/");
    if ((path = strchr(url, '/')) != NULL) {
        *path++ = '\0';
    }
    if ((strchr(host, ':')) != NULL) {
        sscanf(host, "%[^:]:%d", host, &port);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Initialize server address structure
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = inet_addr(host);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    sprintf(request, "GET /%s HTTP/1.1\r\n", path);
    sprintf(request+strlen(request), "Host: %s:%d\r\n", host, port);
    sprintf(request+strlen(request), "Connection: close\r\n");
    sprintf(request+strlen(request), "\r\n");

    // Send request to server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending request");
        exit(1);
    }

    // Receive response from server
    while ((bytes_received = recv(sockfd, response, BUFFER_SIZE-1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    close(sockfd);

    return 0;
}