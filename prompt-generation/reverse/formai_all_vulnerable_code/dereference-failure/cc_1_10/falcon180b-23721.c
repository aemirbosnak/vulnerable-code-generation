//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock = 0;
    struct sockaddr_in server_addr;
    struct hostent *host;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to %s:%s\n", argv[1], argv[2]);
        exit(1);
    }

    printf("Connected to %s:%s\n", argv[1], argv[2]);

    char buffer[BUF_SIZE];
    while (1) {
        memset(buffer, 0, BUF_SIZE);
        if (recv(sock, buffer, BUF_SIZE, 0) <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}