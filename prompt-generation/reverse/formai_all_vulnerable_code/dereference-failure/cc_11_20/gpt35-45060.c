//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

void error(const char *msg) {
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[MAX_BUF_SIZE];

  if (argc < 3) {
    fprintf(stderr,"usage %s hostname port\n", argv[0]);
    exit(0);
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    error("ERROR opening socket");
  }

  server = gethostbyname(argv[1]);

  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
    error("ERROR connecting");
  }

  char *mailer = "smtp.gmail.com";
  char *user = "example@gmail.com";
  char *password = "password1234";
  char *recipients = "recipient@example.com";
  char *subject = "Hello from SMTP client";
  char *body = "This is a test email sent using the SMTP client program.";

  char message[MAX_BUF_SIZE];
  bzero(message,MAX_BUF_SIZE);

  // SMTP handshake
  n = read(sockfd,buffer,MAX_BUF_SIZE-1);
  if (n < 0) {
    error("ERROR reading from socket");
  }
  printf("%s\n",buffer);

  sprintf(message, "EHLO %s\r\n", mailer);
  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    error("ERROR writing to socket");
  }

  // AUTH LOGIN command
  bzero(buffer,MAX_BUF_SIZE);
  n = read(sockfd,buffer,MAX_BUF_SIZE-1);
  if (n < 0) {
    error("ERROR reading from socket");
  }
  printf("%s\n",buffer);

  sprintf(message, "AUTH LOGIN\r\n");
  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    error("ERROR writing to socket");
  }

  // Send base64 encoded user name
  bzero(buffer,MAX_BUF_SIZE);
  n = read(sockfd,buffer,MAX_BUF_SIZE-1);
  if (n < 0) {
    error("ERROR reading from socket");
  }
  printf("%s\n",buffer);

  sprintf(message, "%s\r\n", user);
  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    error("ERROR writing to socket");
  }

  // Send base64 encoded password
  bzero(buffer,MAX_BUF_SIZE);
  n = read(sockfd,buffer,MAX_BUF_SIZE-1);
  if (n < 0) {
    error("ERROR reading from socket");
  }
  printf("%s\n",buffer);

  sprintf(message, "%s\r\n", password);
  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    error("ERROR writing to socket");
  }

  // MAIL FROM command
  bzero(buffer,MAX_BUF_SIZE);
  n = read(sockfd,buffer,MAX_BUF_SIZE-1);
  if (n < 0) {
    error("ERROR reading from socket");
  }
  printf("%s\n",buffer);

  sprintf(message, "MAIL FROM: <%s>\r\n", user);
  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    error("ERROR writing to socket");
  }

  // RCPT TO command
  bzero(buffer,MAX_BUF_SIZE);
  n = read(sockfd,buffer,MAX_BUF_SIZE-1);
  if (n < 0) {
    error("ERROR reading from socket");
  }
  printf("%s\n",buffer);

  sprintf(message, "RCPT TO: <%s>\r\n", recipients);
  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    error("ERROR writing to socket");
  }

  // DATA command
  bzero(buffer,MAX_BUF_SIZE);
  n = read(sockfd,buffer,MAX_BUF_SIZE-1);
  if (n < 0) {
    error("ERROR reading from socket");
  }
  printf("%s\n",buffer);

  sprintf(message, "DATA\r\n");
  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    error("ERROR writing to socket");
  }

  // Send email headers and body
  bzero(buffer,MAX_BUF_SIZE);
  n = read(sockfd,buffer,MAX_BUF_SIZE-1);
  if (n < 0) {
    error("ERROR reading from socket");
  }
  printf("%s\n",buffer);

  sprintf(message, "To: <%s>\r\n", recipients);
  strcat(message, "From: SMTP Client <");
  strcat(message, user);
  strcat(message, ">\r\n");
  strcat(message, "Subject: ");
  strcat(message, subject);
  strcat(message, "\r\n\r\n");
  strcat(message, body);
  strcat(message, "\r\n.\r\n");

  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    error("ERROR writing to socket");
  }

  // QUIT command
  bzero(buffer,MAX_BUF_SIZE);
  n = read(sockfd,buffer,MAX_BUF_SIZE-1);
  if (n < 0) {
    error("ERROR reading from socket");
  }
  printf("%s\n",buffer);

  sprintf(message, "QUIT\r\n");
  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    error("ERROR writing to socket");
  }

  printf("Email sent successfully\n");

  close(sockfd);
  return 0;
}