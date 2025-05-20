//Code Llama-13B DATASET v1.0 Category: Networking ; Style: Romeo and Juliet
// Romeo and Juliet in C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in server, client;
  char *buffer = (char*) malloc(256);
  struct timeval tv;

  if (argc < 3) {
    fprintf(stderr, "usage %s hostname port\n", argv[0]);
    exit(0);
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Socket");
    exit(1);
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(argv[1]);
  server.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
    perror("Connect");
    exit(1);
  }

  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);
  if (n < 0) {
    perror("Read");
    exit(1);
  }

  printf("Server: %s\n", buffer);

  // Send message
  char *message = "Hello, Romeo!";
  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    perror("Write");
    exit(1);
  }

  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);
  if (n < 0) {
    perror("Read");
    exit(1);
  }

  printf("Server: %s\n", buffer);

  // Send message
  message = "Goodbye, Juliet!";
  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    perror("Write");
    exit(1);
  }

  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);
  if (n < 0) {
    perror("Read");
    exit(1);
  }

  printf("Server: %s\n", buffer);

  close(sockfd);

  return 0;
}