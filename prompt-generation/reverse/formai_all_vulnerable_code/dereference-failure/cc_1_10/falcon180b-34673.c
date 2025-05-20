//Falcon-180B DATASET v1.0 Category: Networking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024
#define PORT 8080
#define BACKLOG 5

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];
    int yes = 1;
    int rv;
    char *filename = "index.html";
    FILE *fp;
    char line[MAX_LINE];
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        error("Error opening file");
    }

    printf("Server listening on port %d\n", PORT);

    if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo))!= 0) {
        error("Error resolving hostname");
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        error("Error creating socket");
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        error("Error setting socket option");
    }

    if (bind(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        error("Error binding socket");
    }

    if (listen(sockfd, BACKLOG) == -1) {
        error("Error listening on socket");
    }

    while (1) {
        socklen_t addrlen;
        if ((newsockfd = accept(sockfd, NULL, &addrlen)) == -1) {
            error("Error accepting connection");
        }

        printf("Connection accepted\n");

        while ((read = fread(line, 1, MAX_LINE, fp))!= 0) {
            send(newsockfd, line, read, 0);
        }

        fclose(fp);
        close(newsockfd);
    }

    return 0;
}