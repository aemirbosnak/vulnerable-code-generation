//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TIMEOUT 5

int ping(char *hostname) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return -1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(7); // Echo port

    if (inet_pton(AF_INET, hostname, &server.sin_addr) <= 0) {
        printf("Invalid hostname\n");
        close(sock);
        return -1;
    }

    char data[MAX_DATA];
    strncpy(data, "PING", MAX_DATA);
    send(sock, data, strlen(data), 0);

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);

    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    if (select(sock + 1, &readfds, NULL, NULL, &tv) == -1) {
        printf("Error selecting socket: %s\n", strerror(errno));
        close(sock);
        return -1;
    }

    char buffer[MAX_DATA];
    int bytes_received = recv(sock, buffer, MAX_DATA, 0);

    if (bytes_received <= 0) {
        printf("No response from host\n");
        close(sock);
        return -1;
    }

    close(sock);

    if (strncmp(buffer, "PONG", 4)!= 0) {
        printf("Invalid response\n");
        return -1;
    }

    printf("Host is alive\n");
    return 0;
}

int main() {
    char hostname[MAX_HOSTNAME];
    printf("Enter hostname: ");
    scanf("%s", hostname);

    int result = ping(hostname);

    if (result == -1) {
        printf("Error: %s\n", strerror(errno));
    }

    return 0;
}