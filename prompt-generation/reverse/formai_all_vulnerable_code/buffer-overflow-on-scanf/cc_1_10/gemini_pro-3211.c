//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_START 1
#define PORT_END 65535
#define MAX_PORTS 100

int main() {
  int sockfd, port_count;
  struct sockaddr_in addr;
  char ip[16];
  unsigned short ports[MAX_PORTS];

  // Get the IP address of the host
  printf("Enter the IP address of the host: ");
  scanf("%s", ip);

  // Get the list of ports to scan
  printf("Enter the list of ports to scan (comma-separated): ");
  char input[1024];
  scanf("%s", input);

  // Parse the input and store the ports in an array
  char *token = strtok(input, ",");
  port_count = 0;
  while (token != NULL) {
    ports[port_count++] = atoi(token);
    token = strtok(NULL, ",");
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Set the socket address
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip);
  addr.sin_port = htons(PORT_START);

  // Scan the ports
  for (int i = 0; i < port_count; i++) {
    addr.sin_port = htons(ports[i]);

    // Connect to the port
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
      printf("Port %d is closed\n", ports[i]);
    } else {
      printf("Port %d is open\n", ports[i]);

      // Close the connection
      close(sockfd);

      // Reconnect to the next port
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (sockfd == -1) {
        perror("socket");
        exit(1);
      }
    }
  }

  // Close the socket
  close(sockfd);

  return 0;
}