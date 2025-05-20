//Falcon2-11B DATASET v1.0 Category: Networking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
    int listen_sock, client_sock, bytes_read, bytes_written;
    struct sockaddr_in client_addr;
    struct hostent *server;
    int portno = 12345;
    char buf[256];
    char *name = NULL;

    if (argc > 1) {
        portno = atoi(argv[1]);
    }

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(portno);
    bzero((char *) &client_addr.sin_addr, sizeof(client_addr.sin_addr));
    memcpy((char *) &client_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    if (bind(listen_sock, (struct sockaddr *) &client_addr, sizeof(client_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(listen_sock, MAX_CLIENTS);

    while (1) {
        client_sock = accept(listen_sock, (struct sockaddr *) &client_addr, (socklen_t *) &bytes_read);
        if (client_sock < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (fork() == 0) {
            name = "server";
            close(listen_sock);
            close(client_sock);
            break;
        }

        close(listen_sock);
        close(client_sock);
    }

    printf("Connected as %s\n", name);

    while (1) {
        bytes_read = recv(client_sock, buf, 255, 0);
        if (bytes_read < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        bytes_written = send(client_sock, buf, bytes_read, 0);
        if (bytes_written < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        printf("%s > %s\n", name, buf);
    }

    close(client_sock);
    close(listen_sock);
    return 0;
}