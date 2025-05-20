//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <SSID>\n", argv[0]);
        return 1;
    }

    char essid[32] = {0};
    strncpy(essid, argv[1], 32);

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(9);
    inet_pton(AF_INET, "224.0.0.251", &server.sin_addr);

    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);

    struct iovec iov[2];
    iov[0].iov_base = buf;
    iov[0].iov_len = strlen(essid);
    iov[1].iov_base = "\0";
    iov[1].iov_len = 1;

    struct msghdr msg;
    msg.msg_iov = iov;
    msg.msg_iovlen = 2;
    msg.msg_name = &server;
    msg.msg_namelen = sizeof(server);
    msg.msg_control = NULL;
    msg.msg_controllen = 0;
    msg.msg_flags = 0;

    int len = sendmsg(sock, &msg, 0);
    if (len == -1) {
        printf("Error sending message\n");
        close(sock);
        return 1;
    }

    char recv_buf[BUF_SIZE];
    memset(recv_buf, 0, BUF_SIZE);

    struct sockaddr_in from;
    socklen_t from_len = sizeof(from);
    int bytes_received = recvfrom(sock, recv_buf, BUF_SIZE, 0, &from, &from_len);
    if (bytes_received == -1) {
        printf("Error receiving message\n");
        close(sock);
        return 1;
    }

    close(sock);

    printf("Wi-Fi signal strength for SSID '%s': %d\n", essid, atoi(recv_buf));

    return 0;
}