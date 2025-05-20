//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

  if (argc < 2) {
    perror("Usage: ./http-client <URL>\n");
    return 1;
  }

  char *url = argv[1];
  struct hostent *server;
  struct sockaddr_in server_address;

  // Parse the host and path from the URL
  char host[512];
  char path[512];
  sscanf(url, "http://%[^/]/%s", host, path);

  // Get the server's IP address
  server = gethostbyname(host);
  if (server == NULL) {
    perror("Failed to resolve host\n");
    return 1;
  }

  // Create a socket for the server
  int server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock == -1) {
    perror("Failed to create socket\n");
    return 1;
  }

  // Set server address parameters
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(80);
  server_address.sin_addr = *((struct in_addr*) server->h_addr);

  // Connect to the server
  if (connect(server_sock, (struct sockaddr*) &server_address, sizeof(server_address)) != 0) {
    perror("Failed to connect to server\n");
    return 1;
  }

  // Construct the HTTP request message
  char request[1024];
  sprintf(request, "GET /%s HTTP/1.1\r\n"
                    "Host: %s\r\n"
                    "Connection: close\r\n\r\n", path, host);

  // Send the request to the server
  if (send(server_sock, request, strlen(request), 0) == -1) {
    perror("Failed to send request to server\n");
    return 1;
  }

  // Receive the response from the server
  char buffer[BUFFER_SIZE];
  int recv_len;
  while ((recv_len = recv(server_sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
    buffer[recv_len] = '\0';
    printf("%s", buffer);
  }

  // Close the socket
  close(server_sock);

  return 0;
}