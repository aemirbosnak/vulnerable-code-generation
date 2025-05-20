//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define MAXDATASIZE 100

int main(int argc, char *argv[]) {
  int sockfd, n;
  char buffer[MAXDATASIZE];
  struct sockaddr_in serv_addr;
  struct hostent *server;

  if (argc != 2) {
    fprintf(stderr, "usage: %s <hostname>\n", argv[0]);
    exit(0);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(0);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "ERROR opening socket\n");
    exit(0);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(PORT);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "ERROR connecting\n");
    exit(0);
  }

  while (1) {
    printf("Enter the command: ");
    fgets(buffer, MAXDATASIZE, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
      fprintf(stderr, "ERROR writing to socket\n");
      exit(0);
    }

    n = read(sockfd, buffer, MAXDATASIZE);
    if (n < 0) {
      fprintf(stderr, "ERROR reading from socket\n");
      exit(0);
    }
    printf("%s", buffer);
  }

  return 0;
}