//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[]) {
  char username[BUFFSIZE], password[BUFFSIZE], host[BUFFSIZE], port[BUFFSIZE];
  char *mail;
  int sockfd;
  char command[BUFFSIZE], response[BUFFSIZE];
  int ret;

  if (argc != 6) {
    fprintf(stderr, "Usage: %s username password host port mail\n", argv[0]);
    exit(1);
  }

  strcpy(username, argv[1]);
  strcpy(password, argv[2]);
  strcpy(host, argv[3]);
  strcpy(port, argv[4]);
  mail = argv[5];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
    exit(1);
  }

  struct hostent *he = gethostbyname(host);
  if (he == NULL) {
    fprintf(stderr, "Error resolving hostname: %s\n", strerror(errno));
    exit(1);
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(port));
  addr.sin_addr = *(struct in_addr *)he->h_addr_list[0];

  ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (ret == -1) {
    fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
    exit(1);
  }

  ret = recv(sockfd, response, BUFFSIZE, 0);
  if (ret == -1) {
    fprintf(stderr, "Error receiving data from server: %s\n", strerror(errno));
    exit(1);
  }
  fprintf(stdout, "%s", response);

  sprintf(command, "USER %s\r\n", username);
  ret = send(sockfd, command, strlen(command), 0);
  if (ret == -1) {
    fprintf(stderr, "Error sending data to server: %s\n", strerror(errno));
    exit(1);
  }
  ret = recv(sockfd, response, BUFFSIZE, 0);
  if (ret == -1) {
    fprintf(stderr, "Error receiving data from server: %s\n", strerror(errno));
    exit(1);
  }
  fprintf(stdout, "%s", response);

  sprintf(command, "PASS %s\r\n", password);
  ret = send(sockfd, command, strlen(command), 0);
  if (ret == -1) {
    fprintf(stderr, "Error sending data to server: %s\n", strerror(errno));
    exit(1);
  }
  ret = recv(sockfd, response, BUFFSIZE, 0);
  if (ret == -1) {
    fprintf(stderr, "Error receiving data from server: %s\n", strerror(errno));
    exit(1);
  }
  fprintf(stdout, "%s", response);

  sprintf(command, "STAT\r\n");
  ret = send(sockfd, command, strlen(command), 0);
  if (ret == -1) {
    fprintf(stderr, "Error sending data to server: %s\n", strerror(errno));
    exit(1);
  }
  ret = recv(sockfd, response, BUFFSIZE, 0);
  if (ret == -1) {
    fprintf(stderr, "Error receiving data from server: %s\n", strerror(errno));
    exit(1);
  }
  fprintf(stdout, "%s", response);

  sprintf(command, "RETR %s\r\n", mail);
  ret = send(sockfd, command, strlen(command), 0);
  if (ret == -1) {
    fprintf(stderr, "Error sending data to server: %s\n", strerror(errno));
    exit(1);
  }

  FILE *fp = fopen(mail, "w");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file: %s\n", strerror(errno));
    exit(1);
  }

  while (1) {
    ret = recv(sockfd, response, BUFFSIZE, 0);
    if (ret == -1) {
      fprintf(stderr, "Error receiving data from server: %s\n", strerror(errno));
      exit(1);
    }
    if (strstr(response, ".\r\n"))
      break;
    fprintf(fp, "%s", response);
  }

  fclose(fp);

  sprintf(command, "QUIT\r\n");
  ret = send(sockfd, command, strlen(command), 0);
  if (ret == -1) {
    fprintf(stderr, "Error sending data to server: %s\n", strerror(errno));
    exit(1);
  }

  close(sockfd);

  return 0;
}