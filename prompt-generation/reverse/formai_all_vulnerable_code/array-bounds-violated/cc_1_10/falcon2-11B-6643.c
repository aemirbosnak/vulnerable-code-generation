//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 110

int main() {
    int sockfd, valread;
    struct hostent *server;
    struct sockaddr_in serveraddr;
    char buffer[256];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    // Resolve server address
    server = gethostbyname("mail.example.com");
    if (server == NULL) {
        fprintf(stderr, "Hostname could not be resolved\n");
        exit(1);
    }

    // Store server address
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Login
    printf("Username: ");
    fgets(buffer, 256, stdin);
    send(sockfd, buffer, strlen(buffer), 0);

    // Retrieve mail
    while (1) {
        bzero(buffer, 256);
        valread = recv(sockfd, buffer, 255, 0);
        if (valread < 0) {
            perror("recv failed");
            exit(1);
        }
        printf("%s", buffer);
        printf("\n");
        if (buffer[strlen(buffer) - 1] == '\n') {
            break;
        }
    }

    // Close socket
    close(sockfd);

    return 0;
}