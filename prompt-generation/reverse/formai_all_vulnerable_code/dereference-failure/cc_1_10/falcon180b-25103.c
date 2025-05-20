//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *ip;
    int port;
    char buf[BUF_SIZE];
    int len;
    struct ifreq ifr;
    int s;
    char *ptr;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buf, 0, BUF_SIZE);
        len = recv(sock, buf, BUF_SIZE, 0);
        if (len <= 0) {
            printf("Error receiving data\n");
            break;
        }

        printf("%s", buf);
    }

    close(sock);
    return 0;
}