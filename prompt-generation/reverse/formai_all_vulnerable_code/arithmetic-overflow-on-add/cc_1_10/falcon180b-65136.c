//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535

void scan(int sock, int port) {
    struct sockaddr_in serv_addr;
    int addrlen = sizeof(serv_addr);
    char send_data[1024];
    char recv_data[1024];
    int bytes_sent = 0;
    int bytes_recv = 0;

    memset(send_data, 0, sizeof(send_data));
    memset(recv_data, 0, sizeof(recv_data));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed on port %d\n", port);
    } else {
        printf("Connection established on port %d\n", port);
        while (bytes_recv <= 0) {
            bytes_recv = recv(sock, recv_data, sizeof(recv_data), 0);
            if (bytes_recv <= 0) {
                break;
            }
            printf("Received data: %s\n", recv_data);
        }
    }

    close(sock);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket creation failed\n");
        exit(1);
    }

    printf("Enter IP address: ");
    char ip[16];
    scanf("%s", ip);

    printf("Enter start port: ");
    int start_port;
    scanf("%d", &start_port);

    printf("Enter end port: ");
    int end_port;
    scanf("%d", &end_port);

    for (int port = start_port; port <= end_port; port++) {
        scan(sock, port);
    }

    close(sock);
    return 0;
}