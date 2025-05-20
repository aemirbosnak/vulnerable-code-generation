//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080 /* proxy port */
#define MAX_SIZE 1024 /* buffer size */

int main(int argc, char *argv[])
{
  int sockfd, newsockfd, clientlen, n;
  char buffer[MAX_SIZE];
  struct sockaddr_in serv_addr, cli_addr;
  int portno;
  fd_set readfds;
  struct timeval tv;
  int maxfd;

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

  memset((char *)&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  listen(sockfd, 5);

  FD_ZERO(&readfds);
  maxfd = sockfd;

  while (1) {
    FD_SET(sockfd, &readfds);
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    if (select(maxfd + 1, &readfds, NULL, NULL, &tv) < 0) {
      perror("Error selecting socket");
      exit(1);
    }

    if (FD_ISSET(sockfd, &readfds)) {
      clientlen = sizeof(cli_addr);
      newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clientlen);
      if (newsockfd < 0) {
        perror("Error accepting connection");
        exit(1);
      }

      FD_SET(newsockfd, &readfds);
      if (newsockfd > maxfd) {
        maxfd = newsockfd;
      }
    }

    for (int i = 0; i <= maxfd; i++) {
      if (FD_ISSET(i, &readfds)) {
        memset(buffer, 0, MAX_SIZE);
        if ((n = read(i, buffer, MAX_SIZE)) <= 0) {
          if (n == 0) {
            printf("Client disconnected\n");
          } else {
            perror("Error reading socket");
          }
          close(i);
          FD_CLR(i, &readfds);
          if (i == maxfd) {
            while (maxfd >= 0 && !FD_ISSET(maxfd, &readfds)) {
              maxfd--;
            }
          }
        } else {
          printf("Client: %s\n", buffer);
          write(i, buffer, n);
        }
      }
    }
  }

  close(sockfd);
  return 0;
}