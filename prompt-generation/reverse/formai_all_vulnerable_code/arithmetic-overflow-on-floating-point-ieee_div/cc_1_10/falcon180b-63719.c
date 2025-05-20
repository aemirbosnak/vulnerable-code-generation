//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER "speedtest.net"
#define PORT 80

#define MAX_DATA_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

unsigned long long get_current_timestamp() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (unsigned long long)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char *data = malloc(MAX_DATA_SIZE);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect failed");
    }

    char request[100];
    sprintf(request, "GET /speedtest.php HTTP/1.1\r\nHost: %s\r\nConnection: Close\r\n\r\n", SERVER);

    send(sock, request, strlen(request), 0);

    int bytes_received = 0;
    int total_bytes_received = 0;
    unsigned long long start_timestamp = get_current_timestamp();

    while (1) {
        int ret = recv(sock, data + bytes_received, MAX_DATA_SIZE - bytes_received, 0);

        if (ret <= 0) {
            break;
        }

        total_bytes_received += ret;
        bytes_received += ret;

        if (bytes_received >= MAX_DATA_SIZE) {
            break;
        }
    }

    unsigned long long end_timestamp = get_current_timestamp();

    double speed = (double)total_bytes_received / (end_timestamp - start_timestamp);

    printf("Download speed: %.2f bytes/second\n", speed);

    close(sock);
    free(data);

    return 0;
}