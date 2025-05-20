//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 100

int main(int argc, char **argv) {
    int server_fd, new_socket, valread, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char msg[MAX_MSG_LEN];
    char buffer[MAX_MSG_LEN];
    int i;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "error, no such host\n");
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(5000);

    if (connect(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    for (i = 0; i < MAX_CLIENTS; i++) {
        printf("waiting for client %d\n", i);
        new_socket = accept(server_fd, (struct sockaddr *) &cli_addr, &addrlen);
        if (new_socket < 0) {
            perror("accept");
            exit(1);
        }

        if (i == MAX_CLIENTS - 1) {
            break;
        }

        printf("connected to client %d\n", i);
        if (fork() == 0) {
            // child process
            close(server_fd);
            close(new_socket);
            while (1) {
                valread = read(new_socket, buffer, MAX_MSG_LEN);
                if (valread < 0) {
                    perror("read");
                    exit(1);
                }

                if (valread == 0) {
                    break;
                }

                send(new_socket, buffer, valread, 0);
            }
            exit(0);
        }
    }

    for (i = 0; i < MAX_CLIENTS; i++) {
        printf("connected to client %d\n", i);
        if (fork() == 0) {
            // child process
            close(server_fd);
            close(new_socket);
            while (1) {
                printf("client %d> ", i);
                fgets(msg, MAX_MSG_LEN, stdin);
                send(new_socket, msg, strlen(msg), 0);
                if (strcmp(msg, "quit") == 0) {
                    break;
                }
            }
            exit(0);
        }
    }

    close(server_fd);
    return 0;
}