//GEMINI-pro DATASET v1.0 Category: Networking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
  int sockfd, port;
  struct sockaddr_in server_addr, client_addr;
  char buf[1024];

  int addr_len = sizeof(struct sockaddr_in);

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  port = 5000;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sockfd, (struct sockaddr *)&server_addr, addr_len) < 0) {
    perror("Error binding socket");
    exit(EXIT_FAILURE);
  }

  while (1) {
    int n = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&client_addr, &addr_len);
    if (n < 0) {
      perror("Error receiving data");
      continue;
    }

    buf[n] = '\0';
    printf("Received: %s\n", buf);

    int sent = sendto(sockfd, buf, n, 0, (struct sockaddr *)&client_addr, addr_len);
    if (sent < 0) {
      perror("Error sending data");
      continue;
    }
  }

  close(sockfd);

  return 0;
}