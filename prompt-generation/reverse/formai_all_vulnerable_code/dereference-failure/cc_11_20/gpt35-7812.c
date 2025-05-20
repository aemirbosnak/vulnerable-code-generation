//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, client_sockfd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUFFER_SIZE];

  if (argc != 2) {
    printf("Usage: %s <port number>\n", argv[0]);
    exit(1);
  }

  // Create a socket for the proxy server
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error: %s\n", strerror(errno));
    exit(1);
  }

  // Set the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(atoi(argv[1]));

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Error: %s\n", strerror(errno));
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sockfd, 5) < 0) {
    printf("Error: %s\n", strerror(errno));
    exit(1);
  }

  printf("Proxy server started on port %s\n", argv[1]);

  while (1) {
    socklen_t client_len = sizeof(client_addr);

    // Accept a client connection
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (client_sockfd < 0) {
      printf("Error: %s\n", strerror(errno));
      continue;
    }

    // Receive the request from the client
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(client_sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
      printf("Error: %s\n", strerror(errno));
      close(client_sockfd);
      continue;
    }

    printf("Received request from client:\n%s", buffer);

    // Extract the host name and port from the request
    char *host_start = strstr(buffer, "Host: ") + sizeof("Host: ") - 1;
    char *host_end = strstr(host_start, "\r\n");
    char *port_start = strstr(buffer, "http://") + sizeof("http://") - 1;
    char *port_end = strchr(port_start, ':');
    if (port_end == NULL) {
      port_end = strstr(port_start, "/");
    }

    char host[100];
    strncpy(host, host_start, host_end - host_start);
    host[host_end - host_start] = '\0';
    int port = atoi(port_start);

    printf("Connecting to host %s on port %d\n", host, port);

    // Open a connection to the remote server
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
      printf("Error: %s\n", strerror(errno));
      close(client_sockfd);
      continue;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(host);

    if (connect(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
      printf("Error: %s\n", strerror(errno));
      close(client_sockfd);
      close(server_sockfd);
      continue;
    }

    // Forward the request to the remote server
    if (send(server_sockfd, buffer, strlen(buffer), 0) < 0) {
      printf("Error: %s\n", strerror(errno));
      close(client_sockfd);
      close(server_sockfd);
      continue;
    }

    // Receive the response from the remote server
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_sent = recv(server_sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_sent < 0) {
      printf("Error: %s\n", strerror(errno));
      close(client_sockfd);
      close(server_sockfd);
      continue;
    }

    printf("Received response from server:\n%s", buffer);

    // Forward the response to the client
    if (send(client_sockfd, buffer, strlen(buffer), 0) < 0) {
      printf("Error: %s\n", strerror(errno));
      close(client_sockfd);
      close(server_sockfd);
      continue;
    }

    // Close the connections
    close(client_sockfd);
    close(server_sockfd);
  }

  return 0;
}