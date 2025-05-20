//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define MAX_PINGS 10
#define MAX_DELAY 10

int main() {
  int sockfd, port, n, i, delay, target_port, num_pings = 0, success = 0;
  char hostname[256], buffer[1024];

  printf("Enter hostname: ");
  scanf("%s", hostname);

  printf("Enter target port: ");
  scanf("%d", &target_port);

  for (i = 0; i < MAX_PINGS; i++) {
    delay = rand() % MAX_DELAY + 1;
    n = ping(hostname, target_port, delay);
    if (n > 0) {
      success++;
    }
    num_pings++;
  }

  printf("Number of pings: %d\n", num_pings);
  printf("Number of successful pings: %d\n", success);
  printf("Percentage of successful pings: %.2f%%", (float)success / num_pings * 100);

  return 0;
}

int ping(char *hostname, int port, int delay) {
  int sockfd, n, i;
  struct sockaddr_in serv_addr;
  char buffer[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0) {
    return -1;
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = inet_addr(hostname);

  sleep(delay);
  n = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (n < 0) {
    return -1;
  }

  return n;
}