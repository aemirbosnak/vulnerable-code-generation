//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define HTTP_PORT 80
#define USER_AGENT "Mind-Bending HTTP Client 1.0"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    struct addrinfo hints, *res;
    int sockfd, rc;
    char buf[BUFFER_SIZE] = {0};

    // check if hostname and path are provided
    if (argc != 3) {
        printf("Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // set up hints for getaddrinfo()
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // resolve hostname
    if ((rc = getaddrinfo(argv[1], "http", &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo() failed: %s\n", gai_strerror(rc));
        return EXIT_FAILURE;
    }

    // create socket
    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    // connect to server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect() failed");
        return EXIT_FAILURE;
    }

    // construct HTTP request string
    snprintf(buf, BUFFER_SIZE, "GET %s HTTP/1.1\r\n"
                                "Host: %s\r\n"
                                "User-Agent: %s\r\n"
                                "Connection: close\r\n"
                                "\r\n",
             argv[2], argv[1], USER_AGENT);

    // send HTTP request
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send() failed");
        return EXIT_FAILURE;
    }

    // read HTTP response
    while ((rc = recv(sockfd, buf, BUFFER_SIZE - 1, 0)) > 0) {
        buf[rc] = '\0';
        printf("%s", buf);
    }

    // check if recv() failed or returned 0 (indicating end of data)
    if (rc < 0) {
        perror("recv() failed");
        return EXIT_FAILURE;
    } else if (rc == 0) {
        printf("\nConnection closed by server.\n");
    }

    // free addrinfo structure
    freeaddrinfo(res);

    // close socket
    if (close(sockfd) == -1) {
        perror("close() failed");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}