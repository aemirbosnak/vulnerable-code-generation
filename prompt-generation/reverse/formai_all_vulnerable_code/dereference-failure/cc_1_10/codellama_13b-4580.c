//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
  int sockfd, n;
  char buffer[MAX_LINE_LENGTH];
  struct sockaddr_in serv_addr;
  struct hostent *server;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
  (char *)&serv_addr.sin_addr.s_addr,
  server->h_length);
  serv_addr.sin_port = htons(atoi(argv[2]));

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  bzero(buffer, MAX_LINE_LENGTH);
  n = read(sockfd, buffer, MAX_LINE_LENGTH);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  printf("%s\n", buffer);

  close(sockfd);
  return 0;
}