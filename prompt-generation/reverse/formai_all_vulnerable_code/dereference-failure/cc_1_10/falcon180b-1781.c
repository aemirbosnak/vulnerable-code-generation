//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_PINGS 5
#define PING_INTERVAL 1

void send_ping(int sock) {
    char ping_data[] = "PING";
    send(sock, ping_data, strlen(ping_data), 0);
}

void receive_pong(int sock) {
    char pong_data[1024];
    memset(pong_data, 0, sizeof(pong_data));
    int bytes_received = recv(sock, pong_data, sizeof(pong_data), 0);

    if (bytes_received > 0) {
        pong_data[bytes_received] = '\0';
        printf("Received pong: %s\n", pong_data);
    } else {
        printf("No pong received\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    printf("Connected to server\n");

    for (int i = 0; i < MAX_PINGS; i++) {
        send_ping(sock);
        sleep(PING_INTERVAL);
        receive_pong(sock);
    }

    close(sock);
    return 0;
}