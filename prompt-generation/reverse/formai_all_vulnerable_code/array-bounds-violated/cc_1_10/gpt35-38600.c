//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int create_socket(const char *server_address, const int server_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;

    if (sock == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(server_port);

    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }

    return sock;
}

void receive_data(int sock) {
    char buffer[BUFF_SIZE] = {0};
    ssize_t n;

    while ((n = recv(sock, buffer, BUFF_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);

        if (n < BUFF_SIZE) {
            break;
        }
    }

    if (n < 0) {
        perror("Failed to receive data from server");
        exit(EXIT_FAILURE);
    }
}

void send_data(int sock, const char *data) {
    ssize_t n = send(sock, data, strlen(data), 0);

    if (n < 0) {
        perror("Failed to send data to server");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        printf("Usage: imap_client <server_address> <server_port> <user_email>\n");
        exit(EXIT_FAILURE);
    }

    int server_port = atoi(argv[2]);

    int sock = create_socket(argv[1], server_port);

    char buffer[BUFF_SIZE] = {0};
    receive_data(sock);

    sprintf(buffer, "A001 LOGIN %s\r\n", argv[3]);
    send_data(sock, buffer);
    receive_data(sock);

    sprintf(buffer, "A002 SELECT INBOX\r\n");
    send_data(sock, buffer);
    receive_data(sock);

    sprintf(buffer, "A003 LOGOUT\r\n");
    send_data(sock, buffer);
    receive_data(sock);

    close(sock);

    return 0;
}