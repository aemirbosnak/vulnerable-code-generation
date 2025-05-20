//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_SOCKETS 1024
#define BUFFER_SIZE 1024

void die(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket()");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        die("bind()");
    }

    return sock;
}

int connect_socket(int sock, const char* ip, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        die("connect()");
    }

    return sock;
}

void scan_port(int sock, int port) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    if (recv(sock, buffer, BUFFER_SIZE, MSG_PEEK) == 0) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Port %d is open\n", port);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char* ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_SOCKETS - 1;

    if (end_port > 65535) {
        printf("Invalid port range\n");
        return 1;
    }

    for (int i = start_port; i <= end_port; i++) {
        int sock = create_socket(i);
        if (sock == -1) {
            continue;
        }

        if (connect_socket(sock, ip, i) == -1) {
            close(sock);
            continue;
        }

        scan_port(sock, i);
        close(sock);
    }

    return 0;
}