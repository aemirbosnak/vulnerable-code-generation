//Falcon-180B DATASET v1.0 Category: Networking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, portno = 8080;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int n;
    struct hostent *server;
    char *host;

    if(argc < 2) {
        printf("Error : Please provide a valid IP address\n");
        exit(0);
    }

    host = argv[1];

    server = gethostbyname(host);

    if(server == NULL) {
        printf("Error : No such host found\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error : Could not create socket\n");
        exit(0);
    }

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error : Could not connect to the server\n");
        exit(0);
    }

    while(1) {
        bzero(buffer, 1024);
        n = read(sockfd, buffer, 1024);
        if(n < 0) {
            printf("Error : Could not read from the server\n");
            exit(0);
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    exit(0);
}