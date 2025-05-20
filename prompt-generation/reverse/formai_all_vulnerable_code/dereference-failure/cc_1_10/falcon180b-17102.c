//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    int server_len = sizeof(server);
    int status;
    char buffer[1024];
    char *host;
    int port;

    if (argc!= 4) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, host, &server.sin_addr);

    // Connect to server
    status = connect(sock, (struct sockaddr *)&server, server_len);
    if (status == -1) {
        printf("Error: connection failed\n");
        exit(1);
    }

    printf("Connected to server %s:%d\n", host, port);

    // Send data
    snprintf(buffer, sizeof(buffer), "PING");
    send(sock, buffer, strlen(buffer), 0);

    // Receive data
    memset(buffer, 0, sizeof(buffer));
    status = recv(sock, buffer, sizeof(buffer), 0);
    if (status == -1) {
        printf("Error: data reception failed\n");
        exit(1);
    }

    printf("Received data: %s\n", buffer);

    close(sock);

    return 0;
}