//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT "80"

void scan_network(char *ip) {
    int sock;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(PORT));
    inet_pton(AF_INET, ip, &addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        close(sock);
        return;
    }

    send(sock, "GET / HTTP/1.1\r\nHost: \r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: \r\n\r\n"), 0);

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0))!= 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);
}

int main() {
    char ip[16];
    int i;

    for (i = 1; i <= 255; i++) {
        sprintf(ip, "192.168.1.%d", i);
        scan_network(ip);
    }

    return 0;
}