//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: thoughtful
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

#define MAX_PINGS 5

int main() {
  int i;
  struct sockaddr_in sock_addr;
  char hostname[256];
  int port = 53;
  int num_pings = 0;

  printf("Enter hostname: ");
  scanf("%s", hostname);

  for (i = 0; i < MAX_PINGS; i++) {
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = inet_addr(hostname);

    if (ping(sock_addr) == 0) {
      num_pings++;
      printf("Ping successful!\n");
    } else {
      printf("Ping failed.\n");
    }

    port++;
  }

  printf("Number of successful pings: %d\n", num_pings);

  return 0;
}

int ping(struct sockaddr_in sock_addr) {
  int sockfd;
  char buf[128];
  int bytes_sent = 0, bytes_received = 0;

  sockfd = socket(AF_INET, SOCK_STREAM, htons(22));

  if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1) {
    return -1;
  }

  send(sockfd, buf, 128, 0);
  bytes_sent = send(sockfd, buf, 128, 0);

  bytes_received = recv(sockfd, buf, 128, 0);

  close(sockfd);

  if (bytes_received > 0) {
    return 0;
  } else {
    return -1;
  }
}