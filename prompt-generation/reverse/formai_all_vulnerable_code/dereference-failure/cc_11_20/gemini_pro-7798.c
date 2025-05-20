//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip-address> <port-range>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the IP address
  struct sockaddr_in addr;
  if (inet_pton(AF_INET, argv[1], &addr.sin_addr) != 1) {
    fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Parse the port range
  char *dash = strchr(argv[2], '-');
  if (dash == NULL) {
    fprintf(stderr, "Invalid port range: %s\n", argv[2]);
    return EXIT_FAILURE;
  }
  *dash = '\0';
  int start_port = atoi(argv[2]);
  int end_port = atoi(dash + 1);
  if (start_port < 0 || end_port < 0 || start_port > end_port) {
    fprintf(stderr, "Invalid port range: %s\n", argv[2]);
    return EXIT_FAILURE;
  }

  // Create the socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the socket options
  int optval = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
    perror("setsockopt");
    return EXIT_FAILURE;
  }

  // Bind the socket to the local address
  addr.sin_family = AF_INET;
  addr.sin_port = 0;
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Scan the ports
  for (int port = start_port; port <= end_port; port++) {
    // Set the destination address
    addr.sin_port = htons(port);

    // Connect to the port
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
      printf("Port %d is open\n", port);
    } else if (errno != ECONNREFUSED) {
      perror("connect");
      return EXIT_FAILURE;
    }
  }

  // Close the socket
  close(sockfd);
  return EXIT_SUCCESS;
}