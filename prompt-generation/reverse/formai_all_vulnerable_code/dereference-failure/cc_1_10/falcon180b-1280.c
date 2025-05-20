//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_help() {
    printf("Usage:./portscanner <IP Address> <Start Port> <End Port>\n");
}

void scan_ports(char* ip, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);
    if (inet_pton(AF_INET, ip, &server.sin_addr) <= 0) {
        printf("Invalid IP Address\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    for (int i = start_port; i <= end_port; i++) {
        server.sin_port = htons(i);
        if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0) {
            snprintf(buffer, BUFFER_SIZE, "Port %d is open\n", i);
            write(1, buffer, strlen(buffer));
        } else if (errno == ECONNREFUSED) {
            snprintf(buffer, BUFFER_SIZE, "Port %d is closed\n", i);
            write(1, buffer, strlen(buffer));
        } else {
            snprintf(buffer, BUFFER_SIZE, "Error connecting to port %d: %s\n", i, strerror(errno));
            write(2, buffer, strlen(buffer));
        }
    }

    close(sock);
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        print_help();
        return 1;
    }

    char* ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        printf("Invalid port range\n");
        return 1;
    }

    scan_ports(ip, start_port, end_port);

    return 0;
}