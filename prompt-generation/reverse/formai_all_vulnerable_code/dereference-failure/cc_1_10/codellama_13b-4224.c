//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char hostname[256];
    char path[256];

    if (parse_url(url, hostname, path) != 0) {
        printf("Invalid URL\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    char buf[MAX_BUF_SIZE];
    snprintf(buf, MAX_BUF_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    memset(buf, 0, MAX_BUF_SIZE);
    int n = recv(sock, buf, MAX_BUF_SIZE, 0);
    if (n == -1) {
        perror("recv");
        return 1;
    }

    printf("%s\n", buf);

    close(sock);

    return 0;
}

int parse_url(char *url, char *hostname, char *path) {
    char *p = strstr(url, "://");
    if (p == NULL) {
        return -1;
    }

    p += 3;

    char *q = strchr(p, '/');
    if (q == NULL) {
        q = p + strlen(p);
    }

    strncpy(hostname, p, q - p);
    strncpy(path, q, strlen(q));

    return 0;
}