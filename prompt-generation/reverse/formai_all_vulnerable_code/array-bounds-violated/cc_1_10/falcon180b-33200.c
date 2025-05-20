//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER "speedtest.net"
#define PORT 80

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER, &server_addr.sin_addr) <= 0) {
        error_handling("invalid address/hostname");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
    }

    sprintf(send_buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1], SERVER);

    if (send(sock, send_buffer, strlen(send_buffer), 0) == -1) {
        error_handling("send failed");
    }

    memset(recv_buffer, 0, BUFFER_SIZE);
    int bytes_received = 0;

    while ((bytes_received = recv(sock, recv_buffer, BUFFER_SIZE - 1, 0)) > 0) {
        recv_buffer[bytes_received] = '\0';
        printf("%s", recv_buffer);
    }

    if (bytes_received == -1) {
        error_handling("recv failed");
    }

    close(sock);
    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}