//FormAI DATASET v1.0 Category: Networking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
  struct addrinfo hints;
  struct addrinfo* result, * rp;
  int sockfd, s, flags, nread, nwritten;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  s = getaddrinfo(argv[1], argv[2], &hints, &result);
  if (s != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
    exit(EXIT_FAILURE);
  }

  for (rp = result; rp != NULL; rp = rp->ai_next) {
    sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sockfd == -1) {
      continue;
    }

    if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1) {
      break;
    }

    close(sockfd);
  }

  if (rp == NULL) {
    fprintf(stderr, "Could not connect\n");
    exit(EXIT_FAILURE);
  }

  freeaddrinfo(result);
  
  printf("Connected to %s:%s\n", argv[1], argv[2]);

  // Set socket to non-blocking
  flags = fcntl(sockfd, F_GETFL, 0);
  if (flags == -1) {
    perror("fcntl");
    exit(EXIT_FAILURE);
  }
  if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
    perror("fcntl");
    exit(EXIT_FAILURE);
  }

  char buffer[MAX_BUFFER_SIZE];
  memset(&buffer, 0, MAX_BUFFER_SIZE);

  fd_set read_fds;
  FD_ZERO(&read_fds);
  FD_SET(sockfd, &read_fds);
  int max_fd = sockfd + 1;

  while (1) {
    if (select(max_fd, &read_fds, NULL, NULL, NULL) == -1) {
      perror("select");
      exit(EXIT_FAILURE);
    }

    if (FD_ISSET(sockfd, &read_fds)) {
      nread = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
      if (nread == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
      }
      else if (nread == 0) {
        printf("Connection closed by server\n");
        break;
      }
      printf("%.*s", nread, buffer);
      memset(&buffer, 0, MAX_BUFFER_SIZE);
    }

    if (fgets(buffer, MAX_BUFFER_SIZE, stdin) != NULL) {
      nwritten = send(sockfd, buffer, strlen(buffer), 0);
      if (nwritten == -1) {
        perror("send");
        exit(EXIT_FAILURE);
      }
      memset(&buffer, 0, MAX_BUFFER_SIZE);
    }

    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);
  }

  close(sockfd);
  printf("Disconnected from %s:%s\n", argv[1], argv[2]);

  exit(EXIT_SUCCESS);
}