//FormAI DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void scan_port(const char *ip, int port) {
    struct sockaddr_in server;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket.\n");
        return;
    }

    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Port %d is closed.\n", port);
    } else {
        printf("Port %d is open!\n", port);
        close(sock);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: IP address not provided.\n");
        return 1;
    }

    char *ip = argv[1];
    int start_port, end_port;

    printf("Enter the start port: ");
    scanf("%d", &start_port);
    printf("Enter the end port: ");
    scanf("%d", &end_port);

    if (start_port > end_port) {
        printf("Error: Start port cannot be greater than end port.\n");
        return 1;
    }

    for (int i = start_port; i <= end_port; i++) {
        scan_port(ip, i);
    }

    return 0;
}