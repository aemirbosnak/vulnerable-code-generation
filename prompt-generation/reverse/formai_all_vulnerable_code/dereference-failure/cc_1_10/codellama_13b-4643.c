//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define PING_PACKET_SIZE 64

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char buffer[PING_PACKET_SIZE];
    memset(buffer, 0, PING_PACKET_SIZE);

    struct hostent *server;
    struct sockaddr_in server_addr;

    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Failed to resolve host %s\n", host);
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = 0;
    server_addr.sin_addr.s_addr = *((unsigned long *)server->h_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    if (send(sock, buffer, PING_PACKET_SIZE, 0) < 0) {
        perror("send");
        return 1;
    }

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(sock, &fds);

    if (select(sock + 1, &fds, NULL, NULL, &timeout) < 0) {
        perror("select");
        return 1;
    }

    if (FD_ISSET(sock, &fds)) {
        printf("Received response from %s\n", host);
    } else {
        printf("Timed out waiting for response from %s\n", host);
    }

    close(sock);
    return 0;
}