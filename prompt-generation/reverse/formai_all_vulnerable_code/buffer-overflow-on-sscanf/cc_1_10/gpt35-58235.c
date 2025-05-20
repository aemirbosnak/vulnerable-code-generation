//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  // Check arguments
  if (argc != 2) {
    printf("Usage: %s <url>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Parse URL
  char *url = argv[1];    
  char host[BUFFER_SIZE];
  char path[BUFFER_SIZE];
  int port;
  if (sscanf(url, "http://%[^:/]:%d/%s", host, &port, path) != 3) {
    printf("Error: Invalid URL\n");
    exit(EXIT_FAILURE);
  }

  // Print debug info
  printf("Host: %s\n", host);
  printf("Port: %d\n", port);
  printf("Path: %s\n", path);

  // Resolve host name
  struct hostent *he = gethostbyname(host);
  if (he == NULL) {
    printf("Error: Cannot resolve host name\n");
    exit(EXIT_FAILURE);
  }

  // Create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Error: Cannot create socket\n");
    exit(EXIT_FAILURE);
  }

  // Connect to server
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr = *((struct in_addr *)he->h_addr);
  memset(&(server_addr.sin_zero), '\0', 8);
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    printf("Error: Cannot connect to server\n");
    exit(EXIT_FAILURE);
  }

  // Send HTTP request
  char request[BUFFER_SIZE];
  sprintf(request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);
  if (send(sock, request, strlen(request), 0) == -1) {
    printf("Error: Cannot send request\n");
    exit(EXIT_FAILURE);
  }

  // Receive response
  char response[BUFFER_SIZE];
  int len;
  while ((len = recv(sock, response, BUFFER_SIZE - 1, 0)) > 0) {
    response[len] = '\0';
    printf("%s", response);
  }
  
  // Close socket
  close(sock);

  return 0;
}