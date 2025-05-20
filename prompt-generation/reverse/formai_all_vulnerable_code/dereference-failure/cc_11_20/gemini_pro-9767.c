//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 143
#define BUFFSIZE 1024

int main(int argc, char **argv) {
  struct sockaddr_in server_addr;
  int sockfd, n;
  char buffer[BUFFSIZE];

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "Error: could not resolve hostname: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error: could not create socket\n");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    fprintf(stderr, "Error: could not connect to server\n");
    exit(EXIT_FAILURE);
  }

  n = read(sockfd, buffer, BUFFSIZE);
  if (n < 0) {
    fprintf(stderr, "Error: could not read from socket\n");
    exit(EXIT_FAILURE);
  }
  printf("Server: %s\n", buffer);

  snprintf(buffer, BUFFSIZE, "A LOGIN %s\r\n", argv[2]);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    fprintf(stderr, "Error: could not write to socket\n");
    exit(EXIT_FAILURE);
  }

  n = read(sockfd, buffer, BUFFSIZE);
  if (n < 0) {
    fprintf(stderr, "Error: could not read from socket\n");
    exit(EXIT_FAILURE);
  }
  printf("Server: %s\n", buffer);

  snprintf(buffer, BUFFSIZE, "A NOOP\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    fprintf(stderr, "Error: could not write to socket\n");
    exit(EXIT_FAILURE);
  }

  n = read(sockfd, buffer, BUFFSIZE);
  if (n < 0) {
    fprintf(stderr, "Error: could not read from socket\n");
    exit(EXIT_FAILURE);
  }
  printf("Server: %s\n", buffer);

  snprintf(buffer, BUFFSIZE, "A LOGOUT\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    fprintf(stderr, "Error: could not write to socket\n");
    exit(EXIT_FAILURE);
  }

  n = read(sockfd, buffer, BUFFSIZE);
  if (n < 0) {
    fprintf(stderr, "Error: could not read from socket\n");
    exit(EXIT_FAILURE);
  }
  printf("Server: %s\n", buffer);

  close(sockfd);

  return EXIT_SUCCESS;
}