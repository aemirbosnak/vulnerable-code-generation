//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define POP3_PORT 110

int main(int argc, char *argv[])
{
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error: no such host\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error: socket");
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(POP3_PORT);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error: connect");
    exit(1);
  }

  n = read(sockfd, buffer, 255);
  if (n < 0) {
    perror("Error: read");
    exit(1);
  }

  printf("%s", buffer);

  memset(buffer, 0, 256);
  sprintf(buffer, "USER %s\r\n", argv[2]);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error: write");
    exit(1);
  }

  n = read(sockfd, buffer, 255);
  if (n < 0) {
    perror("Error: read");
    exit(1);
  }

  printf("%s", buffer);

  memset(buffer, 0, 256);
  sprintf(buffer, "PASS %s\r\n", argv[3]);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error: write");
    exit(1);
  }

  n = read(sockfd, buffer, 255);
  if (n < 0) {
    perror("Error: read");
    exit(1);
  }

  printf("%s", buffer);

  memset(buffer, 0, 256);
  sprintf(buffer, "LIST\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error: write");
    exit(1);
  }

  n = read(sockfd, buffer, 255);
  if (n < 0) {
    perror("Error: read");
    exit(1);
  }

  printf("%s", buffer);

  memset(buffer, 0, 256);
  sprintf(buffer, "QUIT\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error: write");
    exit(1);
  }

  close(sockfd);

  return 0;
}