//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: immersive
// Immersive C Port Scanner Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_RANGE 1024
#define TIMEOUT 5

void scan_ports(char* target, int port_range) {
  int sockfd, n;
  struct sockaddr_in servaddr, cliaddr;
  struct timeval timeout;
  socklen_t len;
  char buffer[1024];

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket creation failed");
    exit(1);
  }

  timeout.tv_sec = TIMEOUT;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
    perror("setsockopt failed");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(target);

  for (int i = 0; i < port_range; i++) {
    servaddr.sin_port = htons(i);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
      perror("connect failed");
      close(sockfd);
      exit(1);
    }
    len = sizeof(cliaddr);
    n = recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&cliaddr, &len);
    if (n < 0) {
      perror("recvfrom failed");
      close(sockfd);
      exit(1);
    }
    printf("Port %d is open\n", i);
    close(sockfd);
  }
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: %s <target> <port_range>\n", argv[0]);
    exit(1);
  }
  scan_ports(argv[1], atoi(argv[2]));
  return 0;
}