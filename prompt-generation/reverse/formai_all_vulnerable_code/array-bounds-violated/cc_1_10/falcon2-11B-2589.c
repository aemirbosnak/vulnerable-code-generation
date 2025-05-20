//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

void startServer(int port) {
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return;
    }

    if (bind(sock, (struct sockaddr *) &address, sizeof(address)) == -1) {
        printf("Error binding socket\n");
        return;
    }

    if (listen(sock, 5) == -1) {
        printf("Error listening on socket\n");
        return;
    }

    for (;;) {
        int connSocket = accept(sock, NULL, NULL);
        if (connSocket == -1) {
            printf("Error accepting connection\n");
            return;
        }

        printf("Connection accepted from %s\n", inet_ntoa(address.sin_addr));

        char buffer[256];
        int bytesRead = recv(connSocket, buffer, sizeof(buffer) - 1, 0);

        if (bytesRead == -1) {
            printf("Error reading from socket\n");
            close(connSocket);
            continue;
        }

        buffer[bytesRead] = '\0';

        printf("Received: %s\n", buffer);

        send(connSocket, "HTTP/1.1 200 OK\r\n\r\nHello, World!", strlen("HTTP/1.1 200 OK\r\n\r\nHello, World!") + 1, 0);

        close(connSocket);
    }

    close(sock);
}

int main() {
    int port = 8080;
    startServer(port);

    return 0;
}