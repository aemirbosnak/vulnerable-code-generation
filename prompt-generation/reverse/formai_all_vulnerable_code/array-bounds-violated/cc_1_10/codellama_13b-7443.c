//Code Llama-13B DATASET v1.0 Category: Client Server Application ; Style: Alan Turing
// Client-Server Application in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUF_SIZE 1024

void client(char* hostname, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == -1) {
        perror("Connection failed");
        exit(1);
    }

    char buf[MAX_BUF_SIZE];
    while (1) {
        printf("Enter message to send: ");
        fgets(buf, MAX_BUF_SIZE, stdin);
        buf[strlen(buf) - 1] = '\0';

        if (strcmp(buf, "quit") == 0) {
            break;
        }

        if (send(sock, buf, strlen(buf), 0) == -1) {
            perror("Message sending failed");
            exit(1);
        }

        memset(buf, 0, MAX_BUF_SIZE);

        if (recv(sock, buf, MAX_BUF_SIZE, 0) == -1) {
            perror("Message receiving failed");
            exit(1);
        }

        printf("Received message: %s\n", buf);
    }

    close(sock);
}

void server(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr*)&server, sizeof(server)) == -1) {
        perror("Binding failed");
        exit(1);
    }

    if (listen(sock, 3) == -1) {
        perror("Listening failed");
        exit(1);
    }

    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);
    int conn_sock = accept(sock, (struct sockaddr*)&client, &client_len);
    if (conn_sock == -1) {
        perror("Connection failed");
        exit(1);
    }

    char buf[MAX_BUF_SIZE];
    while (1) {
        if (recv(conn_sock, buf, MAX_BUF_SIZE, 0) == -1) {
            perror("Message receiving failed");
            exit(1);
        }

        printf("Received message: %s\n", buf);

        if (strcmp(buf, "quit") == 0) {
            break;
        }

        if (send(conn_sock, buf, strlen(buf), 0) == -1) {
            perror("Message sending failed");
            exit(1);
        }

        memset(buf, 0, MAX_BUF_SIZE);
    }

    close(conn_sock);
}

int main() {
    int port = PORT;
    if (fork() == 0) {
        client("localhost", port);
    } else {
        server(port);
    }

    return 0;
}