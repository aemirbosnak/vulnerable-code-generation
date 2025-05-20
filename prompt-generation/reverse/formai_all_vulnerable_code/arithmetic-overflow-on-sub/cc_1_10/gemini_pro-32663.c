//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFLEN 1024

int main() {
  int sockfd, n;
  struct sockaddr_in servaddr;
  char buf[BUFLEN];
  clock_t start, end;
  double elapsed;
  int seq = 0;
  int lost = 0;
  int dup = 0;
  int out_of_order = 0;

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(9876);
  inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

  while (1) {
    start = clock();
    sprintf(buf, "seq: %d", seq);
    n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (n < 0) {
      perror("sendto");
      exit(EXIT_FAILURE);
    }

    n = recvfrom(sockfd, buf, BUFLEN, 0, NULL, NULL);
    if (n < 0) {
      perror("recvfrom");
      exit(EXIT_FAILURE);
    }

    end = clock();
    elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    int recv_seq = atoi(buf);
    if (recv_seq != seq) {
      if (recv_seq == seq - 1) {
        dup++;
      } else {
        out_of_order++;
      }
    } else {
      seq++;
    }

    printf("seq: %d, rtt: %.3f ms\n", recv_seq, elapsed * 1000);
  }

  close(sockfd);
  return 0;
}