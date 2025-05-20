//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "speedtest.net"
#define SERVER_PORT 80

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    double start_time, end_time;
    double elapsed_time;
    int total_bytes_sent = 0;
    int total_bytes_recv = 0;
    double speed = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(NULL);
    while (total_bytes_sent < BUFFER_SIZE) {
        int bytes_sent = send(sock, send_buffer, BUFFER_SIZE - total_bytes_sent, 0);
        if (bytes_sent == -1) {
            printf("Error sending data\n");
            exit(1);
        }
        total_bytes_sent += bytes_sent;
    }

    while (total_bytes_recv < BUFFER_SIZE) {
        int bytes_recv = recv(sock, recv_buffer, BUFFER_SIZE - total_bytes_recv, 0);
        if (bytes_recv == -1) {
            printf("Error receiving data\n");
            exit(1);
        }
        total_bytes_recv += bytes_recv;
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    speed = (double)total_bytes_recv / elapsed_time;

    printf("Internet speed: %.2lf bytes/second\n", speed);

    close(sock);
    return 0;
}