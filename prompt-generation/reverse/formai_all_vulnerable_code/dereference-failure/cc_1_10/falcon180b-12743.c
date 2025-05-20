//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int sock, max_fd;
    struct sockaddr_in server;
    int addrlen = sizeof(server);
    int port = atoi(argv[1]);
    int count = 0;
    fd_set readfds;
    int retval;
    char buffer[1024];

    FD_ZERO(&readfds);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket!\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == -1) {
        printf("Error connecting to server!\n");
        exit(2);
    }

    FD_SET(sock, &readfds);
    max_fd = sock;

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);
        max_fd = sock;

        retval = select(max_fd + 1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(sock, &readfds)) {
            memset(buffer, 0, sizeof(buffer));
            retval = recv(sock, buffer, sizeof(buffer), 0);

            if (retval <= 0) {
                printf("Server disconnected!\n");
                close(sock);
                exit(3);
            }

            printf("Server: %s\n", buffer);
        }

        if (FD_ISSET(0, &readfds)) {
            memset(buffer, 0, sizeof(buffer));
            retval = read(0, buffer, sizeof(buffer));

            if (retval <= 0) {
                printf("Client disconnected!\n");
                close(sock);
                exit(4);
            }

            send(sock, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}