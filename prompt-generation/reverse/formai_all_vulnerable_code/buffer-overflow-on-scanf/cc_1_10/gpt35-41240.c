//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void main()
{
    int sockfd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[4096];

    printf("Welcome to the POP3 Client program with a surreal touch.\n");
    printf("Please enter the POP3 server hostname: ");
    scanf("%s", buffer);
    server = gethostbyname(buffer);

    if (server == NULL) {
        fprintf(stderr, "ERROR: Invalid hostname.\n");
        exit(0);
    }

    printf("Please enter the POP3 server port number: ");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        perror("ERROR: Could not open socket.\n");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        perror("ERROR: Could not connect.\n");

    printf("POP3 server connected, Say something!\n");

    while (fgets(buffer, 4096, stdin)) {
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0)
            perror("ERROR: Could not write to socket.\n");

        bzero(buffer, 4096);

        n = read(sockfd, buffer, 4096);
        if (n < 0)
            perror("ERROR: Could not read from socket.\n");

        printf("%s\n", buffer);
    }
    
    close(sockfd);
}