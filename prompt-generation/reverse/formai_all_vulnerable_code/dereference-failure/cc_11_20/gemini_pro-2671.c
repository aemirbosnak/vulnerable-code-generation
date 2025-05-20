//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
  int sockfd;
  struct sockaddr_in servaddr;

  if (argc != 4)
  {
    fprintf(stderr, "usage: %s <server IP address> <port> <message>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
  {
    perror("socket");
    exit(1);
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
  {
    perror("inet_pton");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
  {
    perror("connect");
    exit(1);
  }

  char buffer[MAX_LINE];
  sprintf(buffer, "HELO %s\r\n", "localhost");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0)
  {
    perror("send");
    exit(1);
  }

  if (recv(sockfd, buffer, MAX_LINE, 0) < 0)
  {
    perror("recv");
    exit(1);
  }

  sprintf(buffer, "MAIL FROM: <romeo@localhost>\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0)
  {
    perror("send");
    exit(1);
  }

  if (recv(sockfd, buffer, MAX_LINE, 0) < 0)
  {
    perror("recv");
    exit(1);
  }

  sprintf(buffer, "RCPT TO: <juliet@localhost>\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0)
  {
    perror("send");
    exit(1);
  }

  if (recv(sockfd, buffer, MAX_LINE, 0) < 0)
  {
    perror("recv");
    exit(1);
  }

  sprintf(buffer, "DATA\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0)
  {
    perror("send");
    exit(1);
  }

  if (recv(sockfd, buffer, MAX_LINE, 0) < 0)
  {
    perror("recv");
    exit(1);
  }

  sprintf(buffer, "%s\r\n.\r\n", argv[3]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0)
  {
    perror("send");
    exit(1);
  }

  if (recv(sockfd, buffer, MAX_LINE, 0) < 0)
  {
    perror("recv");
    exit(1);
  }

  sprintf(buffer, "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0)
  {
    perror("send");
    exit(1);
  }

  if (recv(sockfd, buffer, MAX_LINE, 0) < 0)
  {
    perror("recv");
    exit(1);
  }

  close(sockfd);
  return 0;
}