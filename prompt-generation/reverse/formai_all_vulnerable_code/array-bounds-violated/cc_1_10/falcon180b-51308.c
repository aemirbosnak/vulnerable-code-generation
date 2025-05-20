//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_IP "speedtest.net"
#define SERVER_PORT 80
#define BUFFER_SIZE 4096
#define TEST_DURATION 10 // in seconds

int main() {
    int sock = 0;
    struct sockaddr_in server_addr;
    char *message = "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n";
    char response_buffer[BUFFER_SIZE];
    int bytes_received = 0;
    time_t start_time, end_time;
    double elapsed_time;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server.\n");
        close(sock);
        return 1;
    }

    time(&start_time);
    send(sock, message, strlen(message), 0);

    while (1) {
        bytes_received = recv(sock, response_buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        response_buffer[bytes_received] = '\0';
        printf("%s", response_buffer);
    }

    time(&end_time);
    elapsed_time = difftime(end_time, start_time);
    speed = (double)bytes_received / elapsed_time;

    printf("\nTest completed.\n");
    printf("Speed: %.2f bytes/second\n", speed);

    close(sock);
    return 0;
}