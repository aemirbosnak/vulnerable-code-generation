//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];

    // Shocking pop3 client
    if (argc < 2) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to POP3 server on %s:%s\n", argv[1], argv[2]);

    // Shocking POP3 commands
    printf("Please enter your POP3 username: ");
    fflush(stdout);
    gets(buffer);

    printf("Please enter your POP3 password: ");
    fflush(stdout);
    gets(buffer);

    printf("Logging in...\n");
    send(sockfd, buffer, strlen(buffer), 0);
    fflush(stdout);
    bzero(buffer, sizeof(buffer));

    printf("Please enter your POP3 command: ");
    fflush(stdout);
    gets(buffer);

    printf("Sending command...\n");
    send(sockfd, buffer, strlen(buffer), 0);
    fflush(stdout);
    bzero(buffer, sizeof(buffer));

    bzero(buffer, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("ERROR receiving data");
        exit(1);
    }

    printf("Server response: %s\n", buffer);

    close(sockfd);
    return 0;
}