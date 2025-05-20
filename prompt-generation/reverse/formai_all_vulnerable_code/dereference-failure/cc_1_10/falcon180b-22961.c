//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024
#define MAX_PINGS 5
#define PING_INTERVAL 1

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int bytes_sent, bytes_received;
    struct timeval start, end;
    double elapsed_time;
    int total_pings = 0, successful_pings = 0;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Unable to create socket.\n");
        exit(1);
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (connect(sock, (struct sockaddr *)&server, sizeof(server))!= 0) {
        printf("Error: Unable to connect to server.\n");
        exit(1);
    }

    printf("Starting ping test...\n");

    for (int i = 0; i < MAX_PINGS; i++) {
        gettimeofday(&start, NULL);
        send(sock, "PING", strlen("PING"), 0);
        while (TRUE) {
            bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
            if (bytes_received > 0) {
                if (strncmp(buffer, "PONG", strlen("PONG")) == 0) {
                    gettimeofday(&end, NULL);
                    elapsed_time = ((end.tv_sec - start.tv_sec) * 1000) + (end.tv_usec - start.tv_usec) / 1000;
                    printf("Ping %d: %d ms\n", i + 1, elapsed_time);
                    successful_pings++;
                } else {
                    printf("Error: Received invalid response.\n");
                }
                break;
            }
        }
        usleep(PING_INTERVAL * 1000);
        total_pings++;
    }

    printf("Ping test completed.\n");
    printf("Total pings: %d\n", total_pings);
    printf("Successful pings: %d\n", successful_pings);

    close(sock);
    return 0;
}