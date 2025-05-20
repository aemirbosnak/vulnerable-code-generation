//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "speedtest.net"
#define SERVER_PORT 80

int main() {
    int sockfd, n;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    double start_time, end_time;
    double elapsed_time;
    long int bytes_sent, bytes_received;
    double speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = clock();
    while (1) {
        n = send(sockfd, send_buffer, BUFFER_SIZE, 0);
        if (n < 0) {
            printf("Error sending data\n");
            exit(1);
        }
        bytes_sent += n;
    }

    end_time = clock();
    elapsed_time = (end_time - start_time) / (double)CLOCKS_PER_SEC;
    speed = (double)bytes_sent / elapsed_time;

    printf("Bytes sent: %ld\n", bytes_sent);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Speed: %.2f bytes/second\n", speed);

    close(sockfd);
    return 0;
}