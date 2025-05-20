//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define TIME_INTERVAL 1

void error_handling(const char* message);

int main() {
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    double start_time, end_time;
    int bytes_received;
    double speed;

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_handling("socket failed");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr))!= 0) {
        error_handling("connect failed");
        exit(1);
    }

    start_time = clock();
    bytes_received = 0;

    while (1) {
        if ((bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0)) <= 0) {
            error_handling("recv failed");
            exit(1);
        }
        bytes_received += bytes_received;
    }

    end_time = clock();
    speed = (double)bytes_received / (end_time - start_time) / 1024;

    printf("Internet speed: %.2lf KB/s\n", speed);

    close(socket_fd);

    return 0;
}

void error_handling(const char* message) {
    perror(message);
    exit(1);
}