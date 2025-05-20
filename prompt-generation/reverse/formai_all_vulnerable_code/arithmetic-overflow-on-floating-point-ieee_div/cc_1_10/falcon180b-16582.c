//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER "speedtest.net"
#define PORT 80

int main() {
    int sock;
    struct sockaddr_in server;
    char *host = SERVER;
    char buffer[1024];
    int bytes_received;
    char *response;
    char *token;
    int content_length;
    int total_bytes_received = 0;
    int start_time, end_time;
    double elapsed_time;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(NULL);

    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);
    send(sock, buffer, strlen(buffer), 0);

    while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        total_bytes_received += bytes_received;
        response = strstr(buffer, "Content-Length:");
        if (response!= NULL) {
            token = strtok(response, " ");
            content_length = atoi(token);
            if (content_length > 0) {
                break;
            }
        }
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    speed = (double)total_bytes_received / elapsed_time;

    printf("Internet Speed: %.2f bytes/second\n", speed);

    close(sock);
    return 0;
}