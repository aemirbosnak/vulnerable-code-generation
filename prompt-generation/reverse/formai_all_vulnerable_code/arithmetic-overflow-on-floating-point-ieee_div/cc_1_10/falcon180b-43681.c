//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER "speedtest.net"
#define PORT 8080

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[1024];
    int bytes_received;
    struct timeval start, end;
    double elapsed_time;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    gettimeofday(&start, NULL);
    send(sock, "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n"), 0);

    bytes_received = 0;
    while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    gettimeofday(&end, NULL);
    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    speed = (double)bytes_received / elapsed_time;

    printf("\nSpeed: %.2f bytes/second\n", speed);

    close(sock);
    return 0;
}