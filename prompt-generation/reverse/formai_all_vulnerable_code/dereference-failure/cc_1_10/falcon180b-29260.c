//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int scan_ports(int start_port, int end_port);

int main(int argc, char *argv[]) {

    if (argc!= 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    int total_open_ports = 0;

    for (int i = start_port; i <= end_port; i++) {
        if (scan_ports(i, i)) {
            total_open_ports++;
        }
    }

    printf("Total open ports: %d\n", total_open_ports);

    return 0;
}

int scan_ports(int start_port, int end_port) {

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 0;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        close(server_socket);
        return 0;
    }

    listen(server_socket, 5);

    for (int i = start_port; i <= end_port; i++) {

        struct sockaddr_in client_addr;
        memset(&client_addr, 0, sizeof(client_addr));

        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(i);
        client_addr.sin_addr.s_addr = INADDR_ANY;

        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));

        if (client_socket == -1) {
            if (errno == ECONNREFUSED) {
                printf("%d: Closed\n", i);
            } else {
                printf("%d: Error\n", i);
            }
        } else {
            printf("%d: Open\n", i);
            close(client_socket);
        }
    }

    close(server_socket);

    return 1;
}