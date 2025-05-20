//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>

#define HTTP_PROXY_PORT 8080

int main(int argc, char *argv[]) {
  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  char buffer[1024];

  // Create the server socket
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("socket");
    exit(1);
  }

  // Set the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(HTTP_PROXY_PORT);

  // Bind the server socket to the address
  if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(server_sock, 5) < 0) {
    perror("listen");
    exit(1);
  }

  // Accept incoming connections
  while (1) {
    int len = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &len);
    if (client_sock < 0) {
      perror("accept");
      continue;
    }

    // Read the HTTP request from the client
    int num_bytes = recv(client_sock, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
      perror("recv");
      close(client_sock);
      continue;
    }

    // Parse the HTTP request
    char *host = NULL;
    char *path = NULL;
    char *port = NULL;
    if (sscanf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n", &path, &host) == 2) {
      port = "80";
    } else if (sscanf(buffer, "GET %s HTTP/1.1\r\nHost: %s:%s\r\n", &path, &host, &port) == 3) {
    } else {
      // Invalid HTTP request
      close(client_sock);
      continue;
    }

    // Connect to the remote server
    struct hostent *remote_host = gethostbyname(host);
    if (remote_host == NULL) {
      // Could not resolve the hostname
      close(client_sock);
      continue;
    }

    struct sockaddr_in remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = ((struct in_addr *)remote_host->h_addr)->s_addr;
    remote_addr.sin_port = htons(atoi(port));

    int remote_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (remote_sock < 0) {
      perror("socket");
      close(client_sock);
      continue;
    }

    if (connect(remote_sock, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) < 0) {
      perror("connect");
      close(client_sock);
      close(remote_sock);
      continue;
    }

    // Send the HTTP request to the remote server
    if (send(remote_sock, buffer, num_bytes, 0) < 0) {
      perror("send");
      close(client_sock);
      close(remote_sock);
      continue;
    }

    // Receive the HTTP response from the remote server
    num_bytes = recv(remote_sock, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
      perror("recv");
      close(client_sock);
      close(remote_sock);
      continue;
    }

    // Send the HTTP response to the client
    if (send(client_sock, buffer, num_bytes, 0) < 0) {
      perror("send");
      close(client_sock);
      close(remote_sock);
      continue;
    }

    // Close the client and remote sockets
    close(client_sock);
    close(remote_sock);
  }

  // Close the server socket
  close(server_sock);

  return 0;
}