//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define POP3_PORT 110

int main(int argc, char **argv) {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server> <username> [<password>]\n", argv[0]);
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error: no such host\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error: opening socket");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(POP3_PORT);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error: connecting");
    exit(1);
  }

  char buffer[256];
  n = read(sockfd, buffer, 255);
  if (n < 0) {
    perror("Error: reading from socket");
    exit(1);
  }

  printf("%s", buffer);

  // Send the username
  sprintf(buffer, "USER %s\r\n", argv[2]);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error: writing to socket");
    exit(1);
  }

  n = read(sockfd, buffer, 255);
  if (n < 0) {
    perror("Error: reading from socket");
    exit(1);
  }

  printf("%s", buffer);

  // Send the password
  if (argc == 4) {
    sprintf(buffer, "PASS %s\r\n", argv[3]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
      perror("Error: writing to socket");
      exit(1);
    }

    n = read(sockfd, buffer, 255);
    if (n < 0) {
      perror("Error: reading from socket");
      exit(1);
    }
    printf("%s", buffer);
  }

  // Send the LIST command
  strcpy(buffer, "LIST\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error: writing to socket");
    exit(1);
  }

  // Receive the list of messages
  while (1) {
    n = read(sockfd, buffer, 255);
    if (n < 0) {
      perror("Error: reading from socket");
      exit(1);
    }
    if (n == 0) {
      break;
    }
    printf("%s", buffer);
  }

  // Send the QUIT command
  strcpy(buffer, "QUIT\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error: writing to socket");
    exit(1);
  }

  close(sockfd);

  return 0;
}