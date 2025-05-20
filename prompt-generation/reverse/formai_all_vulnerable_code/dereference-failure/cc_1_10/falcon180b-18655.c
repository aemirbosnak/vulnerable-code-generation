//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int bytes_sent, bytes_recv, total_bytes_recv = 0;
    double start_time, end_time, elapsed_time;
    int timeout_count = 0;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket.\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error: Could not connect to server.\n");
        return 1;
    }

    memset(send_buffer, 'A', BUFFER_SIZE);
    bytes_sent = send(sockfd, send_buffer, BUFFER_SIZE, 0);
    if (bytes_sent == -1) {
        printf("Error: Could not send data.\n");
        return 1;
    }

    start_time = clock();
    while (TRUE) {
        bytes_recv = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        if (bytes_recv <= 0) {
            if (errno == ETIMEDOUT) {
                timeout_count++;
            } else {
                break;
            }
        } else {
            total_bytes_recv += bytes_recv;
        }
    }
    end_time = clock();

    elapsed_time = (end_time - start_time) / (double)CLOCKS_PER_SEC;
    printf("Total bytes received: %d\n", total_bytes_recv);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Timeout count: %d\n", timeout_count);

    close(sockfd);
    return 0;
}