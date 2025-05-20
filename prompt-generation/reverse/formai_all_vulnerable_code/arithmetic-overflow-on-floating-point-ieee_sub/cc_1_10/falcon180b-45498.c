//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define SERVER_IP "speedtest.net"

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int total_bytes_received = 0;
    double start_time, end_time, elapsed_time;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    start_time = difftime(time(NULL), time(NULL));

    while (1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Connection closed by server\n");
            break;
        }
        total_bytes_received += bytes_received;
    }

    end_time = difftime(time(NULL), time(NULL));
    elapsed_time = end_time - start_time;

    double speed = (double)total_bytes_received / elapsed_time;
    printf("Internet speed: %.2f bytes/second\n", speed);

    close(sock);
    return 0;
}