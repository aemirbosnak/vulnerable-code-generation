//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in server;
    int opt = 1;
    char *ip_address;
    int port_range_start, port_range_end;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int i;

    if (argc!= 5) {
        printf("Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        exit(1);
    }

    ip_address = argv[1];
    port_range_start = atoi(argv[2]);
    port_range_end = atoi(argv[3]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        printf("Error setting socket option\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_port = htons(port_range_start);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Connection failed\n");
        exit(1);
    }

    for (i = port_range_start; i <= port_range_end; i++) {
        server.sin_port = htons(i);

        if (send(sock, " ", 1, 0) == -1) {
            printf("Error sending data\n");
            exit(1);
        }

        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            printf("Port %d is %s\n", i, (strcmp(buffer, "open") == 0)? "open" : "closed");
        } else {
            printf("No response received for port %d\n", i);
        }
    }

    close(sock);
    return 0;
}