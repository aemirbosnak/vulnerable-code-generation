//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 143
#define MAXDATASIZE 1000

int main(int argc, char *argv[]) {
  struct addrinfo hints, *server_info, *p;
  int sockfd, n;
  struct sockaddr_in server_addr;
  char recv_buf[MAXDATASIZE];

  if (argc != 2) {
    fprintf(stderr, "usage: %s <server_ip>\n", argv[0]);
    exit(1);
  }

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  if ((n = getaddrinfo(argv[1], PORT, &hints, &server_info)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(n));
    exit(1);
  }

  for (p = server_info; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
      perror("socket");
      continue;
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
      perror("connect");
      continue;
    }

    break;
  }

  if (p == NULL) {
    fprintf(stderr, "failed to connect\n");
    exit(1);
  }

  freeaddrinfo(server_info);

  while (1) {
    printf("Enter message: ");
    fgets(recv_buf, MAXDATASIZE, stdin);
    if (send(sockfd, recv_buf, strlen(recv_buf), 0) == -1) {
      perror("send");
      exit(1);
    }

    if (recv(sockfd, recv_buf, MAXDATASIZE, 0) == -1) {
      perror("recv");
      exit(1);
    }

    printf("Server response: %s\n", recv_buf);
  }

  close(sockfd);

  return 0;
}