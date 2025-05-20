//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define BUFSIZE (1024 * 1024)
#define INTERVAL (1000 * 1000)

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <server>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(80);
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) != 1) {
    fprintf(stderr, "inet_pton failed\n");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  struct timeval start, end;
  gettimeofday(&start, NULL);

  int nbytes = 0;
  while (1) {
    char buf[BUFSIZE];
    int n = recv(sockfd, buf, BUFSIZE, 0);
    if (n == -1) {
      perror("recv");
      break;
    } else if (n == 0) {
      break;
    }
    nbytes += n;

    gettimeofday(&end, NULL);
    if (end.tv_sec - start.tv_sec >= INTERVAL / 1000000) {
      double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
      printf("%f MB/s\n", (double)nbytes / (1024.0 * 1024.0) / elapsed);
      nbytes = 0;
      gettimeofday(&start, NULL);
    }
  }

  close(sockfd);
  return EXIT_SUCCESS;
}