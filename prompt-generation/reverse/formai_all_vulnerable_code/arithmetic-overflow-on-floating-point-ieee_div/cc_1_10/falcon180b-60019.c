//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define BUF_SIZE 1024
#define SERVER "speedtest.net"
#define PORT 80

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];
    int total_sent = 0, total_recv = 0;
    double start_time, end_time, elapsed_time;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error("socket failed");

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("connect failed");

    start_time = time(0);
    while (1) {
        memset(send_buf, 'A', BUF_SIZE);
        int sent = send(sock, send_buf, BUF_SIZE, 0);
        if (sent <= 0)
            break;
        total_sent += sent;
    }

    close(sock);

    end_time = time(0);
    elapsed_time = difftime(end_time, start_time);

    printf("Total bytes sent: %d\n", total_sent);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Bandwidth: %.2f bps\n", (double)total_sent / elapsed_time);

    return 0;
}