//FormAI DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFLEN 100
#define PACKETS 10

int main(int argc, char *argv[]) {
  struct addrinfo hints, *res;
  int sockfd, rv, len, seq_no = 0;
  struct timeval start, end;
  char buf[BUFLEN];

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
    return 1;
  }

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;

  if ((rv = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
  }

  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  while (seq_no < PACKETS) {
    seq_no++;

    memset(buf, '\0', BUFLEN);
    sprintf(buf, "ping %d", seq_no);

    len = strlen(buf);
    gettimeofday(&start, NULL);
    sendto(sockfd, buf, len, 0, res->ai_addr, res->ai_addrlen);

    memset(buf, '\0', BUFLEN);
    recvfrom(sockfd, buf, BUFLEN, 0, NULL, NULL);

    gettimeofday(&end, NULL);
    long time_microseconds = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);

    printf("ping %d received from %s: time=%ldms\n", seq_no, argv[1], time_microseconds / 1000);
    sleep(1);
  }

  freeaddrinfo(res);
  close(sockfd);
  return 0;
}