//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/stat.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buffer[1024], command[1024];
    FILE *fp;

    printf("Enter server name or IP address: ");
    scanf("%s", &command);

    printf("Enter port number: ");
    scanf("%d", &portno);

    server = gethostbyname(command);
    if (server == NULL) {
        fprintf(stderr, "Unknown host\n");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "ERROR connecting\n");
        exit(1);
    }

    sprintf(buffer, "USER anonymous\r\n");
    write(sockfd, buffer, strlen(buffer));

    sprintf(buffer, "PASS anonymous@\r\n");
    write(sockfd, buffer, strlen(buffer));

    sprintf(buffer, "PWD\r\n");
    write(sockfd, buffer, strlen(buffer));

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        exit(1);
    }

    printf("%s\n", buffer);

    sprintf(buffer, "LIST\r\n");
    write(sockfd, buffer, strlen(buffer));

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        exit(1);
    }

    printf("%s\n", buffer);

    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "ERROR opening output file\n");
        exit(1);
    }

    fputs(buffer, fp);

    fclose(fp);

    close(sockfd);

    return 0;
}