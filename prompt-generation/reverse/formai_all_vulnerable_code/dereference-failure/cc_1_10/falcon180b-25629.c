//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_LEN 64
#define MAX_PORT_LEN 6

typedef struct {
    char host[MAX_HOST_LEN];
    char port[MAX_PORT_LEN];
    int sock;
} host_t;

void print_usage(char *prog) {
    fprintf(stderr, "Usage: %s <host> <port>\n", prog);
    exit(1);
}

int connect_host(char *host, char *port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }

    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        close(sock);
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    serv_addr.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        close(sock);
        return -1;
    }

    return sock;
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        print_usage(argv[0]);
    }

    char host[MAX_HOST_LEN] = {0};
    strncpy(host, argv[1], MAX_HOST_LEN - 1);

    char port[MAX_PORT_LEN] = {0};
    strncpy(port, argv[2], MAX_PORT_LEN - 1);

    int sock = connect_host(host, port);
    if (sock == -1) {
        return 1;
    }

    printf("Connected to %s:%s\n", host, port);
    close(sock);
    return 0;
}