//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFSIZE 4096

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <port> <target-host>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int port = atoi(argv[1]);
  char *target_host = argv[2];

  // Create a listening socket for incoming connections
  int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (listening_socket == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set up the listening socket address
  struct sockaddr_in listening_address;
  memset(&listening_address, 0, sizeof(listening_address));
  listening_address.sin_family = AF_INET;
  listening_address.sin_port = htons(port);
  listening_address.sin_addr.s_addr = htonl(INADDR_ANY);

  // Bind the listening socket to the listening address
  if (bind(listening_socket, (struct sockaddr *)&listening_address, sizeof(listening_address)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(listening_socket, 5) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Accept an incoming connection
    int client_socket = accept(listening_socket, NULL, NULL);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Create a socket to connect to the target host
    int target_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (target_socket == -1) {
      perror("socket");
      close(client_socket);
      continue;
    }

    // Set up the target socket address
    struct sockaddr_in target_address;
    memset(&target_address, 0, sizeof(target_address));
    target_address.sin_family = AF_INET;
    target_address.sin_port = htons(80);
    target_address.sin_addr.s_addr = inet_addr(target_host);

    // Connect to the target host
    if (connect(target_socket, (struct sockaddr *)&target_address, sizeof(target_address)) == -1) {
      perror("connect");
      close(client_socket);
      close(target_socket);
      continue;
    }

    // Proxy the data between the client and the target host
    char buffer[BUFSIZE];
    while (1) {
      // Read data from the client
      ssize_t bytes_received = recv(client_socket, buffer, BUFSIZE, 0);
      if (bytes_received == -1) {
        perror("recv");
        close(client_socket);
        close(target_socket);
        break;
      } else if (bytes_received == 0) {
        // Client has closed the connection
        break;
      }

      // Send the data to the target host
      if (send(target_socket, buffer, bytes_received, 0) == -1) {
        perror("send");
        close(client_socket);
        close(target_socket);
        break;
      }

      // Read the response from the target host
      ssize_t bytes_sent = recv(target_socket, buffer, BUFSIZE, 0);
      if (bytes_sent == -1) {
        perror("recv");
        close(client_socket);
        close(target_socket);
        break;
      } else if (bytes_sent == 0) {
        // Target host has closed the connection
        break;
      }

      // Send the response to the client
      if (send(client_socket, buffer, bytes_sent, 0) == -1) {
        perror("send");
        close(client_socket);
        close(target_socket);
        break;
      }
    }

    // Close the client and target sockets
    close(client_socket);
    close(target_socket);
  }

  // Close the listening socket
  close(listening_socket);

  return EXIT_SUCCESS;
}