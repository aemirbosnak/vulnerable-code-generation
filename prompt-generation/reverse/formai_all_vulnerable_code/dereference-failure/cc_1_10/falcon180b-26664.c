//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    int port;
    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    for (port = 1; port <= MAX_PORTS; port++) {
        if (port!= atoi(argv[2])) {
            memset(buffer, 0, BUFFER_SIZE);
            sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
            send(sock, buffer, strlen(buffer), 0);

            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
            if (bytes_received > 0) {
                printf("Port %d is open\n", port);
            }
        }
    }

    close(sock);
    return 0;
}