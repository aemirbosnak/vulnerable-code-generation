//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define DEFAULT_PORT "7"
#define DEFAULT_TIMEOUT 5

typedef struct {
    char hostname[MAX_HOSTNAME];
    int port;
    int timeout;
} host_t;

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char recv_buf[MAX_DATA];
    host_t host;
    int ret;
    int i;

    if (argc < 3) {
        printf("Usage: %s <hostname> <port> [timeout]\n", argv[0]);
        return 1;
    }

    strncpy(host.hostname, argv[1], MAX_HOSTNAME);
    host.port = atoi(argv[2]);
    if (argc > 3) {
        host.timeout = atoi(argv[3]);
    } else {
        host.timeout = DEFAULT_TIMEOUT;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(host.port);
    inet_pton(AF_INET, host.hostname, &server.sin_addr);

    ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (ret == -1) {
        printf("Error connecting to %s:%d: %s\n", host.hostname, host.port, strerror(errno));
        close(sock);
        return 1;
    }

    printf("Connected to %s:%d\n", host.hostname, host.port);

    for (i = 0; i < 5; i++) {
        ret = send(sock, "PING", strlen("PING"), 0);
        if (ret == -1) {
            printf("Error sending PING: %s\n", strerror(errno));
            close(sock);
            return 1;
        }

        memset(recv_buf, 0, MAX_DATA);
        ret = recv(sock, recv_buf, MAX_DATA, 0);
        if (ret == -1) {
            printf("Error receiving data: %s\n", strerror(errno));
            close(sock);
            return 1;
        }

        if (ret > 0 && strncmp(recv_buf, "PONG", 4) == 0) {
            printf("PONG received\n");
            break;
        }
    }

    if (i == 5) {
        printf("No response received\n");
    }

    close(sock);
    return 0;
}