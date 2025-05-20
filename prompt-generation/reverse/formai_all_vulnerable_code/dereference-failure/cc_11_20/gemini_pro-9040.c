//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int sockfd, port;
  struct sockaddr_in serv_addr;
  char buf[1024], cmd[32], arg[256];
  socklen_t len = sizeof(serv_addr);

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  port = atoi(argv[2]);

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  memset(&serv_addr, 0, len);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, len) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  memset(buf, 0, sizeof(buf));
  read(sockfd, buf, sizeof(buf));
  printf("%s\n", buf);

  while (1) {
    printf(">> ");
    memset(buf, 0, sizeof(buf));
    memset(cmd, 0, sizeof(cmd));
    memset(arg, 0, sizeof(arg));
    scanf("%s %s", cmd, arg);

    if (strcmp(cmd, "USER") == 0) {
      memset(buf, 0, sizeof(buf));
      sprintf(buf, "USER %s\r\n", arg);
      write(sockfd, buf, strlen(buf));
      memset(buf, 0, sizeof(buf));
      read(sockfd, buf, sizeof(buf));
      printf("%s\n", buf);
    } else if (strcmp(cmd, "PASS") == 0) {
      memset(buf, 0, sizeof(buf));
      sprintf(buf, "PASS %s\r\n", arg);
      write(sockfd, buf, strlen(buf));
      memset(buf, 0, sizeof(buf));
      read(sockfd, buf, sizeof(buf));
      printf("%s\n", buf);
    } else if (strcmp(cmd, "LIST") == 0) {
      memset(buf, 0, sizeof(buf));
      sprintf(buf, "LIST %s\r\n", arg);
      write(sockfd, buf, strlen(buf));
      memset(buf, 0, sizeof(buf));
      read(sockfd, buf, sizeof(buf));
      printf("%s\n", buf);
    } else if (strcmp(cmd, "RETR") == 0) {
      memset(buf, 0, sizeof(buf));
      sprintf(buf, "RETR %s\r\n", arg);
      write(sockfd, buf, strlen(buf));
      memset(buf, 0, sizeof(buf));
      read(sockfd, buf, sizeof(buf));
      printf("%s\n", buf);
    } else if (strcmp(cmd, "DELE") == 0) {
      memset(buf, 0, sizeof(buf));
      sprintf(buf, "DELE %s\r\n", arg);
      write(sockfd, buf, strlen(buf));
      memset(buf, 0, sizeof(buf));
      read(sockfd, buf, sizeof(buf));
      printf("%s\n", buf);
    } else if (strcmp(cmd, "QUIT") == 0) {
      memset(buf, 0, sizeof(buf));
      sprintf(buf, "QUIT\r\n");
      write(sockfd, buf, strlen(buf));
      memset(buf, 0, sizeof(buf));
      read(sockfd, buf, sizeof(buf));
      printf("%s\n", buf);
      break;
    }
  }

  close(sockfd);
  return 0;
}