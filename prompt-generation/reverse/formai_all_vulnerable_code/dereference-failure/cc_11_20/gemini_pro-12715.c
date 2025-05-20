//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Optimized TCP/IP echo server program

int main(int argc, char **argv) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  bzero((char *)&serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error on binding");
    exit(1);
  }

  listen(sockfd, 5);

  while (1) {
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("Error on accept");
      continue;
    }

    while (1) {
      bzero(buffer, 256);
      int n = read(newsockfd, buffer, 255);
      if (n < 0) {
        perror("Error on reading");
        break;
      } else if (n == 0) {
        printf("Client disconnected\n");
        break;
      }

      // Optimized echo response
      int i;
      char *p = buffer;
      for (i = 0; i < n; i++) {
        if (p[i] >= 'a' && p[i] <= 'z') {
          p[i] -= 32; // Convert to uppercase
        } else if (p[i] >= 'A' && p[i] <= 'Z') {
          p[i] += 32; // Convert to lowercase
        }
      }

      n = write(newsockfd, buffer, n);
      if (n < 0) {
        perror("Error on writing");
        break;
      }
    }

    close(newsockfd);
  }

  close(sockfd);
  return 0;
}