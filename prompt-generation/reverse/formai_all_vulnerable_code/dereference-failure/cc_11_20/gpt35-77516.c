//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 4096

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    printf("Connecting to %s...\n", url);

    // parse the url to get hostname, path, and port
    char* hostname = url;
    char* path = "/";
    char* port = "80";
    char* ptr = strstr(url, "://");

    if(ptr != NULL) hostname = ptr+3;

    ptr = strchr(hostname, '/');
    if(ptr != NULL) {
        *ptr = '\0';
        path = ptr+1;
    }

    ptr = strchr(hostname, ':');
    if(ptr != NULL) {
        *ptr = '\0';
        port = ptr+1;
    }

    // create a socket
    struct sockaddr_in address;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket");
        return 1;
    }

    // get server address
    struct hostent* server = gethostbyname(hostname);
    if(server == NULL) {
        fprintf(stderr, "Error: could not resolve hostname '%s'\n", hostname);
        return 1;
    }

    memset(&address, 0, sizeof(struct sockaddr_in));
    address.sin_family = AF_INET;
    address.sin_port = htons(atoi(port));
    memcpy(&address.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to server
    if(connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("connect");
        return 1;
    }

    // create HTTP request
    char request[MAX_BUFFER_SIZE];
    memset(request, 0, sizeof(request));
    sprintf(request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);

    // send request to server
    if(send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        return 1;
    }

    // receive response from server
    char response[MAX_BUFFER_SIZE];
    memset(response, 0, sizeof(response));
    ssize_t n = 0;
    bool headerDone = false;

    while((n = recv(sockfd, response, sizeof(response), 0)) > 0) {
        if(!headerDone) {
            // find end of header
            char* endOfHeader = strstr(response, "\r\n\r\n");
            if(endOfHeader != NULL) {
                // print header and remaining content
                printf("%.*s", (int)(endOfHeader+4-response), response);
                printf("%.*s", (int)(n-(endOfHeader+4-response)), endOfHeader+4);
                headerDone = true;
            } else {
                // print whole received content
                printf("%.*s", (int)n, response);
            }
        } else {
            // print remaining content
            printf("%.*s", (int)n, response);
        }
        memset(response, 0, sizeof(response));
    }

    if(n == -1) {
        perror("recv");
        return 1;
    }

    // close the socket
    close(sockfd);

    return 0;
}