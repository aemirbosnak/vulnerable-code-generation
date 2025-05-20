//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
  int sockfd, n;
  char recvbuf[1024];
  struct sockaddr_in serv_addr;
  struct hostent *server;

  if (argc < 3) {
    fprintf(stderr, "usage: %s hostname port\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("ERROR opening socket");

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2]));
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR connecting");

  printf("Please enter the message: ");
  bzero(recvbuf, 1024);
  fgets(recvbuf, 1024, stdin);
  n = write(sockfd, recvbuf, strlen(recvbuf));
  if (n < 0)
    error("ERROR writing to socket");

  bzero(recvbuf, 1024);
  n = read(sockfd, recvbuf, 1024);
  if (n < 0)
    error("ERROR reading from socket");

  printf("%s\n", recvbuf);

  close(sockfd);
  return 0;
}