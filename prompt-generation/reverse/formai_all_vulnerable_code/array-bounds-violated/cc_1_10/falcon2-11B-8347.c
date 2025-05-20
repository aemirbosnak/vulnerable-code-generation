//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting\n");
        exit(1);
    }

    char buffer[1024];
    while (1) {
        int bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_read < 0) {
            fprintf(stderr, "Error reading from socket\n");
            exit(1);
        }
        buffer[bytes_read] = '\0';
        printf("%s\n", buffer);

        char send_buffer[1024];
        sprintf(send_buffer, "Hello, World!\n");
        send(sockfd, send_buffer, strlen(send_buffer), 0);
    }

    close(sockfd);
    return 0;
}