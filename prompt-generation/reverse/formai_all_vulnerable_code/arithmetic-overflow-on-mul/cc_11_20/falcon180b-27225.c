//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define SERVER "127.0.0.1"
#define PORT 80
#define PACKET_SIZE 1024
#define PACKET_INTERVAL 1000 // 1 second

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[PACKET_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        int bytes_sent = send(sock, buffer, PACKET_SIZE, 0);
        if (bytes_sent == -1) {
            printf("Error sending packet\n");
            exit(1);
        }

        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);

        while (1) {
            int bytes_received = recv(sock, buffer, PACKET_SIZE, 0);
            if (bytes_received == -1) {
                printf("Error receiving packet\n");
                exit(1);
            }

            if (bytes_received == 0) {
                printf("Server closed connection\n");
                exit(1);
            }

            gettimeofday(&end_time, NULL);

            long int elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);

            if (elapsed_time >= PACKET_INTERVAL) {
                break;
            }
        }

        close(sock);
        printf("Reconnecting to server...\n");
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error creating socket\n");
            exit(1);
        }

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(PORT);
        inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            printf("Error connecting to server\n");
            exit(1);
        }

        printf("Reconnected to server\n");
    }

    return 0;
}