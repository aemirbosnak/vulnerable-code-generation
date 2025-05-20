//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 21
#define BUFFER_SIZE 1024

int main() {
  int sockfd, n, port = SERVER_PORT, err;
  char buffer[BUFFER_SIZE];
  struct sockaddr_in server_addr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Connect to the server
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr("localhost");
  err = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (err < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Send and receive data
  printf("Enter file name: ");
  scanf("%s", buffer);
  n = send(sockfd, buffer, BUFFER_SIZE, 0);
  if (n < 0) {
    perror("Error sending data");
    exit(1);
  }

  n = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (n < 0) {
    perror("Error receiving data");
    exit(1);
  }

  // Print the server's response
  printf("Server's response: %s\n", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}