#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: ./proxy <remote_server_address> <remote_server_port>\n");
    return 1;
  }

  char *remote_server_address = argv[1];
  int remote_server_port = atoi(argv[2]);

  // Create a socket to listen for client connections
  int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_fd == -1) {
    perror("Error creating socket");
    return 1;
  }

  // Bind the socket to a port
  struct sockaddr_in bind_addr;
  bind_addr.sin_family = AF_INET;
  bind_addr.sin_port = htons(8080);
  if (bind(listen_fd, (struct sockaddr *)&bind_addr, sizeof(bind_addr)) == -1) {
    perror("Error binding socket");
    return 1;
  }

  // Listen for client connections
  for (;;) {
    // Accept a client connection
    int client_fd = accept(listen_fd, NULL, NULL);
    if (client_fd == -1) {
      perror("Error accepting connection");
      continue;
    }

    // Forward the client request to the remote server
    char buffer[1024];
    int bytes_read = read(client_fd, buffer, 1024);
    if (bytes_read > 0) {
      write(client_fd, buffer, bytes_read);
    }

    // Close the client connection
    close(client_fd);
  }

  return 0;
}
