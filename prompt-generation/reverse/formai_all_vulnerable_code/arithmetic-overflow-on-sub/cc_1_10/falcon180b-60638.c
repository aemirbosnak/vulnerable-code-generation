//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    char buf[1024];
    int bytes_received = 0;
    clock_t start_time = clock();

    while (1) {
        int bytes_read = recv(sock, buf + bytes_received, 1024 - bytes_received, 0);
        if (bytes_read <= 0) {
            printf("Connection closed\n");
            close(sock);
            return 0;
        }

        bytes_received += bytes_read;
        if (bytes_received >= 1024) {
            double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
            double speed = 1024.0 / elapsed_time;

            printf("Internet speed: %.2f KB/s\n", speed);
            start_time = clock();
            bytes_received = 0;
        }
    }

    close(sock);
    return 0;
}