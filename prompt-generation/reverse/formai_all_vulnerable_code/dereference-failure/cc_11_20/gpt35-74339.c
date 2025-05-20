//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define PORT 25
#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[MAX_BUFFER];
  if(argc < 2) {
    fprintf(stderr,"usage %s hostname\n", argv[0]);
    exit(0);
  }

  /* create a socket */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  /* get host by name */
  server = gethostbyname(argv[1]);
  if(server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(0);
  }

  /* set server address */
  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = PORT;
  serv_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr,
        (char *) &serv_addr.sin_addr.s_addr,
        server->h_length);
  serv_addr.sin_port = htons(portno);

  /* connect to server */
  if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  /* read server welcome message */
  bzero(buffer, MAX_BUFFER);
  n = read(sockfd, buffer, MAX_BUFFER - 1);
  if(n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  fprintf(stdout,"%s", buffer);

  /* read server response after sending helo */
  char* helo = "HELO test\r\n";
  bzero(buffer, MAX_BUFFER);
  n = write(sockfd, helo, strlen(helo));
  if(n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  n = read(sockfd, buffer, MAX_BUFFER - 1);
  if(n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  fprintf(stdout,"%s", buffer);

  /* send email */
  char* sender = "MAIL FROM:<test@test.com>\r\n";
  bzero(buffer, MAX_BUFFER);
  n = write(sockfd, sender, strlen(sender));
  if(n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  n = read(sockfd, buffer, MAX_BUFFER - 1);
  if(n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  fprintf(stdout,"%s", buffer);

  /* send recipient */
  char* recipient = "RCPT TO:<recipient@test.com>\r\n";
  bzero(buffer, MAX_BUFFER);
  n = write(sockfd, recipient, strlen(recipient));
  if(n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  n = read(sockfd, buffer, MAX_BUFFER - 1);
  if(n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  fprintf(stdout,"%s", buffer);

  /* send data */
  char* data = "DATA\r\n";
  bzero(buffer, MAX_BUFFER);
  n = write(sockfd, data, strlen(data));
  if(n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  n = read(sockfd, buffer, MAX_BUFFER - 1);
  if(n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  fprintf(stdout,"%s", buffer);

  /* send email body */
  char* email = "Subject: Test email\nThis is a test email\n.\r\n";
  bzero(buffer, MAX_BUFFER);
  n = write(sockfd, email, strlen(email));
  if(n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  n = read(sockfd, buffer, MAX_BUFFER - 1);
  if(n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  fprintf(stdout,"%s", buffer);

  /* quit */
  char* quit = "QUIT\r\n";
  bzero(buffer, MAX_BUFFER);
  n = write(sockfd, quit, strlen(quit));
  if(n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  n = read(sockfd, buffer, MAX_BUFFER - 1);
  if(n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  fprintf(stdout,"%s", buffer);

  /* close the socket */
  close(sockfd);

  return 0;
}