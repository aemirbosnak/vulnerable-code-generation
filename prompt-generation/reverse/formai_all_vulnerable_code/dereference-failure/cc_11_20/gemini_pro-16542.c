//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUFSIZE];
  int n;

  if (argc < 3) {
    fprintf(stderr,"Usage: %s <server> <port>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr,"ERROR opening socket\n");
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
    fprintf(stderr,"ERROR connecting\n");
    exit(1);
  }

  bzero(buffer,BUFSIZE);
  n = read(sockfd,buffer,BUFSIZE);
  if (n < 0) {
    fprintf(stderr,"ERROR reading from socket\n");
    exit(1);
  }

  printf("%s\n",buffer);

  bzero(buffer,BUFSIZE);
  sprintf(buffer,"A001 LOGIN user@example.com password\r\n");
  n = write(sockfd,buffer,strlen(buffer));
  if (n < 0) {
    fprintf(stderr,"ERROR writing to socket\n");
    exit(1);
  }

  bzero(buffer,BUFSIZE);
  n = read(sockfd,buffer,BUFSIZE);
  if (n < 0) {
    fprintf(stderr,"ERROR reading from socket\n");
    exit(1);
  }

  printf("%s\n",buffer);

  bzero(buffer,BUFSIZE);
  sprintf(buffer,"A002 LIST \"\" *\r\n");
  n = write(sockfd,buffer,strlen(buffer));
  if (n < 0) {
    fprintf(stderr,"ERROR writing to socket\n");
    exit(1);
  }

  bzero(buffer,BUFSIZE);
  n = read(sockfd,buffer,BUFSIZE);
  if (n < 0) {
    fprintf(stderr,"ERROR reading from socket\n");
    exit(1);
  }

  printf("%s\n",buffer);

  bzero(buffer,BUFSIZE);
  sprintf(buffer,"A003 SELECT Inbox\r\n");
  n = write(sockfd,buffer,strlen(buffer));
  if (n < 0) {
    fprintf(stderr,"ERROR writing to socket\n");
    exit(1);
  }

  bzero(buffer,BUFSIZE);
  n = read(sockfd,buffer,BUFSIZE);
  if (n < 0) {
    fprintf(stderr,"ERROR reading from socket\n");
    exit(1);
  }

  printf("%s\n",buffer);

  bzero(buffer,BUFSIZE);
  sprintf(buffer,"A004 FETCH 1 BODY[TEXT]\r\n");
  n = write(sockfd,buffer,strlen(buffer));
  if (n < 0) {
    fprintf(stderr,"ERROR writing to socket\n");
    exit(1);
  }

  bzero(buffer,BUFSIZE);
  n = read(sockfd,buffer,BUFSIZE);
  if (n < 0) {
    fprintf(stderr,"ERROR reading from socket\n");
    exit(1);
  }

  printf("%s\n",buffer);

  close(sockfd);

  return 0;
}