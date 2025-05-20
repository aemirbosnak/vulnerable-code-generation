//Code Llama-13B DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <stdbool.h>

#define LIGHT_ON 0
#define LIGHT_OFF 1

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[256];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to the server\n");

    while (1) {
        n = read(sockfd, buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        buffer[n] = 0;
        printf("Server: %s\n", buffer);

        if (strcmp(buffer, "light on") == 0) {
            printf("Light is on\n");
        } else if (strcmp(buffer, "light off") == 0) {
            printf("Light is off\n");
        }

        memset(buffer, 0, 256);
    }

    close(sockfd);

    return 0;
}