//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER "speedtest.net"
#define PORT 80

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_data[BUFFER_SIZE], recv_data[BUFFER_SIZE];
    double start_time, end_time;
    long int bytes_sent, bytes_received;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    start_time = clock();

    while (1) {
        memset(send_data, 'a', BUFFER_SIZE);
        n = send(sockfd, send_data, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("No data sent\n");
            exit(1);
        }
        bytes_sent += n;

        memset(recv_data, 0, BUFFER_SIZE);
        n = recv(sockfd, recv_data, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("No data received\n");
            exit(1);
        }
        bytes_received += n;
    }

    end_time = clock();

    close(sockfd);

    printf("Total bytes sent: %ld\n", bytes_sent);
    printf("Total bytes received: %ld\n", bytes_received);

    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Duration: %lf seconds\n", duration);

    double speed = (double)bytes_sent / duration;
    printf("Internet speed: %lf bytes/second\n", speed);

    return 0;
}