//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_HOSTNAME 64
#define MAX_DATA 1024

int main() {
    char hostname[MAX_HOSTNAME];
    int port;
    int timeout;
    int sock;
    struct sockaddr_in server;
    char data[MAX_DATA];
    char response[MAX_DATA];
    int bytes_sent, bytes_received;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port: ");
    scanf("%d", &port);

    printf("Enter timeout in seconds: ");
    scanf("%d", &timeout);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to %s:%d: %s\n", hostname, port, strerror(errno));
        exit(1);
    }

    bytes_sent = send(sock, "PING", strlen("PING"), 0);
    if (bytes_sent == -1) {
        printf("Error sending PING: %s\n", strerror(errno));
        exit(1);
    }

    memset(response, 0, sizeof(response));
    bytes_received = recv(sock, response, sizeof(response), 0);
    if (bytes_received == -1) {
        printf("Error receiving response: %s\n", strerror(errno));
        exit(1);
    }

    close(sock);

    printf("Response: %s\n", response);

    return 0;
}