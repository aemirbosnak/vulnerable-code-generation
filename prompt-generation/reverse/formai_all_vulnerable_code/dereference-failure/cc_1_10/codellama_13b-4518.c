//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: careful
/*
 * A simple HTTP client in C
 *
 * This program sends a GET request to the specified URL
 * and prints the response to the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 2) {
    printf("Usage: %s <url>\n", argv[0]);
    return 1;
  }

  // Parse the URL
  char *url = argv[1];
  char *host = strtok(url, ":");
  char *port = strtok(NULL, ":");

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  // Initialize the socket address
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  inet_pton(AF_INET, host, &server_addr.sin_addr);

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect() failed");
    return 1;
  }

  // Send the GET request
  char *request = "GET / HTTP/1.1\r\nHost: ";
  strcat(request, host);
  strcat(request, "\r\n\r\n");
  if (send(sock, request, strlen(request), 0) < 0) {
    perror("send() failed");
    return 1;
  }

  // Receive the response
  char buffer[1024];
  int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
  if (bytes_received < 0) {
    perror("recv() failed");
    return 1;
  }
  buffer[bytes_received] = '\0';

  // Print the response
  printf("Response:\n%s", buffer);

  // Close the socket
  close(sock);

  return 0;
}