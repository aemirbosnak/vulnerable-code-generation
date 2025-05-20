//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 4096

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* url = argv[1];

    // Parse host and path from url
    char* host;
    char* path;
    if(strncmp(url, "http://", 7) == 0) {
        char* temp = strdup(url+7);
        host = strtok(temp, "/");
        path = strtok(NULL, "") ?: "/";
    }
    else {
        fprintf(stderr, "Invalid URL\n");
        exit(EXIT_FAILURE);
    }

    // Get information about the host
    struct hostent *server = gethostbyname(host);
    if(server == NULL) {
        fprintf(stderr, "Unable to resolve host %s\n", host);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(80);
    if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Construct the request message
    char request[MAX_REQUEST_SIZE];
    snprintf(request, MAX_REQUEST_SIZE,
        "GET %s HTTP/1.0\r\n"
        "Host: %s\r\n"
        "User-Agent: Mozilla/5.0\r\n"
        "Accept: */*\r\n\r\n",
        path, host
    );

    // Send the request
    if(write(sockfd, request, strlen(request)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive response and print
    char buffer[1024];
    while(1) {
        ssize_t n = read(sockfd, buffer, sizeof(buffer)-1);
        if(n == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        if(n == 0) {
            break;
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}