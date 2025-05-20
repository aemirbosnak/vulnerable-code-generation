//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define SMTP_PORT 25 // port for SMTP

int main(int argc, char *argv[]) {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];

  if(argc < 3) {
    fprintf(stderr,"usage %s hostname message\n", argv[0]);
    exit(0);
  }

  // create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // get server IP address from hostname
  server = gethostbyname(argv[1]);
  if(server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }

  // initialize server address struct
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
  serv_addr.sin_port = htons(SMTP_PORT);

  // connect to SMTP server
  if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // read initial response from server
  bzero(buffer,256);
  n = read(sockfd, buffer, 255);
  printf("%s\n",buffer);

  // send HELO command to server
  char heloMessage[256];
  sprintf(heloMessage, "HELO %s\r\n", argv[1]);
  n = write(sockfd, heloMessage, strlen(heloMessage));
  if(n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // read response from server
  bzero(buffer,256);
  n = read(sockfd, buffer, 255);
  printf("%s\n",buffer);

  // send MAIL FROM command to server
  char mailFrom[256];
  sprintf(mailFrom, "MAIL FROM:<%s>\r\n", argv[1]);
  n = write(sockfd, mailFrom, strlen(mailFrom));
  if(n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // read response from server
  bzero(buffer,256);
  n = read(sockfd, buffer, 255);
  printf("%s\n",buffer);

  // send RCPT TO command to server
  char rcptTo[256];
  sprintf(rcptTo, "RCPT TO:<%s>\r\n", argv[2]);
  n = write(sockfd, rcptTo, strlen(rcptTo));
  if(n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // read response from server
  bzero(buffer,256);
  n = read(sockfd, buffer, 255);
  printf("%s\n",buffer);

  // send DATA command to server
  char dataMessage[256] = "DATA\r\n";
  n = write(sockfd, dataMessage, strlen(dataMessage));
  if(n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // read response from server
  bzero(buffer,256);
  n = read(sockfd, buffer, 255);
  printf("%s\n",buffer);

  // send message to server
  char *message = "Subject: SMTP Test\r\nThis is a test message sent from my SMTP client.\r\n.\r\n";
  n = write(sockfd, message, strlen(message));
  if(n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // read response from server
  bzero(buffer,256);
  n = read(sockfd, buffer, 255);
  printf("%s\n",buffer);

  // send QUIT command to server
  char quitMessage[256] = "QUIT\r\n";
  n = write(sockfd, quitMessage, strlen(quitMessage));
  if(n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // read response from server
  bzero(buffer,256);
  n = read(sockfd, buffer, 255);
  printf("%s\n",buffer);

  // close socket
  close(sockfd);
  return 0;
}