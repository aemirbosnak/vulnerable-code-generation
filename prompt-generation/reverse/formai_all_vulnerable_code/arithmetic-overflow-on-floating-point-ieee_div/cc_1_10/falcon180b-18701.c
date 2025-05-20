//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "speedtest.net"
#define SERVER_PORT 80

void error(const char *message) {
    perror(message);
    exit(1);
}

int main() {
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    double start_time, end_time;
    int bytes_received = 0;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        error("socket failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect failed");
    }

    start_time = clock();
    while (bytes_received < BUFFER_SIZE) {
        int bytes_read = recv(socket_fd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (bytes_read <= 0) {
            break;
        }
        bytes_received += bytes_read;
    }
    end_time = clock();

    close(socket_fd);

    double time_taken = (end_time - start_time) / CLOCKS_PER_SEC;
    double speed = (double)bytes_received / time_taken;

    printf("Internet speed: %.2lf kbps\n", speed / 1024);

    return 0;
}