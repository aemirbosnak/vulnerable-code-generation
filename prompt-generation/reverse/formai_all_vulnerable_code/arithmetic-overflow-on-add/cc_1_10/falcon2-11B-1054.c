//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT_NUMBER 21
#define MAX_CONNECTIONS 10

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc!= 3) {
        printf("Usage: %s hostname portnumber\n", argv[0]);
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    printf("Connected to %s on port %d\n", argv[1], portno);

    for (;;) {
        send(sockfd, "HELLO WORLD\r\n", 12, 0);
        n = recv(sockfd, "HELLO WORLD\r\n", 12, 0);
        if (n == -1) {
            perror("Error receiving");
            exit(1);
        }
        printf("Received: %s\n", (char *)malloc(n+1));
        free(malloc(n+1));
    }

    close(sockfd);
    return 0;
}