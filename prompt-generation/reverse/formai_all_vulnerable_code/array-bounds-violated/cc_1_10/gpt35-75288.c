//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, numbytes;
  char buf[BUF_SIZE], command[BUF_SIZE];
  struct addrinfo hints, *res;
  
  // Check that a server address was provided
  if (argc != 2) {
    fprintf(stderr, "Usage: %s server_address\n", argv[0]);
    exit(1);
  }
  
  // Set up the hints struct for address resolution
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  
  // Look up the server address
  if (getaddrinfo(argv[1], "imap", &hints, &res) != 0) {
    fprintf(stderr, "Failed to resolve server address\n");
    exit(1);
  }
  
  // Create a socket and connect to the server
  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sockfd == -1) {
    fprintf(stderr, "Failed to create socket\n");
    exit(1);
  }
  if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
    fprintf(stderr, "Failed to connect to server\n");
    exit(1);
  }
  
  // Receive and print the server greeting message
  numbytes = recv(sockfd, buf, BUF_SIZE - 1, 0);
  buf[numbytes] = '\0';
  printf("%s", buf);
  
  // Send the login credentials to the server
  printf("Username: ");
  scanf("%s", command);
  sprintf(buf, "A001 LOGIN %s ", command);
  printf("Password: ");
  scanf("%s", command);
  strcat(buf, command);
  strcat(buf, "\r\n");
  send(sockfd, buf, strlen(buf), 0);
  
  // Receive and print the server response to the login command
  numbytes = recv(sockfd, buf, BUF_SIZE - 1, 0);
  buf[numbytes] = '\0';
  printf("%s", buf);
  
  // Send the list command to the server
  sprintf(buf, "A002 LIST \"\" *\r\n");
  send(sockfd, buf, strlen(buf), 0);
  
  // Receive and print the server response to the list command
  while (numbytes = recv(sockfd, buf, BUF_SIZE - 1, 0)) {
    buf[numbytes] = '\0';
    printf("%s", buf);
  }
  
  // Close the socket and free the address info 
  close(sockfd);
  freeaddrinfo(res);
  
  return 0;
}