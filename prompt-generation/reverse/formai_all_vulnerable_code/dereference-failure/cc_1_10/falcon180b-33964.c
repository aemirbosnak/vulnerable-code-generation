//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 1024
#define PORT_NUM 65535
#define TIMEOUT 1000 // timeout in milliseconds

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    if (port <= 0 || port > PORT_NUM) {
        printf("Invalid port number.\n");
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed.\n", port);
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out.\n");
        } else {
            printf("Error connecting to host.\n");
        }
        close(sock);
        exit(1);
    }

    printf("Port %d is open.\n", port);
    close(sock);
    exit(0);
}