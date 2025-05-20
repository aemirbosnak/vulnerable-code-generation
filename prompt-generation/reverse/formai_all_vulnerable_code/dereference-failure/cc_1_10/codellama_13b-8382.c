//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  int sockfd, new_sockfd, portno, clilen, n, pid;
  struct sockaddr_in server_addr, client_addr;
  char buffer[256];

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  portno = atoi(argv[1]);

  memset((char *) &server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  listen(sockfd, 5);
  clilen = sizeof(client_addr);

  while (1) {
    new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &clilen);
    if (new_sockfd < 0) {
      perror("ERROR on accept");
      exit(1);
    }

    pid = fork();
    if (pid < 0) {
      perror("ERROR on fork");
      exit(1);
    }

    if (pid == 0) {
      close(sockfd);

      n = recv(new_sockfd, buffer, 256, 0);
      if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
      }

      printf("Client message: %s\n", buffer);

      n = write(new_sockfd, "Hello, client!", 14);
      if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
      }

      close(new_sockfd);
      exit(0);
    }

    close(new_sockfd);
  }

  return 0;
}