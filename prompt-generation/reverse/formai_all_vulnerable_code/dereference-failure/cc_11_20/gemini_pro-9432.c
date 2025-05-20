//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  struct hostent *server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error: could not find host %s\n", argv[1]);
    exit(1);
  }

  struct sockaddr_in serv_addr;
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
  serv_addr.sin_port = htons(atoi(argv[2]));

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
    perror("connect");
    exit(1);
  }

  printf("Connected to %s on port %s\n", argv[1], argv[2]);

  char buffer[256];
  bzero(buffer, 256);
  printf("Enter your email address: ");
  fgets(buffer, 256, stdin);

  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(1);
  }

  bzero(buffer, 256);
  printf("Enter your password: ");
  fgets(buffer, 256, stdin);

  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(1);
  }

  bzero(buffer, 256);
  printf("Enter the email address of the recipient: ");
  fgets(buffer, 256, stdin);

  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(1);
  }

  bzero(buffer, 256);
  printf("Enter the subject of the email: ");
  fgets(buffer, 256, stdin);

  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(1);
  }

  bzero(buffer, 256);
  printf("Enter the body of the email: ");
  fgets(buffer, 256, stdin);

  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(1);
  }

  bzero(buffer, 256);
  if (recv(sockfd, buffer, 256, 0) == -1) {
    perror("recv");
    exit(1);
  }

  printf("Server: %s\n", buffer);

  close(sockfd);

  return 0;
}