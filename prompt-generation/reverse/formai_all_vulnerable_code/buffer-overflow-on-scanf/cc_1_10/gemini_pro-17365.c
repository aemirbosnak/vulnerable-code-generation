//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
  // Initialize variables
  int sockfd, port, n;
  char buffer[1024];
  struct sockaddr_in servaddr;

  // Get the website URL and port number from the user
  printf("Enter the website URL: ");
  scanf("%s", buffer);
  printf("Enter the port number: ");
  scanf("%d", &port);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Socket creation failed");
    exit(1);
  }

  // Set the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  servaddr.sin_addr.s_addr = inet_addr(buffer);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
    perror("Connection failed");
    exit(1);
  }

  // Send a request to the server
  strcpy(buffer, "GET / HTTP/1.1\r\nHost: ");
  strcat(buffer, buffer);
  strcat(buffer, "\r\n\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("Send failed");
    exit(1);
  }

  // Receive the response from the server
  n = recv(sockfd, buffer, 1023, 0);
  if (n == -1) {
    perror("Receive failed");
    exit(1);
  }

  // Check the response code
  if (strncmp(buffer, "HTTP/1.1 200 OK", 14) == 0) {
    printf("Website is up and running!\n");
  } else {
    printf("Website is down or has an error!\n");
  }

  // Close the socket
  close(sockfd);

  return 0;
}