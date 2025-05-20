//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, ret, count = 0;
    struct sockaddr_in server_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];
    int opt = TRUE;
    int val = 1;

    if (argc!= 4) {
        printf("Usage: %s <IP address> <port> <number of pings>\n", argv[0]);
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    while (count < atoi(argv[3])) {
        memset(send_buf, 0, BUF_SIZE);
        sprintf(send_buf, "PING %s:%d", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
        ret = sendto(sock, send_buf, strlen(send_buf), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (ret == -1) {
            printf("Error sending packet\n");
            exit(1);
        }

        memset(recv_buf, 0, BUF_SIZE);
        ret = recvfrom(sock, recv_buf, BUF_SIZE, 0, (struct sockaddr *)&server_addr, &val);
        if (ret == -1) {
            printf("Error receiving packet\n");
            exit(1);
        }

        printf("Ping %d: %s\n", count+1, recv_buf);
        count++;
        usleep(100000); // wait for 100ms before sending next packet
    }

    close(sock);
    return 0;
}