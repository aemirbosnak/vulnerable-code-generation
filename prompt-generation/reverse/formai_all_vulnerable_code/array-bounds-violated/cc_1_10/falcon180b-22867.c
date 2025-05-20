//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define PORT "3490"

void scan_network(char* ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed to %s:%s\n", ip, PORT);
        return;
    }

    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);

    send(sock, "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n"), 0);

    int bytes_received = recv(sock, buf, BUF_SIZE, 0);
    if (bytes_received <= 0) {
        printf("No response from %s:%s\n", ip, PORT);
        return;
    }

    buf[bytes_received] = '\0';
    printf("Response from %s:%s:\n%s", ip, PORT, buf);

    close(sock);
}

int main() {
    char ip[16];
    int i;
    for (i = 1; i <= 255; i++) {
        sprintf(ip, "192.168.1.%d", i);
        scan_network(ip, PORT);
    }

    return 0;
}