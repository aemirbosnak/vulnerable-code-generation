//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

int main() {
    int socket_fd, bytes_received, total_bytes_received = 0;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    double start_time, end_time, elapsed_time;
    double speed;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        printf("Socket creation failed\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed\n");
        exit(1);
    }

    start_time = difftime(time(NULL), time(NULL));

    while (1) {
        bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        total_bytes_received += bytes_received;
    }

    end_time = difftime(time(NULL), time(NULL));
    elapsed_time = end_time - start_time;
    speed = (double)total_bytes_received / elapsed_time;

    printf("Internet speed: %.2lf bytes/second\n", speed);

    close(socket_fd);

    return 0;
}