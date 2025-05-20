//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_ADDR "speedtest.net"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    memset(send_buffer, 'a', BUFFER_SIZE);
    send(sock, send_buffer, BUFFER_SIZE, 0);

    memset(recv_buffer, 0, BUFFER_SIZE);
    int bytes_received;
    struct timeval start_time, end_time;

    gettimeofday(&start_time, NULL);
    while ((bytes_received = recv(sock, recv_buffer, BUFFER_SIZE, 0)) > 0) {
        gettimeofday(&end_time, NULL);
        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
        double speed = bytes_received / elapsed_time;
        printf("Speed: %.2f Mbps\n", speed);
    }

    close(sock);
    return 0;
}