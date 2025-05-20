//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SERVER_ADDR "ftp.server.com"

void error(char *msg) {
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 2) {
       fprintf(stderr,"usage %s hostname\n", argv[0]);
       exit(0);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(21);
    if (connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);
    n = write(sockfd, "USER username\r\n", strlen("USER username\r\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);
    n = write(sockfd, "PASS password\r\n", strlen("PASS password\r\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);
    n = write(sockfd, "PWD\r\n", strlen("PWD\r\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);
    n = write(sockfd, "TYPE I\r\n", strlen("TYPE I\r\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);
    n = write(sockfd, "PASV\r\n", strlen("PASV\r\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);
    int h1,h2,h3,h4,p1,p2;
    sscanf(buffer,"227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)",&h1,&h2,&h3,&h4,&p1,&p2);
    struct sockaddr_in transfer_addr = {0};
    transfer_addr.sin_family = AF_INET;
    char *ip = malloc(16);
    sprintf(ip,"%d.%d.%d.%d",h1,h2,h3,h4);
    inet_aton(ip,&transfer_addr.sin_addr);
    free(ip);
    transfer_addr.sin_port = htons((p1<<8)|p2);
    int datafd = socket(AF_INET,SOCK_STREAM,0);
    if(datafd < 0) error("ERROR opening socket");
    if(connect(datafd,(struct sockaddr*)&transfer_addr,sizeof(transfer_addr)) < 0) error("ERROR connecting data socket");
    printf("Connected to data socket..\n");
    n = write(sockfd, "RETR filename.txt\r\n", strlen("RETR filename.txt\r\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);
    FILE *output_file = fopen("downloaded_file.txt","wb");
    while((n=read(datafd,buffer,255)) > 0) {
        fwrite(buffer,1,n,output_file);
    }
    fclose(output_file);
    close(datafd);
    printf("File downloaded successfully..\n");
    n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);
    close(sockfd);
    return 0;
}