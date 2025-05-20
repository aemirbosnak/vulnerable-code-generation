//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "speedtest.net"
#define SERVER_PORT 80

void send_request(int sock) {
    char request[100];
    strcpy(request, "GET / HTTP/1.1\r\n");
    strcat(request, "Host: speedtest.net\r\n");
    strcat(request, "Connection: close\r\n\r\n");

    send(sock, request, strlen(request), 0);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    time_t start_time, end_time;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    time(&start_time);
    send_request(sock);

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("%s", buffer);
    }

    close(sock);

    time(&end_time);

    printf("\nInternet speed: %ld bytes/second\n", (end_time - start_time) * BUFFER_SIZE / (long)bytes_received);

    return 0;
}