//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_MIN 1
#define PORT_MAX 65535

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip_address> <port_range>\n", argv[0]);
    exit(1);
  }

  char *ip_address = argv[1];
  char *port_range = argv[2];

  int port_start, port_end;
  if (sscanf(port_range, "%d-%d", &port_start, &port_end) != 2) {
    fprintf(stderr, "Invalid port range: %s\n", port_range);
    exit(1);
  }

  if (port_start < PORT_MIN || port_start > PORT_MAX || port_end < PORT_MIN || port_end > PORT_MAX) {
    fprintf(stderr, "Invalid port range: %d-%d\n", port_start, port_end);
    exit(1);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(ip_address);

  for (int port = port_start; port <= port_end; port++) {
    servaddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == 0) {
      printf("Port %d: open\n", port);
    } else {
      printf("Port %d: closed\n", port);
    }
  }

  close(sockfd);

  return 0;
}