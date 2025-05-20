//Code Llama-13B DATASET v1.0 Category: Client Server Application ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, n;
  char buffer[BUFSIZE];
  struct sockaddr_in server_addr;
  struct hostent *server;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(atoi(argv[2]));

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  while (1) {
    bzero(buffer, BUFSIZE);
    fgets(buffer, BUFSIZE, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
    }

    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE);
    if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
    }

    printf("%s\n", buffer);
  }

  close(sockfd);
  return 0;
}