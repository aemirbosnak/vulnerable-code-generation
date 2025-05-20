//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_IP "speedtest.net"
#define SERVER_PORT 80

#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    int total_bytes_received = 0;
    time_t start_time, end_time;

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
        return 1;
    }

    time(&start_time);

    do {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            total_bytes_received += bytes_received;
        }
    } while (bytes_received > 0);

    time(&end_time);

    double elapsed_time = difftime(end_time, start_time);
    double speed = total_bytes_received / (elapsed_time * 1024);

    printf("Internet speed: %.2f kbps\n", speed);

    close(sock);

    return 0;
}