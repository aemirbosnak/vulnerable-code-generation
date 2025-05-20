//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SOCKET_ERROR -1

int main(int argc, char *argv[]) {
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    printf("Happy QoS Monitor starting up!\n");

    if (argc!= 3) {
        printf("Usage:./qos_monitor <server_address> <port_number>\n");
        return 1;
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == SOCKET_ERROR) {
        printf("Error creating socket.\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Error connecting to server.\n");
        close(socket_fd);
        return 1;
    }

    printf("Connected to server!\n");

    while (1) {
        bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data.\n");
            close(socket_fd);
            return 1;
        }

        printf("Received %d bytes of data:\n%s\n", bytes_received, buffer);
    }

    close(socket_fd);
    return 0;
}