//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("You forgot to provide a server address!\n");
        exit(EXIT_FAILURE);
    }
    char *server_address = argv[1];
    int port = 80;
    struct addrinfo hints, *res;
    int sockfd;
    char http_request[1024], response[1024];
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(server_address, NULL, &hints, &res) != 0) {
        printf("Invalid address!\n");
        exit(EXIT_FAILURE);
    }
    for (res = res; res != NULL; res = res->ai_next) {
        if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
            continue;
        }
        if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }
        break;
    }
    if (res == NULL) {
        printf("Connection failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("Connected to %s:%d\n", server_address, port);
    sprintf(http_request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", server_address);
    send(sockfd, http_request, strlen(http_request), 0);
    printf("Request sent!\n");
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response, sizeof response - 1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }
    printf("Response received!\n");
    close(sockfd);
    return EXIT_SUCCESS;
}