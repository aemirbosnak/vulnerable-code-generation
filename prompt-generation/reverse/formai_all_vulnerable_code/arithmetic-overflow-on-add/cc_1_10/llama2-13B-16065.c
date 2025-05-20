//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT_RANGE 1024

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: Please specify a port range to scan\n");
    return 1;
  }

  int start_port, end_port;
  char *port_range = argv[1];
  sscanf(port_range, "%d-%d", &start_port, &end_port);

  if (start_port > end_port) {
    printf("Error: Start port cannot be greater than end port\n");
    return 1;
  }

  struct sockaddr_in server_addr;
  socklen_t client_len = sizeof(server_addr);
  int client_fd, server_fd;

  // Create a socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket failed");
    return 1;
  }

  // Set address and port number
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(0); // any available port
  inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

  // Bind the socket
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    close(server_fd);
    return 1;
  }

  // Listen for incoming connections
  if (listen(server_fd, 5) < 0) {
    perror("listen failed");
    close(server_fd);
    return 1;
  }

  // Scan ports
  for (int i = start_port; i <= end_port; i++) {
    char port_str[5];
    snprintf(port_str, sizeof(port_str), "%d", i);
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Accept and connect to the client
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
      perror("accept failed");
      continue;
    }

    // Print the client IP and port
    printf("Client IP: %s, Port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Close the client connection
    close(client_fd);
  }

  // Close the server connection
  close(server_fd);

  return 0;
}