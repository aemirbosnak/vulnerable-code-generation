//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sock, err = 0;
    struct sockaddr_in server;
    char buffer[1024];
    int bytes_received;
    struct timeval timeout;
    int timeout_ms = 1000; // 1 second timeout

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server.sin_addr);
    server.sin_port = htons(atoi(argv[2]));

    err = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (err!= 0) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

    while (1) {
        bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            printf("Connection lost\n");
            break;
        }
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}