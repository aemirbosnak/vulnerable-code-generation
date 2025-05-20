//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT_RANGE 1000
#define MAX_CONNECTIONS 100

int main(int argc, char *argv[]) {
  // Check if the correct number of arguments was passed
  if (argc != 3) {
    printf("Usage: %s <ip_address> <port_range>\n", argv[0]);
    return 1;
  }

  // Get the IP address and port range from the arguments
  char *ip_address = argv[1];
  int port_range = atoi(argv[2]);

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("Failed to create socket");
    return 1;
  }

  // Initialize the socket address structure
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr(ip_address);

  // Loop through the port range and attempt to connect to each port
  for (int port = 1; port <= port_range; port++) {
    server_address.sin_port = htons(port);

    // Attempt to connect to the server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) == 0) {
      printf("Port %d is open\n", port);
    }
  }

  // Close the socket
  close(sock);

  return 0;
}