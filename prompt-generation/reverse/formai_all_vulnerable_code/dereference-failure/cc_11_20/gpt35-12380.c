//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"error, no such host\n");
        exit(0);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("error connecting");
        exit(1);
    }

    n = read(sockfd,buffer,BUFFER_SIZE);

    if (n < 0) {
        perror("error reading from socket");
        exit(1);
    }

    printf("%s\n",buffer);

    char userinput[BUFFER_SIZE];
    memset(userinput, 0, sizeof(userinput));

    printf("Enter username: ");
    fgets(userinput, BUFFER_SIZE, stdin);
    strtok(userinput, "\n");

    char message[BUFFER_SIZE];
    sprintf(message, "USER %s\r\n", userinput);
    write(sockfd,message,strlen(message));

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE);

    if (n < 0) {
        perror("error reading from socket");
        exit(1);
    }

    printf("%s\n",buffer);

    memset(userinput, 0, BUFFER_SIZE);

    printf("Enter password: ");
    fgets(userinput, BUFFER_SIZE, stdin);
    strtok(userinput, "\n");

    memset(message, 0, BUFFER_SIZE);
    sprintf(message, "PASS %s\r\n", userinput);
    write(sockfd,message,strlen(message));

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE);

    if (n < 0) {
        perror("error reading from socket");
        exit(1);
    }

    printf("%s\n",buffer);

    memset(message, 0, BUFFER_SIZE);

    sprintf(message, "LIST\r\n");
    write(sockfd,message,strlen(message));

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE);

    if (n < 0) {
        perror("error reading from socket");
        exit(1);
    }

    printf("%s\n",buffer);

    memset(message, 0, BUFFER_SIZE);

    printf("Enter email number (or type 'quit' to exit): ");
    fgets(userinput, BUFFER_SIZE, stdin);
    strtok(userinput, "\n");

    if (strcmp(userinput, "quit") == 0) {
        close(sockfd);
        exit(0);
    }

    sprintf(message, "RETR %s\r\n", userinput);
    write(sockfd,message,strlen(message));

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE);

    if (n < 0) {
        perror("error reading from socket");
        exit(1);
    }

    printf("%s\n",buffer);

    close(sockfd);

    return 0;
}