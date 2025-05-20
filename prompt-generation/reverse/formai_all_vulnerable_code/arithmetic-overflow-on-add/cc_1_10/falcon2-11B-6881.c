//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define SERVER_PORT 8080
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

int main() {
    int server_socket, conn_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int n;
    int color_code[3];

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        return 1;
    }

    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("listen failed");
        return 1;
    }

    while (1) {
        fd_set readfds;
        struct timeval tv;
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        FD_ZERO(&readfds);
        FD_SET(server_socket, &readfds);

        if (select(server_socket + 1, &readfds, NULL, NULL, &tv) < 1) {
            perror("select failed");
            return 1;
        }

        if (FD_ISSET(server_socket, &readfds)) {
            conn_socket = accept(server_socket, (struct sockaddr *) &client_addr, (socklen_t*) &n);
            if (conn_socket == -1) {
                perror("accept failed");
                return 1;
            }

            printf("New connection from %s on port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            while ((n = recv(conn_socket, buffer, BUFFER_SIZE, 0)) > 0) {
                printf("Received message: %s\n", buffer);
                color_code[0] = buffer[0];
                color_code[1] = buffer[1];
                color_code[2] = buffer[2];

                printf("R: %d, G: %d, B: %d\n", color_code[0], color_code[1], color_code[2]);

                if (send(conn_socket, "OK", 2, 0) < 0) {
                    perror("send failed");
                    return 1;
                }
            }

            close(conn_socket);
        }
    }

    return 0;
}