//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: synchronous
/*
 * A simple chat server in synchronous style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MSG_LEN 1024

int main(int argc, char **argv) {
  int sockfd, new_sockfd, portno;
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[MAX_MSG_LEN];

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[1]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  memset((char *) &serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  listen(sockfd, 5);

  while (1) {
    clilen = sizeof(cli_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (new_sockfd < 0) {
      perror("Error accepting connection");
      continue;
    }

    while (1) {
      bzero(buffer, MAX_MSG_LEN);
      if (read(new_sockfd, buffer, MAX_MSG_LEN) < 0) {
        perror("Error reading from socket");
        break;
      }

      printf("Received message: %s\n", buffer);

      if (strncmp(buffer, "quit", 4) == 0) {
        printf("Client disconnected\n");
        break;
      }

      if (write(new_sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error writing to socket");
        break;
      }
    }

    close(new_sockfd);
  }

  close(sockfd);

  return 0;
}