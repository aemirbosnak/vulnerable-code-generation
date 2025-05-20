//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: decentralized
// Decentralized Network Topology Mapper
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define PORT 8080
#define BUFSIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock, new_sock, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFSIZE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("ERROR opening socket");
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    listen(sock, 5);

    clilen = sizeof(cli_addr);

    while (1) {
        new_sock = accept(sock, (struct sockaddr *) &cli_addr, &clilen);
        if (new_sock < 0) {
            error("ERROR on accept");
        }

        bzero(buffer, BUFSIZE);
        read(new_sock, buffer, BUFSIZE);
        printf("Received message from client: %s\n", buffer);

        bzero(buffer, BUFSIZE);
        sprintf(buffer, "Hello, client! It's a decentralized network mapper.");
        write(new_sock, buffer, strlen(buffer));

        close(new_sock);
    }

    close(sock);

    return 0;
}