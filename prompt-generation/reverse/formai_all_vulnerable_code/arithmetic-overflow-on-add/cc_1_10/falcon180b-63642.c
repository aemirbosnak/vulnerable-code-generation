//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

#define PACKET_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char send_data[PACKET_SIZE];
    char recv_data[PACKET_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);

        int max_fd = sock;
        int ret = select(max_fd + 1, &readfds, NULL, NULL, NULL);

        if (ret == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(sock, &readfds)) {
            int bytes_received = recv(sock, recv_data, PACKET_SIZE, 0);
            if (bytes_received <= 0) {
                perror("recv");
                exit(EXIT_FAILURE);
            }

            printf("Received: %s\n", recv_data);
        }
    }

    close(sock);
    return 0;
}