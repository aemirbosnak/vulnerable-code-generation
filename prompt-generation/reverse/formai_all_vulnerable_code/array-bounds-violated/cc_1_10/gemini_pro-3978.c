//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int sock, n;
    struct sockaddr_in addr;
    char buf[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        printf("Enter message (q to quit): ");
        fgets(buf, sizeof(buf), stdin);
        if (strcmp(buf, "q\n") == 0) {
            break;
        }

        n = send(sock, buf, strlen(buf), 0);
        if (n < 0) {
            perror("send");
            exit(1);
        }

        n = recv(sock, buf, sizeof(buf), 0);
        if (n < 0) {
            perror("recv");
            exit(1);
        }

        buf[n] = '\0';
        printf("Received: %s", buf);
    }

    close(sock);
    return 0;
}