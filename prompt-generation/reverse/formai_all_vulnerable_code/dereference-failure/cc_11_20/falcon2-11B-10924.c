//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char* argv[]) {
    struct sockaddr_in serverAddr;
    int sockfd, portno;
    struct hostent* server;
    char buffer[1024];
    int n;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serverAddr.sin_addr.s_addr, server->h_length);
    serverAddr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Enter 'quit' to exit\n");
    while (1) {
        printf("Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);
        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("ERROR sending data");
            exit(1);
        }
        if (strcmp(buffer, "quit") == 0) {
            break;
        }
    }

    printf("Enter 'quit' to exit\n");
    while (1) {
        bzero(buffer, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("ERROR receiving data");
            exit(1);
        }
        if (strcmp(buffer, "quit") == 0) {
            break;
        }
        printf("%s\n", buffer);
    }

    close(sockfd);
    exit(0);
}