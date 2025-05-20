//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

int main(int argc, char *argv[]) {
    int sock = 0;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    double start_time = 0, end_time = 0;
    double total_time = 0;
    int total_bytes = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    start_time = time(NULL);
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes += bytes_received;
    }
    end_time = time(NULL);
    total_time = difftime(end_time, start_time);

    printf("Total bytes received: %d\n", total_bytes);
    printf("Time taken: %.2f seconds\n", total_time);
    printf("Internet speed: %.2f kB/s\n", (total_bytes / total_time) / 1024);

    close(sock);
    return 0;
}