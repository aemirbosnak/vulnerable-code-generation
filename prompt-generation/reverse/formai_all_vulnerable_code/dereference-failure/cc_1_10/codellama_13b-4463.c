//Code Llama-13B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[MAX_BUFFER_SIZE];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  server = gethostbyname(argv[1]);

  if (server == NULL) {
    fprintf(stderr, "Error, no such host\n");
    exit(1);
  }

  memset((char *) &serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting");
    exit(1);
  }

  while (1) {
    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);

    if (n < 0) {
      perror("Error reading from socket");
      exit(1);
    }

    if (n == 0) {
      printf("Connection closed by server\n");
      break;
    }

    printf("Received %d bytes: %s\n", n, buffer);
  }

  close(sockfd);

  return 0;
}