//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535

void scan(int sock, int port) {
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));

    if (result == -1) {
        printf("Port %d is closed.\n", port);
    } else {
        printf("Port %d is open.\n", port);
        close(sock);
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    printf("Enter the IP address: ");
    char ip[16];
    scanf("%s", ip);

    printf("Enter the starting port: ");
    int start;
    scanf("%d", &start);

    printf("Enter the ending port: ");
    int end;
    scanf("%d", &end);

    if (end < start) {
        printf("Invalid port range.\n");
        close(sock);
        return 1;
    }

    for (int i = start; i <= end; i++) {
        scan(sock, i);
    }

    close(sock);
    return 0;
}