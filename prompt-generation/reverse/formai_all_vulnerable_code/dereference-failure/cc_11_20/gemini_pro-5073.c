//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>

#define PORT 110
#define BUFSIZE 1024

int main() {
  // Declare variables
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUFSIZE];

  // Get the hostname
  printf("Enter the hostname of the POP3 server: ");
  scanf("%s", buffer);

  // Get the server's IP address
  server = gethostbyname(buffer);
  if (server == NULL) {
    printf("Error: could not resolve hostname %s\n", buffer);
    exit(1);
  }

  // Create the socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error: could not create socket\n");
    exit(1);
  }

  // Fill in the server's address
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  serv_addr.sin_addr = *(struct in_addr *)server->h_addr;

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error: could not connect to server\n");
    exit(1);
  }

  // Send the USER command
  sprintf(buffer, "USER username");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    printf("Error: could not send USER command\n");
    exit(1);
  }

  // Read the server's response
  n = read(sockfd, buffer, BUFSIZE);
  if (n < 0) {
    printf("Error: could not read server's response\n");
    exit(1);
  }

  // Print the server's response
  printf("%s\n", buffer);

  // Send the PASS command
  sprintf(buffer, "PASS password");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    printf("Error: could not send PASS command\n");
    exit(1);
  }

  // Read the server's response
  n = read(sockfd, buffer, BUFSIZE);
  if (n < 0) {
    printf("Error: could not read server's response\n");
    exit(1);
  }

  // Print the server's response
  printf("%s\n", buffer);

  // Send the LIST command
  sprintf(buffer, "LIST");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    printf("Error: could not send LIST command\n");
    exit(1);
  }

  // Read the server's response
  n = read(sockfd, buffer, BUFSIZE);
  if (n < 0) {
    printf("Error: could not read server's response\n");
    exit(1);
  }

  // Print the server's response
  printf("%s\n", buffer);

  // Send the RETR command
  sprintf(buffer, "RETR 1");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    printf("Error: could not send RETR command\n");
    exit(1);
  }

  // Read the server's response
  n = read(sockfd, buffer, BUFSIZE);
  if (n < 0) {
    printf("Error: could not read server's response\n");
    exit(1);
  }

  // Print the server's response
  printf("%s\n", buffer);

  // Send the QUIT command
  sprintf(buffer, "QUIT");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    printf("Error: could not send QUIT command\n");
    exit(1);
  }

  // Close the socket
  close(sockfd);

  return 0;
}