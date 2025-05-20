//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_PING_LEN 512

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;

    if (getaddrinfo(argv[1], NULL, &hints, &res) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock < 0) {
        perror("socket");
        freeaddrinfo(res);
        return 1;
    }

    struct sockaddr_storage server_addr;
    socklen_t server_addr_len = sizeof(server_addr);
    memcpy(&server_addr, res->ai_addr, res->ai_addrlen);

    char packet[MAX_PING_LEN];
    int packet_len = 64;
    memset(packet, 0, packet_len);

    int i = 0;
    for (i = 0; i < packet_len; i++) {
        packet[i] = i % 256;
    }

    int send_len = sendto(sock, packet, packet_len, 0, (struct sockaddr *)&server_addr, server_addr_len);
    if (send_len < 0) {
        perror("sendto");
        close(sock);
        freeaddrinfo(res);
        return 1;
    }

    char recv_packet[MAX_PING_LEN];
    int recv_len = recvfrom(sock, recv_packet, packet_len, 0, (struct sockaddr *)&server_addr, &server_addr_len);
    if (recv_len < 0) {
        perror("recvfrom");
        close(sock);
        freeaddrinfo(res);
        return 1;
    }

    printf("Received %d bytes from %s\n", recv_len, argv[1]);

    close(sock);
    freeaddrinfo(res);
    return 0;
}