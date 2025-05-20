//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 21

int main() {
  int sockfd;
  struct sockaddr_in servaddr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(1);
  }

  char buf[1024];
  int n;

  while (1) {
    printf("Enter command: ");
    scanf("%s", buf);

    if (strcmp(buf, "USER") == 0) {
      printf("Enter username: ");
      scanf("%s", buf);
      send(sockfd, buf, strlen(buf), 0);
      recv(sockfd, buf, sizeof(buf), 0);
      printf("%s\n", buf);
    } else if (strcmp(buf, "PASS") == 0) {
      printf("Enter password: ");
      scanf("%s", buf);
      send(sockfd, buf, strlen(buf), 0);
      recv(sockfd, buf, sizeof(buf), 0);
      printf("%s\n", buf);
    } else if (strcmp(buf, "LIST") == 0) {
      send(sockfd, buf, strlen(buf), 0);
      n = recv(sockfd, buf, sizeof(buf), 0);
      buf[n] = '\0';
      printf("%s\n", buf);
    } else if (strcmp(buf, "RETR") == 0) {
      printf("Enter filename: ");
      scanf("%s", buf);
      send(sockfd, buf, strlen(buf), 0);
      FILE *fp = fopen(buf, "w");
      n = recv(sockfd, buf, sizeof(buf), 0);
      while (n > 0) {
        fwrite(buf, 1, n, fp);
        n = recv(sockfd, buf, sizeof(buf), 0);
      }
      fclose(fp);
      printf("File downloaded.\n");
    } else if (strcmp(buf, "QUIT") == 0) {
      send(sockfd, buf, strlen(buf), 0);
      break;
    } else {
      printf("Invalid command.\n");
    }
  }

  close(sockfd);

  return 0;
}