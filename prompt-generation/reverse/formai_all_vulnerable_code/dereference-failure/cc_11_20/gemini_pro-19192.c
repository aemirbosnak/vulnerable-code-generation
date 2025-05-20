//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>

#define HOST "pop.example.com"
#define PORT 110

int main() {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  char buffer[1024];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Get the server's address
  struct hostent *server = gethostbyname(HOST);
  if (server == NULL) {
    perror("Error getting server address");
    exit(1);
  }

  // Fill in the server's address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Send the username
  n = write(sockfd, "USER username\r\n", strlen("USER username\r\n"));
  if (n < 0) {
    perror("Error sending username");
    exit(1);
  }

  // Receive the server's response
  n = read(sockfd, buffer, sizeof(buffer) - 1);
  if (n < 0) {
    perror("Error receiving server response");
    exit(1);
  }

  // Print the server's response
  buffer[n] = '\0';
  printf("%s", buffer);

  // Send the password
  n = write(sockfd, "PASS password\r\n", strlen("PASS password\r\n"));
  if (n < 0) {
    perror("Error sending password");
    exit(1);
  }

  // Receive the server's response
  n = read(sockfd, buffer, sizeof(buffer) - 1);
  if (n < 0) {
    perror("Error receiving server response");
    exit(1);
  }

  // Print the server's response
  buffer[n] = '\0';
  printf("%s", buffer);

  // Send the LIST command
  n = write(sockfd, "LIST\r\n", strlen("LIST\r\n"));
  if (n < 0) {
    perror("Error sending LIST command");
    exit(1);
  }

  // Receive the server's response
  n = read(sockfd, buffer, sizeof(buffer) - 1);
  if (n < 0) {
    perror("Error receiving server response");
    exit(1);
  }

  // Print the server's response
  buffer[n] = '\0';
  printf("%s", buffer);

  // Send the QUIT command
  n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
  if (n < 0) {
    perror("Error sending QUIT command");
    exit(1);
  }

  // Receive the server's response
  n = read(sockfd, buffer, sizeof(buffer) - 1);
  if (n < 0) {
    perror("Error receiving server response");
    exit(1);
  }

  // Print the server's response
  buffer[n] = '\0';
  printf("%s", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}