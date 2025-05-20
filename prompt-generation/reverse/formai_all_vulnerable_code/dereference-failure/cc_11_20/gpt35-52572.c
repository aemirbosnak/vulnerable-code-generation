//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/select.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *host = strtok(url, "/");
    char *path = strtok(NULL, "");
    if (path == NULL) {
        path = "/";
    }

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    if (write(sockfd, request, strlen(request)) < 0) {
        perror("ERROR writing to socket");
        return 1;
    }

    char response[BUFFER_SIZE];
    int current_size = 0;
    fd_set set;
    FD_ZERO(&set);
    FD_SET(sockfd, &set);

    while (1) {
        if (select(sockfd + 1, &set, NULL, NULL, NULL) < 0) {
            perror("ERROR in select");
            return 1;
        }
        if (FD_ISSET(sockfd, &set)) {
            n = read(sockfd, response + current_size, BUFFER_SIZE - current_size);
            if (n < 0) {
                perror("ERROR reading from socket");
                return 1;
            }
            if (n == 0) {
                break;
            }
            current_size += n;
            if (current_size >= BUFFER_SIZE) {
                perror("ERROR response too large");
                return 1;
            }
            if (current_size >= 4 && memcmp(response + current_size - 4, "\r\n\r\n", 4) == 0) {
                break;
            }
        }
    }

    char *body_start = strstr(response, "\r\n\r\n");
    if (body_start == NULL) {
        perror("ERROR parsing response");
        return 1;
    }
    body_start += 4;

    printf("%s", body_start);

    close(sockfd);

    return 0;
}