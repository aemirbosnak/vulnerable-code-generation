//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#define MAX_HTTP_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, bytes, sent, received, total;
    char request[MAX_HTTP_SIZE], response[MAX_HTTP_SIZE];

    // Parse the URL
    char url[MAX_HTTP_SIZE];
    strcpy(url, argv[1]);
    char *host = strtok(url, "/");
    char *path = strtok(NULL, "");
    if (path == NULL) {
        path = "";
    }

    // Resolve the host
    server = gethostbyname(host);
    if (server == NULL) {
        printf("Error: could not resolve host\n");
        exit(EXIT_FAILURE);
    }

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        exit(EXIT_FAILURE);
    }

    // Fill in the socket address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = *(unsigned long *)server->h_addr_list[0];
    serv_addr.sin_port = htons(80);

    // Connect
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: could not connect to host\n");
        exit(EXIT_FAILURE);
    }

    // Build the HTTP request
    sprintf(request, "GET /%s HTTP/1.1\n", path);
    sprintf(request + strlen(request), "Host: %s\n", host);
    sprintf(request + strlen(request), "Connection: close\n");
    sprintf(request + strlen(request), "User-Agent: Mozilla/5.0\n");
    sprintf(request + strlen(request), "\n");

    // Send the request
    total = strlen(request);
    sent = 0;
    do {
        bytes = write(sockfd, request + sent, total - sent);
        if (bytes == -1) {
            printf("Error: could not send request\n");
            exit(EXIT_FAILURE);
        }
        sent += bytes;
    } while (sent < total);

    // Receive the response
    memset(response, 0, sizeof(response));
    total = sizeof(response) - 1;
    received = 0;
    do {
        bytes = read(sockfd, response + received, total - received);
        if (bytes == -1) {
            printf("Error: could not receive response\n");
            exit(EXIT_FAILURE);
        }
        if (bytes == 0) {
            break;
        }
        received += bytes;
    } while (received < total);

    // Print the response
    printf("%s", response);

    // Clean up
    close(sockfd);
    exit(EXIT_SUCCESS);
}