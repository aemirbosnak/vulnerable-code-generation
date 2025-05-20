//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDRESS "speedtest.net"

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_addr;
    int opt = 1;
    char buffer[BUFFER_SIZE];
    fd_set read_fds;
    struct timeval timeout;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    FD_ZERO(&read_fds);
    FD_SET(server_socket, &read_fds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    while (1) {
        int retval = select(server_socket + 1, &read_fds, NULL, NULL, &timeout);

        if (retval == -1) {
            printf("Error with select()\n");
            return 1;
        }

        if (FD_ISSET(server_socket, &read_fds)) {
            memset(buffer, 0, BUFFER_SIZE);

            int bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                printf("Error receiving data\n");
                return 1;
            }

            printf("%s", buffer);
        }
    }

    close(server_socket);
    return 0;
}