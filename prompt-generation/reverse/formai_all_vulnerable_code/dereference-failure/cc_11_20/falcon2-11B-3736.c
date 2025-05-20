//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/wait.h>

#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, portno;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);
    if (portno <= 0 || portno > 65535) {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    if (listen(listen_socket, MAX_CLIENTS) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if (client_socket < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        pid_t child_pid = fork();
        if (child_pid == 0) {
            close(listen_socket);
            close(client_socket);

            char buffer[1024];
            int n;

            while ((n = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
                printf("%s\n", buffer);
                send(STDOUT_FILENO, buffer, n, 0);
            }

            close(client_socket);
            exit(0);
        } else if (child_pid > 0) {
            close(client_socket);
        } else {
            printf("Error: Unable to fork child process\n");
            exit(1);
        }
    }

    return 0;
}