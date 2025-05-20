//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

struct sockaddr_in server_addr;
int server_socket;

void error(char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server() {
    struct hostent *server;
    server = gethostbyname("localhost");

    if (server == NULL) {
        error("gethostbyname() failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = *(unsigned long *) server->h_addr;

    if (connect(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("connect() failed");
    }

    return 0;
}

int main() {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("socket() failed");
    }

    if (connect_to_server() < 0) {
        error("connect() failed");
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            error("recv() failed");
        }

        printf("Received message: %s\n", buffer);
    }

    close(server_socket);
    return 0;
}