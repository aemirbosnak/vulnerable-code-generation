//Code Llama-13B DATASET v1.0 Category: Text processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define MAX_MSG_LEN 1024

int main(int argc, char **argv) {
    int sock, new_sock, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_MSG_LEN];

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sock, 5);

    while (1) {
        clilen = sizeof(cli_addr);
        new_sock = accept(sock, (struct sockaddr *) &cli_addr, &clilen);
        if (new_sock < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        bzero(buffer, MAX_MSG_LEN);
        read(new_sock, buffer, MAX_MSG_LEN);
        printf("Received message from client: %s\n", buffer);

        char *message = "Hello, client!";
        write(new_sock, message, strlen(message));

        close(new_sock);
    }

    return 0;
}