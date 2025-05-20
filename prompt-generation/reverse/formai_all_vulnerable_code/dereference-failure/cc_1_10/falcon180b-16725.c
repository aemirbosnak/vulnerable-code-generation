//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define BUF_SIZE 1024
#define TIMEOUT 5

void handle_signal(int signum) {
    if (signum == SIGALRM) {
        printf("Timeout\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in server_addr;
    char send_buf[BUF_SIZE] = "PING";
    char recv_buf[BUF_SIZE];
    int recv_len;
    struct timeval timeout;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret!= 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        send(sock, send_buf, strlen(send_buf), 0);
        memset(recv_buf, 0, BUF_SIZE);
        ret = recv(sock, recv_buf, BUF_SIZE, 0);
        if (ret <= 0) {
            if (ret == 0) {
                printf("Connection closed by server\n");
            } else if (errno == EINTR) {
                continue;
            } else {
                perror("recv");
                exit(1);
            }
        }
        recv_buf[ret] = '\0';
        printf("Received: %s\n", recv_buf);
        if (strcmp(recv_buf, "PONG") == 0) {
            printf("Ping successful\n");
            close(sock);
            exit(0);
        }
    }

    return 0;
}