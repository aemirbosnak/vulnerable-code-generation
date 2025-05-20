//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOST_LEN 256
#define MAX_DATA_LEN 1024
#define TRUE 1
#define FALSE 0
#define ERR_EXIT(m) { perror(m); exit(EXIT_FAILURE); }

typedef struct {
    char *host;
    int port;
} host_t;

int send_ping(int sockfd, const char *data, int len) {
    return send(sockfd, data, len, 0);
}

int recv_pong(int sockfd, char *data, int len) {
    return recv(sockfd, data, len, 0);
}

int resolve_host(const char *host, struct sockaddr_in *addr) {
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        return -1;
    }
    memcpy(&addr->sin_addr, he->h_addr, he->h_length);
    addr->sin_family = AF_INET;
    addr->sin_port = htons(0);
    return 0;
}

int create_socket(int type) {
    int sockfd = socket(AF_INET, type, 0);
    if (sockfd == -1) {
        ERR_EXIT("socket");
    }
    return sockfd;
}

void close_socket(int sockfd) {
    if (close(sockfd) == -1) {
        ERR_EXIT("close");
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s host [port]\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = (argc > 2)? atoi(argv[2]) : 7;

    host_t dest = {
       .host = host,
       .port = port,
    };

    int sockfd = create_socket(SOCK_DGRAM);

    struct sockaddr_in dest_addr;
    if (resolve_host(host, &dest_addr) == -1) {
        close_socket(sockfd);
        return 1;
    }

    char data[MAX_DATA_LEN];
    sprintf(data, "PING %s:%d", host, port);

    if (send_ping(sockfd, data, strlen(data)) == -1) {
        close_socket(sockfd);
        return 1;
    }

    int len = recv_pong(sockfd, data, MAX_DATA_LEN);
    if (len <= 0) {
        close_socket(sockfd);
        return 1;
    }

    if (data[0] == 'P' && data[1] == 'O' && data[2] == 'N' && data[3] == 'G') {
        printf("%s is alive!\n", host);
    } else {
        printf("%s is not responding.\n", host);
    }

    close_socket(sockfd);
    return 0;
}