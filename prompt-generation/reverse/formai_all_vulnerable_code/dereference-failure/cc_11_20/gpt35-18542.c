//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: introspective
/*
Here is a simple HTTP proxy program written in C language.
It listens on a specified port for incoming requests, then forwards the request to the specified server.
After the server responds, it forwards the response back to the original client.
*/

#include<arpa/inet.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {

  if (argc < 4) {
    printf("Usage: %s <proxy-port> <server-ip> <server-port>\n", argv[0]);
    return 0;
  }

  int socket_fd, client_fd;
  struct sockaddr_in proxy_addr, server_addr, client_addr;
  char buffer[MAX_BUFFER];

  // Create a new socket for incoming requests
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    printf("Cannot create socket\n");
    return 1;
  }

  // Bind the socket to the specified port
  memset(&proxy_addr, 0, sizeof(proxy_addr));
  proxy_addr.sin_family = AF_INET;
  proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  proxy_addr.sin_port = htons(atoi(argv[1]));
  if (bind(socket_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
    printf("Cannot bind socket to port\n");
    return 1;
  }

  // Listen for incoming requests
  if (listen(socket_fd, 10) < 0) {
    printf("Cannot listen on socket\n");
    return 1;
  }

  printf("Proxy server started on port %s\n", argv[1]);

  while (1) {
    int client_addr_len = sizeof(client_addr);

    // Accept incoming requests
    client_fd = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len);
    if (client_fd < 0) {
      printf("Cannot accept incoming request\n");
      return 1;
    }

    // Fork a new process to handle the request
    int pid = fork();
    if (pid == 0) {
      // Child process
      int server_fd, bytes_received, bytes_sent;

      // Create a new socket to the specified server
      server_fd = socket(AF_INET, SOCK_STREAM, 0);
      if (server_fd < 0) {
        printf("Cannot create socket to server\n");
        return 1;
      }

      // Connect to the specified server
      memset(&server_addr, 0, sizeof(server_addr));
      server_addr.sin_family = AF_INET;
      server_addr.sin_addr.s_addr = inet_addr(argv[2]);
      server_addr.sin_port = htons(atoi(argv[3]));
      if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Cannot connect to server\n");
        return 1;
      }

      // Receive data from the client and forward to server
      while ((bytes_received = recv(client_fd, buffer, MAX_BUFFER, 0)) > 0) {
        bytes_sent = send(server_fd, buffer, bytes_received, 0);
        if (bytes_sent < 0) {
          printf("Cannot send data to server\n");
          break;
        }
      }

      // Receive data from the server and forward to client
      while ((bytes_received = recv(server_fd, buffer, MAX_BUFFER, 0)) > 0) {
        bytes_sent = send(client_fd, buffer, bytes_received, 0);
        if (bytes_sent < 0) {
          printf("Cannot send data to client\n");
          break;
        }
      }

      // Close connections to server and client
      close(server_fd);
      close(client_fd);
      return 0;
    } else {
      // Parent process
      close(client_fd);
    }
  }

  return 0;
}