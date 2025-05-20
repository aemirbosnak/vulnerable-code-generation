//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in servaddr;
  char buffer[MAX_LINE];

  // Check if the user has provided the correct number of arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server_IP_address> <server_port>\n", argv[0]);
    exit(1);
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Set up the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("Error converting IP address");
    exit(1);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Send the USER command
  sprintf(buffer, "USER username\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error sending USER command");
    exit(1);
  }

  // Receive the server's response
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
    perror("Error receiving server's response");
    exit(1);
  }

  // Check if the server's response is positive
  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: Server did not accept USER command: %s\n", buffer);
    exit(1);
  }

  // Send the PASS command
  sprintf(buffer, "PASS password\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error sending PASS command");
    exit(1);
  }

  // Receive the server's response
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
    perror("Error receiving server's response");
    exit(1);
  }

  // Check if the server's response is positive
  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: Server did not accept PASS command: %s\n", buffer);
    exit(1);
  }

  // Send the LIST command
  sprintf(buffer, "LIST\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error sending LIST command");
    exit(1);
  }

  // Receive the server's response
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
    perror("Error receiving server's response");
    exit(1);
  }

  // Check if the server's response is positive
  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: Server did not accept LIST command: %s\n", buffer);
    exit(1);
  }

  // Print the list of messages
  printf("Messages:\n");
  while (1) {
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
      perror("Error receiving server's response");
      exit(1);
    }

    // Check if the server has sent the end of the list
    if (strcmp(buffer, ".\r\n") == 0) {
      break;
    }

    // Print the message
    printf("%s", buffer);
  }

  // Send the QUIT command
  sprintf(buffer, "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error sending QUIT command");
    exit(1);
  }

  // Close the socket
  close(sockfd);

  return 0;
}