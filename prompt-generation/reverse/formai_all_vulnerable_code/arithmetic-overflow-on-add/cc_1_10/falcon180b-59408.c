//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
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
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    time_t start_time, end_time;
    double elapsed_time;
    double speed;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        printf("Socket creation failed\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed\n");
        exit(1);
    }

    time(&start_time);
    bytes_received = 0;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received += recv(socket_fd, buffer, BUFFER_SIZE, 0);

        if (bytes_received == -1) {
            printf("Data reception failed\n");
            exit(1);
        }

        if (strstr(buffer, "</html>")!= NULL) {
            break;
        }
    }

    time(&end_time);
    elapsed_time = difftime(end_time, start_time);

    speed = (double)bytes_received / elapsed_time;

    printf("Speed: %.2lf Bytes/sec\n", speed);

    close(socket_fd);

    return 0;
}