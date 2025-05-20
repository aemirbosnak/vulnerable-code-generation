//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_HOSTNAME 255

typedef struct {
    char hostname[MAX_HOSTNAME];
    int port;
} host_t;

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    host_t host;
    strncpy(host.hostname, argv[1], MAX_HOSTNAME);
    host.port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(host.port);

    if (inet_pton(AF_INET, host.hostname, &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid hostname\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Host is down\n");
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out\n");
        } else {
            perror("connect");
        }
        close(sock);
        return 1;
    }

    char buffer[1024];
    int bytes_received = 0;

    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    while (bytes_received < 1024) {
        int bytes_read = recv(sock, buffer + bytes_received, 1024 - bytes_received, 0);
        if (bytes_read <= 0) {
            if (bytes_read == 0) {
                printf("Host is down\n");
            } else {
                perror("recv");
            }
            close(sock);
            return 1;
        }
        bytes_received += bytes_read;
    }

    close(sock);
    printf("Host is up\n");
    return 0;
}