//Falcon-180B DATASET v1.0 Category: Networking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void die(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket failed");
    }
    return sock;
}

struct sockaddr_in create_addr(const char* ip, int port) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &addr.sin_addr);
    return addr;
}

int connect_socket(int sock, const char* ip, int port) {
    struct sockaddr_in addr = create_addr(ip, port);
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        die("connect failed");
    }
    return sock;
}

void send_data(int sock, const char* data) {
    if (send(sock, data, strlen(data), 0) == -1) {
        die("send failed");
    }
}

char* receive_data(int sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        die("recv failed");
    }
    return strdup(buffer);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <ip> <port> <data>\n", argv[0]);
        return 1;
    }

    const char* ip = argv[1];
    int port = atoi(argv[2]);
    const char* data = argv[3];

    int sock = create_socket();
    sock = connect_socket(sock, ip, port);

    send_data(sock, data);

    char* response = receive_data(sock);
    printf("Response: %s\n", response);

    close(sock);
    free(response);

    return 0;
}