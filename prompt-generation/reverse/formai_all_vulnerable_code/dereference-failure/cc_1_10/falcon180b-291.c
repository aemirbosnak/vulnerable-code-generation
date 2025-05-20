//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT_MAX 65535

int scan_port(int sock, int target_ip, int port) {
    struct sockaddr_in server;
    int result = 0;

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(target_ip);
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        result = TRUE;
    } else if (errno == ECONNREFUSED) {
        result = FALSE;
    } else {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return result;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <target_ip> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int target_ip = inet_addr(argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (target_ip == INADDR_NONE) {
        printf("Error: Invalid target IP address.\n");
        exit(EXIT_FAILURE);
    }

    if (start_port > end_port || start_port < 1 || end_port > PORT_MAX) {
        printf("Error: Invalid port range.\n");
        exit(EXIT_FAILURE);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, inet_ntoa(*(struct in_addr *)&target_ip));

    for (int i = start_port; i <= end_port; i++) {
        if (scan_port(sock, target_ip, i)) {
            printf("%d - Open\n", i);
        } else {
            printf("%d - Closed\n", i);
        }
    }

    close(sock);
    exit(EXIT_SUCCESS);
}