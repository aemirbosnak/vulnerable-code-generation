//Code Llama-13B DATASET v1.0 Category: Networking ; Style: random
// Unique C Networking Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int sockfd, n;
  char buffer[256];
  struct sockaddr_in serv_addr;

  if (argc < 3) {
    printf("usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  // Set up the server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
    perror("Error converting IP address");
    return 1;
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    return 1;
  }

  // Send a message to the server
  n = write(sockfd, "Hello, world!", strlen("Hello, world!") + 1);
  if (n < 0) {
    perror("Error writing to socket");
    return 1;
  }

  // Read a response from the server
  n = read(sockfd, buffer, 256);
  if (n < 0) {
    perror("Error reading from socket");
    return 1;
  }
  printf("Received response: %s\n", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}