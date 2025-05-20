//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <limits.h>
#include <stdint.h>
#include <errno.h>

#define MAX_PORTS 10000

int main(int argc, char **argv) {

  // Check for valid arguments.
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <target IP address> <start port> <end port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the target IP address.
  char *target = argv[1];

  // Get the start and end ports.
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  // Check if the start port is valid.
  if (start_port < 0 || start_port > USHRT_MAX) {
    fprintf(stderr, "Error: Invalid start port.\n");
    return EXIT_FAILURE;
  }

  // Check if the end port is valid.
  if (end_port < 0 || end_port > USHRT_MAX) {
    fprintf(stderr, "Error: Invalid end port.\n");
    return EXIT_FAILURE;
  }

  // Check if the start port is greater than the end port.
  if (start_port > end_port) {
    fprintf(stderr, "Error: Start port must be less than or equal to the end port.\n");
    return EXIT_FAILURE;
  }

  // Check if the number of ports to scan is valid.
  int num_ports = end_port - start_port + 1;
  if (num_ports > MAX_PORTS) {
    fprintf(stderr, "Error: Too many ports to scan.\n");
    return EXIT_FAILURE;
  }

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error: Could not create socket.\n");
    return EXIT_FAILURE;
  }

  // Set the socket options.
  int reuse = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
    perror("Error: Could not set socket options.\n");
    return EXIT_FAILURE;
  }

  // Set the target address.
  struct sockaddr_in target_addr;
  memset(&target_addr, 0, sizeof(target_addr));
  target_addr.sin_family = AF_INET;
  target_addr.sin_port = htons(start_port);
  target_addr.sin_addr.s_addr = inet_addr(target);

  // Scan the ports.
  for (int i = 0; i < num_ports; i++) {

    // Connect to the port.
    if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {

      // The port is open.
      printf("Port %d is open.\n", start_port + i);
    } else if (errno == ECONNREFUSED) {

      // The port is closed..
      printf("Port %d is closed.\n", start_port + i);
    } else {

      // An error occurred.
      perror("Error: Could not connect to port.\n");
      return EXIT_FAILURE;
    }

    // Increment the port number.
    target_addr.sin_port = htons(start_port + i + 1);
  }

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}