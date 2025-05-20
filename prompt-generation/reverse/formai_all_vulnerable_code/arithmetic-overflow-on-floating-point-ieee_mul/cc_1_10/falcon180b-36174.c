//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDRESS "speedtest.net"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    long int start_time, end_time;
    double elapsed_time;
    int bytes_received;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(NULL);
    bytes_received = 0;

    while (1) {
        if (recv(sock, buffer, BUFFER_SIZE, 0) <= 0) {
            break;
        }
        bytes_received += strlen(buffer);
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    speed = (double)bytes_received / (elapsed_time * 1024);

    printf("Speedtest result: %.2f Mbps\n", speed);

    close(sock);

    return 0;
}