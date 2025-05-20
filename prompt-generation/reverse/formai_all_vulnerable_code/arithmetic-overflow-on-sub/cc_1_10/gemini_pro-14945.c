//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define BUF_SIZE 1024

int main() {
  int sockfd, n, total = 0;
  struct sockaddr_in servaddr;
  char buf[BUF_SIZE];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, "www.google.com", &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return 1;
  }

  struct timeval start, end;
  gettimeofday(&start, NULL);

  while ((n = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
    total += n;
  }
  if (n < 0) {
    perror("recv");
    return 1;
  }

  gettimeofday(&end, NULL);

  long elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
  double speed = (double)total * 8 / elapsed_time;

  printf("Speed: %.2f Mbps\n", speed);

  close(sockfd);

  return 0;
}