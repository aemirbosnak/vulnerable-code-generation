//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_MIN 0
#define PORT_MAX 65535

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip address> <port range>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *ip_address = argv[1];
  char *port_range = argv[2];

  int port_min, port_max;
  if (sscanf(port_range, "%d-%d", &port_min, &port_max) != 2) {
    fprintf(stderr, "Invalid port range: %s\n", port_range);
    return EXIT_FAILURE;
  }

  if (port_min < PORT_MIN || port_min > PORT_MAX || port_max < PORT_MIN || port_max > PORT_MAX) {
    fprintf(stderr, "Invalid port range: %s\n", port_range);
    return EXIT_FAILURE;
  }

  int sockfd;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port_min);
  if (inet_pton(AF_INET, ip_address, &servaddr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid IP address: %s\n", ip_address);
    return EXIT_FAILURE;
  }

  int port;
  for (port = port_min; port <= port_max; port++) {
    servaddr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == 0) {
      printf("Port %d is open on %s\n", port, ip_address);
    }
  }

  close(sockfd);

  return EXIT_SUCCESS;
}