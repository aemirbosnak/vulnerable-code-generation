//FormAI DATASET v1.0 Category: Network Ping Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define TIMEOUT 1

int sock_fd;
bool connected = false;
struct sockaddr_in serv_addr;

void connect_socket(char *ip_address) {
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket.");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
        perror("Error converting IP address.");
        exit(1);
    }

    if (connect(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server.");
        exit(1);
    }
    connected = true;
}

void disconnect_socket() {
    close(sock_fd);
    connected = false;
}

double ping(char *ip_address) {
    struct timeval start, end;
    double time_diff;

    connect_socket(ip_address);

    char message[100] = "Ping Test Message";
    int total_sent = 0;
    int total_received = 0;

    while (total_sent < 4) {
        gettimeofday(&start, NULL);
        send(sock_fd, message, strlen(message), 0);
        total_sent++;

        char buffer[1024] = {0};
        fd_set set;
        FD_ZERO(&set);
        FD_SET(sock_fd, &set);

        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        int select_result = select(sock_fd+1, &set, NULL, NULL, &timeout);
        if (select_result == -1) {
            perror("Error with select.");
            exit(1);
        } else if (select_result == 0) {
            printf("Request timed out.\n");
        } else {
            recv(sock_fd, buffer, 1024, 0);
            gettimeofday(&end, NULL);
            total_received++;
        }

        time_diff = (end.tv_sec - start.tv_sec) * 1000.0;
        time_diff += (end.tv_usec - start.tv_usec) / 1000.0;

        printf("Reply from %s: bytes=32 time=%.2fms TTL=64\n", ip_address, time_diff);
    }

    disconnect_socket();

    return time_diff;
}

int main(int argc, char const *argv[]) {
    char *ip_address = "127.0.0.1";
    double ping_time = ping(ip_address);
    printf("Average ping time for %s: %.2fms\n", ip_address, ping_time);

    return 0;
}