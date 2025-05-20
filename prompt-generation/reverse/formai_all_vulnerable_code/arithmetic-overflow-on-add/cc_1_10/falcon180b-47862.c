//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "speedtest.server.com"
#define SERVER_PORT 80

void error_handling(char* message);

int main(int argc, char* argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket failed");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
    }

    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];

    memset(send_buffer, 'a', BUFFER_SIZE);
    send(sock, send_buffer, BUFFER_SIZE, 0);

    int bytes_received = 0;
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    while (bytes_received < BUFFER_SIZE) {
        int result = recv(sock, recv_buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (result <= 0) {
            error_handling("recv failed");
        }
        bytes_received += result;
    }

    gettimeofday(&end_time, NULL);

    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    close(sock);

    return 0;
}

void error_handling(char* message) {
    perror(message);
    exit(1);
}