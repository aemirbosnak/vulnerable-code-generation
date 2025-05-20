//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
  // Declare variables
  int sockfd, port, result;
  struct sockaddr_in servaddr;
  char ip[16];

  // Get the IP address and port from the user
  printf("Enter the IP address: ");
  scanf("%s", ip);
  printf("Enter the port: ");
  scanf("%d", &port);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  result = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  if (result == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Check if the port is open
  if (result == 0) {
    printf("Port %d is open!\n", port);
  } else {
    printf("Port %d is closed.\n", port);
  }

  // Close the socket
  close(sockfd);

  return 0;
}