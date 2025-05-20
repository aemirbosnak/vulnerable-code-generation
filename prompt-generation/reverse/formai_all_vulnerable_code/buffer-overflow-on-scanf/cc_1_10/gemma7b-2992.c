//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

int main() {
  int sockfd, n, err, addr_len, send_len, recv_len;
  char buffer[1024];
  struct sockaddr_in server_addr;
  struct hostent *server_host;

  // Allocate memory for the server host structure
  server_host = malloc(sizeof(struct hostent));

  // Get the server host name from the user
  printf("Enter the server host name: ");
  scanf("%s", buffer);

  // Resolve the server host name
  server_host = gethostbyname(buffer);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(80));

  // Connect to the server
  addr_len = sizeof(server_addr);
  err = connect(sockfd, (struct sockaddr *)&server_addr, &addr_len);
  if (err < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Send a message to the server
  send_len = send(sockfd, "Hello, world!", 13, 0);

  // Receive a message from the server
  recv_len = recv(sockfd, buffer, 1024, 0);

  // Print the server's message
  printf("Server's message: %s\n", buffer);

  // Close the socket
  close(sockfd);

  // Free the server host structure
  free(server_host);

  return 0;
}