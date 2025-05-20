//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void send_packet(int sock, const char* host, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &addr.sin_addr);

    char buf[1024];
    sprintf(buf, "PING %s\r\n", host);

    sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&addr, sizeof(addr));
}

void recv_packet(int sock, char* buf, int buf_size) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    socklen_t addr_size = sizeof(addr);

    int bytes_received = recvfrom(sock, buf, buf_size, 0, (struct sockaddr*)&addr, &addr_size);
    if (bytes_received <= 0) {
        printf("recvfrom error: %s\n", strerror(errno));
        return;
    }

    buf[bytes_received] = '\0';
    printf("Received: %s\n", buf);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s host port timeout\n", argv[0]);
        return 1;
    }

    char* host = argv[1];
    int port = atoi(argv[2]);
    int timeout = atoi(argv[3]);

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("socket error: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &addr.sin_addr);

    send_packet(sock, host, port);

    char buf[1024];
    int bytes_received;
    do {
        bytes_received = recvfrom(sock, buf, sizeof(buf), 0, NULL, NULL);
        if (bytes_received > 0) {
            buf[bytes_received] = '\0';
            printf("Received: %s\n", buf);
        }
    } while (bytes_received > 0 && timeout-- > 0);

    close(sock);
    return 0;
}