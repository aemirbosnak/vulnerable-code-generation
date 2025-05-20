//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sock, bytes_sent, bytes_recv;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];
    struct sockaddr_in server_addr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_address> <port>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    while (1) {
        printf("Enter message: ");
        fgets(send_buf, BUF_SIZE, stdin);

        bytes_sent = send(sock, send_buf, strlen(send_buf), 0);
        if (bytes_sent < 0) {
            perror("send");
            break;
        }

        bytes_recv = recv(sock, recv_buf, BUF_SIZE, 0);
        if (bytes_recv < 0) {
            perror("recv");
            break;
        }

        printf("Received: %s\n", recv_buf);
    }

    close(sock);

    return 0;
}