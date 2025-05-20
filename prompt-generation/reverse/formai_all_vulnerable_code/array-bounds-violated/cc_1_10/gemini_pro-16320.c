//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: post-apocalyptic
// Wasteland HTTP Client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define BUFSIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    char request[BUFSIZE];
    char response[BUFSIZE];

    // Scavenge a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Unearth the server's coordinates
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(PORT);

    // Crawl towards the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Craft a humble request
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);

    // Send our signal into the wasteland
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Listen for a response from the scavenging server
    int bytes_received;
    while ((bytes_received = recv(sockfd, response, BUFSIZE - 1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    if (bytes_received < 0) {
        perror("recv");
        exit(1);
    }

    // Abandon the socket
    close(sockfd);
    
    return 0;
}