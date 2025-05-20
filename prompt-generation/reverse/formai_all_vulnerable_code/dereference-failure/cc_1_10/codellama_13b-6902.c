//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PACKET_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(host, "80", &hints, &res) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    if (connect(sock, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        return 1;
    }

    char packet[MAX_PACKET_SIZE];
    int packet_size = snprintf(packet, MAX_PACKET_SIZE, "GET / HTTP/1.0\r\n\r\n");
    send(sock, packet, packet_size, 0);

    int n;
    char recv_buf[MAX_PACKET_SIZE];
    while ((n = recv(sock, recv_buf, MAX_PACKET_SIZE, 0)) > 0) {
        printf("%.*s", n, recv_buf);
    }

    freeaddrinfo(res);
    close(sock);
    return 0;
}