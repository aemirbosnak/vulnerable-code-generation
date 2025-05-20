//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <Wi-Fi interface>\n", argv[0]);
        return 1;
    }

    char *interface = argv[1];
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(1234);

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        int len = recv(sock, buffer, BUFFER_SIZE, 0);
        if (len <= 0) {
            perror("recv");
            break;
        }

        buffer[len] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sock);
    return 0;
}