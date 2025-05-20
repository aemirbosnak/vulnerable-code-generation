//Falcon-180B DATASET v1.0 Category: Firewall ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024
#define BACKLOG 5
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int listening_socket, new_socket, opt = TRUE;
    int max_line = MAX_LINE;
    char buffer[MAX_LINE];
    struct sockaddr_in address;
    socklen_t addr_size;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port_number> <log_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(listening_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    if (bind(listening_socket, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listening_socket, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Firewall started on port %s\n", argv[1]);
    fprintf(stdout, "Logging to file %s\n", argv[2]);

    while (TRUE) {
        addr_size = sizeof(address);
        new_socket = accept(listening_socket, (struct sockaddr *)&address, &addr_size);

        if (new_socket == -1) {
            perror("accept");
            continue;
        }

        fprintf(stdout, "Connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        while (TRUE) {
            memset(buffer, 0, max_line);
            if (recv(new_socket, buffer, max_line, 0) <= 0) {
                break;
            }
            fprintf(stdout, "Received: %s", buffer);
        }

        close(new_socket);
    }

    return 0;
}