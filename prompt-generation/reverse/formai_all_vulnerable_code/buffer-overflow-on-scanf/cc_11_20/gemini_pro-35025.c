//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUFF_SIZE];
  char username[BUFF_SIZE];
  char password[BUFF_SIZE];
  char command[BUFF_SIZE];

  if (argc < 4) {
    fprintf(stderr, "usage: %s <server> <port> <username> <password>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "error: no such host %s\n", argv[1]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("error: failed to create socket");
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("error: failed to connect to server");
    exit(1);
  }

  memset(buffer, 0, BUFF_SIZE);
  if (recv(sockfd, buffer, BUFF_SIZE, 0) < 0) {
    perror("error: failed to receive data from server");
    exit(1);
  }
  printf("%s", buffer);

  memset(username, 0, BUFF_SIZE);
  strcpy(username, argv[3]);

  sprintf(command, "USER %s\r\n", username);
  if (send(sockfd, command, strlen(command), 0) < 0) {
    perror("error: failed to send data to server");
    exit(1);
  }

  memset(buffer, 0, BUFF_SIZE);
  if (recv(sockfd, buffer, BUFF_SIZE, 0) < 0) {
    perror("error: failed to receive data from server");
    exit(1);
  }
  printf("%s", buffer);

  memset(password, 0, BUFF_SIZE);
  strcpy(password, argv[4]);

  sprintf(command, "PASS %s\r\n", password);
  if (send(sockfd, command, strlen(command), 0) < 0) {
    perror("error: failed to send data to server");
    exit(1);
  }

  memset(buffer, 0, BUFF_SIZE);
  if (recv(sockfd, buffer, BUFF_SIZE, 0) < 0) {
    perror("error: failed to receive data from server");
    exit(1);
  }
  printf("%s", buffer);

  while (1) {
    memset(command, 0, BUFF_SIZE);
    printf("Enter a command (QUIT to exit): ");
    scanf("%s", command);

    if (strcmp(command, "QUIT") == 0) {
      break;
    }

    if (send(sockfd, command, strlen(command), 0) < 0) {
      perror("error: failed to send data to server");
      exit(1);
    }

    memset(buffer, 0, BUFF_SIZE);
    if (recv(sockfd, buffer, BUFF_SIZE, 0) < 0) {
      perror("error: failed to receive data from server");
      exit(1);
    }
    printf("%s", buffer);
  }

  close(sockfd);
  return 0;
}