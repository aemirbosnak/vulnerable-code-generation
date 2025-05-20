//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER "www.google.com"
#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *send_buf;
    char recv_buf[BUFFER_SIZE];
    int bytes_sent, bytes_recv;
    double start_time, end_time;
    double elapsed_time;
    double speed;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error: socket() failed\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: connect() failed\n");
        close(sock);
        return 1;
    }

    send_buf = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
    bytes_sent = send(sock, send_buf, strlen(send_buf), 0);
    if (bytes_sent == -1) {
        fprintf(stderr, "Error: send() failed\n");
        close(sock);
        return 1;
    }

    start_time = time(NULL);
    bytes_recv = recv(sock, recv_buf, BUFFER_SIZE, 0);
    end_time = time(NULL);

    elapsed_time = difftime(end_time, start_time);

    speed = (double)bytes_recv / elapsed_time;

    printf("Internet speed: %.2f bytes/second\n", speed);

    close(sock);
    return 0;
}