//Code Llama-13B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define QUEUE_SIZE 10

typedef struct {
    int sock;
    struct sockaddr_in addr;
} socket_t;

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void setup_socket(socket_t *s, int port) {
    s->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (s->sock < 0) error("socket() failed");

    s->addr.sin_family = AF_INET;
    s->addr.sin_port = htons(port);
    s->addr.sin_addr.s_addr = INADDR_ANY;
}

void send_packet(socket_t *s, const char *buf, int len) {
    if (send(s->sock, buf, len, 0) < 0) error("send() failed");
}

void receive_packet(socket_t *s, char *buf, int len) {
    int n = recv(s->sock, buf, len, 0);
    if (n < 0) error("recv() failed");
    buf[n] = '\0';
}

void close_socket(socket_t *s) {
    if (close(s->sock) < 0) error("close() failed");
}

int main(int argc, char *argv[]) {
    socket_t s;
    char buf[BUF_SIZE];
    int len;

    if (argc != 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    setup_socket(&s, atoi(argv[2]));

    printf("Connected to %s on port %s\n", argv[1], argv[2]);

    while (1) {
        // Send a packet
        send_packet(&s, "Hello, world!", 13);

        // Receive a packet
        receive_packet(&s, buf, BUF_SIZE);
        printf("Received packet: %s\n", buf);

        // Close the socket
        close_socket(&s);
    }

    return 0;
}