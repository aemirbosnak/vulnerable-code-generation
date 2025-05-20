//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXDATASIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, numbytes;
  char buf[MAXDATASIZE];
  struct hostent *he;
  struct sockaddr_in their_addr;

  if (argc != 4) {
    fprintf(stderr,"usage: smtp_client hostname port from_email\n");
    exit(1);
  }

  if ((he=gethostbyname(argv[1])) == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }

  their_addr.sin_family = AF_INET;
  their_addr.sin_port = htons(atoi(argv[2]));
  their_addr.sin_addr = *((struct in_addr *)he->h_addr);
  memset(&(their_addr.sin_zero), '\0', 8);

  if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
    perror("connect");
    exit(1);
  }

  numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
  if (numbytes == -1) {
    perror("recv");
    exit(1);
  }

  buf[numbytes] = '\0';
  printf("Received: %s",buf);

  char command[MAXDATASIZE];
  sprintf(command, "EHLO %s\n", argv[1]);
  if (send(sockfd, command, strlen(command), 0) == -1) {
    perror("send");
    exit(1);
  }
  
  numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
  if (numbytes == -1) {
    perror("recv");
    exit(1);
  }
  buf[numbytes] = '\0';
  printf("Received: %s",buf);

  char mail_from[MAXDATASIZE];
  sprintf(mail_from, "MAIL FROM:<%s>\n", argv[3]);
  if (send(sockfd, mail_from, strlen(mail_from), 0) == -1) {
    perror("send");
    exit(1);
  }

  numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
  if (numbytes == -1) {
    perror("recv");
    exit(1);
  }
  buf[numbytes] = '\0';
  printf("Received: %s",buf);

  char rcpt_to[MAXDATASIZE];
  printf("Enter recipient email: ");
  scanf("%s", rcpt_to);
  sprintf(rcpt_to, "RCPT TO:<%s>\n", rcpt_to);
  if (send(sockfd, rcpt_to, strlen(rcpt_to), 0) == -1) {
    perror("send");
    exit(1);
  }

  numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
  if (numbytes == -1) {
    perror("recv");
    exit(1);
  }
  buf[numbytes] = '\0';
  printf("Received: %s",buf);

  char data[] = "DATA\n";
  if (send(sockfd, data, strlen(data), 0) == -1) {
    perror("send");
    exit(1);
  }

  numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
  if (numbytes == -1) {
    perror("recv");
    exit(1);
  }
  buf[numbytes] = '\0';
  printf("Received: %s",buf);

  printf("Enter email message (end with '.' on a line by itself):\n");
  char message[MAXDATASIZE];
  while (fgets(buf, MAXDATASIZE, stdin)) {
    if (buf[0] == '.' && buf[1] == '\n')
      break;
    strcat(message, buf);
  }

  if (send(sockfd, message, strlen(message), 0) == -1) {
    perror("send");
    exit(1);
  }

  char period[] = ".\n";
  if (send(sockfd, period, strlen(period), 0) == -1) {
    perror("send");
    exit(1);
  }

  numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
  if (numbytes == -1) {
    perror("recv");
    exit(1);
  }
  buf[numbytes] = '\0';
  printf("Received: %s",buf);

  char quit[] = "QUIT\n";
  if (send(sockfd, quit, strlen(quit), 0) == -1) {
    perror("send");
    exit(1);
  }

  numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
  if (numbytes == -1) {
    perror("recv");
    exit(1);
  }
  buf[numbytes] = '\0';
  printf("Received: %s",buf);

  close(sockfd);

  return 0;
}