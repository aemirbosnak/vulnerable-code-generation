//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDR "speedtest.net"
#define SERVER_PORT 80

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buf[BUFFER_SIZE], recv_buf[BUFFER_SIZE];
    long int start_time, end_time;
    double elapsed_time;
    int total_bytes_sent = 0, total_bytes_recv = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    start_time = clock();
    while (1) {
        memset(send_buf, 0, BUFFER_SIZE);
        sprintf(send_buf, "GET /speedtest HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_ADDR);
        n = send(sockfd, send_buf, strlen(send_buf), 0);
        if (n < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }
        total_bytes_sent += n;

        memset(recv_buf, 0, BUFFER_SIZE);
        n = recv(sockfd, recv_buf, BUFFER_SIZE, 0);
        if (n < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        total_bytes_recv += n;

        if (n == 0) {
            break;
        }
    }

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Total bytes sent: %d\n", total_bytes_sent);
    printf("Total bytes received: %d\n", total_bytes_recv);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    close(sockfd);
    return 0;
}