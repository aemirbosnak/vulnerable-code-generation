//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME_LEN 255
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN);
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    char data[MAX_DATA_LEN];
    strncpy(data, "PING", MAX_DATA_LEN);
    send(sock, data, strlen(data), 0);

    char buffer[MAX_DATA_LEN];
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_received <= 0) {
        printf("Error receiving data from server\n");
        close(sock);
        return 1;
    }

    printf("Response from server: %s\n", buffer);
    close(sock);
    return 0;
}