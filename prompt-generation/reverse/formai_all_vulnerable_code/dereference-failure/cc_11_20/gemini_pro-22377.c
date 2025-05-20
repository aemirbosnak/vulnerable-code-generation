//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 1024

int main(int argc, char **argv) {
  // Check for the correct number of arguments.
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <port> <destination_address>\n", argv[0]);
    return 1;
  }

  // Parse the port number.
  int port = atoi(argv[1]);

  // Get the destination address.
  struct hostent *destination_hostent = gethostbyname(argv[2]);
  if (destination_hostent == NULL) {
    fprintf(stderr, "Invalid destination address: %s\n", argv[2]);
    return 1;
  }

  // Create a socket for listening on the specified port.
  int listening_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (listening_socket == -1) {
    perror("socket");
    return 1;
  }

  // Set up the address structure for the listening socket.
  struct sockaddr_in listening_address;
  memset(&listening_address, 0, sizeof(listening_address));
  listening_address.sin_family = AF_INET;
  listening_address.sin_port = htons(port);
  listening_address.sin_addr.s_addr = INADDR_ANY;

  // Bind the listening socket to the specified address.
  if (bind(listening_socket, (struct sockaddr *)&listening_address, sizeof(listening_address)) == -1) {
    perror("bind");
    return 1;
  }

  // Listen for incoming connections on the listening socket.
  if (listen(listening_socket, 5) == -1) {
    perror("listen");
    return 1;
  }

  // Accept incoming connections on the listening socket.
  int client_socket;
  while ((client_socket = accept(listening_socket, NULL, NULL)) != -1) {
    // Create a socket for connecting to the destination server.
    int destination_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (destination_socket == -1) {
      perror("socket");
      close(client_socket);
      continue;
    }

    // Set up the address structure for the destination server.
    struct sockaddr_in destination_address;
    memset(&destination_address, 0, sizeof(destination_address));
    destination_address.sin_family = AF_INET;
    destination_address.sin_port = htons(80);
    destination_address.sin_addr.s_addr = *((in_addr_t *)destination_hostent->h_addr_list[0]);

    // Connect to the destination server.
    if (connect(destination_socket, (struct sockaddr *)&destination_address, sizeof(destination_address)) == -1) {
      perror("connect");
      close(client_socket);
      close(destination_socket);
      continue;
    }

    // Read the request from the client.
    char request[MAX_REQUEST_SIZE];
    int request_length = read(client_socket, request, MAX_REQUEST_SIZE);
    if (request_length == -1) {
      perror("read");
      close(client_socket);
      close(destination_socket);
      continue;
    }

    // Send the request to the destination server.
    if (write(destination_socket, request, request_length) == -1) {
      perror("write");
      close(client_socket);
      close(destination_socket);
      continue;
    }

    // Read the response from the destination server.
    char response[MAX_RESPONSE_SIZE];
    int response_length = read(destination_socket, response, MAX_RESPONSE_SIZE);
    if (response_length == -1) {
      perror("read");
      close(client_socket);
      close(destination_socket);
      continue;
    }

    // Send the response to the client.
    if (write(client_socket, response, response_length) == -1) {
      perror("write");
      close(client_socket);
      close(destination_socket);
      continue;
    }

    // Close the client socket.
    close(client_socket);

    // Close the destination socket.
    close(destination_socket);
  }

  // Close the listening socket.
  close(listening_socket);

  return 0;
}