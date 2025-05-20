//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int max_speed = 0;
    int speed = 0;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket");
        exit(errno);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(errno);
    }

    if (listen(server_socket, 5) < 0) {
        perror("listen");
        exit(errno);
    }

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr))) < 0) {
            perror("accept");
            exit(errno);
        }

        bytes_received = 0;
        while (1) {
            if ((bytes_received += recv(client_socket, buffer, BUFFER_SIZE, 0)) <= 0) {
                break;
            }
        }

        speed = bytes_received * 8 / (1024 * 1024);
        if (speed > max_speed) {
            max_speed = speed;
        }

        close(client_socket);
    }

    close(server_socket);

    printf("Maximum speed: %d Mbps\n", max_speed);

    return 0;
}