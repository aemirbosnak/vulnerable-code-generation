//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define PORT "80"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];
    int rv;
    int numbytes;
    char buffer[BUFFER_SIZE];
    FILE *fp;
    char *ptr;
    int *speed;
    int timeout;

    printf("Enter the URL to test: ");
    scanf("%s", host);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(host, PORT, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    snprintf(service, sizeof(service), "%s", PORT);

    if (getsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, &numbytes) == -1) {
        perror("getsockopt");
        exit(1);
    }

    printf("Testing...\n");
    fflush(stdout);

    fp = fopen("test.html", "wb");

    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    while ((numbytes = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), numbytes, fp);
    }

    fclose(fp);

    printf("Test complete.\n");

    if (ferror(fp)) {
        perror("fwrite");
        exit(1);
    }

    printf("Calculating speed...\n");
    fflush(stdout);

    fp = fopen("test.html", "rb");

    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    ptr = (char *)malloc(ftell(fp));

    if (ptr == NULL) {
        perror("malloc");
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);
    fread(ptr, sizeof(char), ftell(fp), fp);

    fclose(fp);

    speed = (int *)malloc(sizeof(int));

    *speed = ftell(fp);

    printf("Internet speed: %d bytes/sec\n", *speed);

    free(ptr);
    free(speed);

    return 0;
}