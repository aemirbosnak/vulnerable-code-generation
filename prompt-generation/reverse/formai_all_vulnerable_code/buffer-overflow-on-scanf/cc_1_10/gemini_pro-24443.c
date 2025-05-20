//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  // Get the hostname and port number from the user
  char hostname[256];
  int port;
  printf("Enter the hostname: ");
  scanf("%s", hostname);
  printf("Enter the port number: ");
  scanf("%d", &port);

  // Resolve the hostname
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("Error resolving hostname");
    return 1;
  }

  // Create a sockaddr_in structure
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
  server_addr.sin_port = htons(port);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    return 1;
  }

  // Send a HTTP request to the server
  char request[] = "GET / HTTP/1.1\r\nHost: hostname\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("Error sending request to server");
    return 1;
  }

  // Receive the HTTP response from the server
  char response[1024];
  int bytes_received = recv(sockfd, response, sizeof(response), 0);
  if (bytes_received < 0) {
    perror("Error receiving response from server");
    return 1;
  }

  // Print the HTTP response
  printf("%s", response);

  // Close the socket
  close(sockfd);

  return 0;
}