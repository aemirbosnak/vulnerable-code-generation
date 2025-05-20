//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
// Port scanner in C, Donald Knuth style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  // Check if the input is valid
  if (argc < 2) {
    printf("Usage: %s <target> <port_range>\n", argv[0]);
    return 1;
  }

  // Parse the input
  char *target = argv[1];
  char *port_range = argv[2];

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Set up the target address
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(0);
  addr.sin_addr.s_addr = inet_addr(target);

  // Parse the port range
  int start_port, end_port;
  sscanf(port_range, "%d-%d", &start_port, &end_port);

  // Iterate through the port range
  for (int port = start_port; port <= end_port; port++) {
    // Set the port number in the address
    addr.sin_port = htons(port);

    // Attempt to connect to the port
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
      printf("Port %d is open\n", port);
    } else {
      printf("Port %d is closed\n", port);
    }
  }

  // Close the socket
  close(sock);

  return 0;
}