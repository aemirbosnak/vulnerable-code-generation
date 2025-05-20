//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT "80"

void *get_in_addr(struct sockaddr *sa) {
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    } else {
        return &(((struct sockaddr_in6*)sa)->sin6_addr);
    }
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[1024];
    struct addrinfo hints, *servinfo, *p;
    int status;
    char host[128];
    char path[128];
    char request[512];

    if (argc != 2) {
        fprintf(stderr,"usage: httpclient url\n");
        return 1;
    }

    /* Parse URL */

    status = sscanf(argv[1], "http://%[^/]/%s", host, path);

    if (status < 1) {
        fprintf(stderr, "error: invalid url");
        return 1;
    }

    if (status < 2) {
        strcpy(path, "");
    }

    /* Get addrinfo */

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(host, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 2;
    }

    /* Connect to server */

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("httpclient: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("httpclient: connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "httpclient: failed to connect\n");
        return 2;
    }

    /* Send request */

    sprintf(request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);

    printf("Request:\n%s", request);

    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("httpclient: send");
        return 3;
    }

    /* Receive response */

    while ((n = recv(sockfd, buffer, sizeof buffer - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    if (n == -1) {
        perror("httpclient: recv");
        return 3;
    }

    /* Cleanup */

    freeaddrinfo(servinfo);
    close(sockfd);

    return 0;
}