//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect failed");
    }

    send(sock, "GET /speedtest.txt HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n", strlen("GET /speedtest.txt HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n"), 0);

    int bytes_received = 0;
    while (bytes_received < BUFFER_SIZE) {
        int num_bytes = recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (num_bytes == 0) {
            break;
        } else if (num_bytes == -1) {
            error("recv failed");
        }
        bytes_received += num_bytes;
    }

    close(sock);

    FILE *fp;
    fp = fopen("speedtest.txt", "wb");
    if (fp == NULL) {
        error("file open failed");
    }

    fwrite(buffer, bytes_received, 1, fp);
    fclose(fp);

    return 0;
}