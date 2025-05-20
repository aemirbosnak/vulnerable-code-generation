//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int listen_socket, conn_socket, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);

    if (bind(listen_socket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(listen_socket, 5) < 0) {
        perror("ERROR on listen");
        exit(1);
    }

    while (1) {
        conn_socket = accept(listen_socket, (struct sockaddr *) &cli_addr, (socklen_t *) &portno);

        if (conn_socket < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("New connection established with client: %s, port: %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            i = read(conn_socket, buffer, sizeof(buffer));

            if (i < 0) {
                perror("ERROR reading from socket");
                exit(1);
            } else if (i == 0) {
                close(conn_socket);
                break;
            }

            send(listen_socket, buffer, i, 0);

            i = read(listen_socket, buffer, sizeof(buffer));

            if (i < 0) {
                perror("ERROR reading from socket");
                exit(1);
            } else if (i == 0) {
                close(listen_socket);
                close(conn_socket);
                break;
            }

            send(conn_socket, buffer, i, 0);
        }

        close(conn_socket);
    }

    return 0;
}