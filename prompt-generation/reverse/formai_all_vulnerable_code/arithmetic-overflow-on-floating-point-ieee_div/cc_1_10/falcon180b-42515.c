//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER "speedtest.net"
#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *request = "GET /speedtest HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n";
    char response[BUFFER_SIZE];
    int response_len;
    double start_time, end_time;
    double elapsed_time;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = clock();
    send(sock, request, strlen(request), 0);
    response_len = recv(sock, response, BUFFER_SIZE, 0);

    if (response_len <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    end_time = clock();
    elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;
    speed = response_len / elapsed_time;

    printf("Speed: %.2f bytes/sec\n", speed);

    close(sock);
    return 0;
}