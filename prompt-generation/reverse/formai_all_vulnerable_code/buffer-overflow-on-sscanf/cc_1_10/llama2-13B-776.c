//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

int main(int argc, char *argv[]) {
  // Initialize variables
  int sock, port, i, j;
  struct sockaddr_in server_addr;
  char buffer[1024];

  // Check if the user entered a port range
  if (argc < 2) {
    printf("Error: Please enter a port range, e.g. 'scan 1-65535'\n");
    return 1;
  }

  // Parse the port range
  char *range = argv[1];
  int start, end;
  sscanf(range, "%d-%d", &start, &end);

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    return 2;
  }

  // Set up the server address structure
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(0);

  // Bind the socket to the address and port
  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Binding failed");
    return 3;
  }

  // Listen for incoming connections
  if (listen(sock, 3) < 0) {
    perror("Listening failed");
    return 4;
  }

  // Enter the port scanning loop
  for (port = start; port <= end; port++) {
    // Connect to the target port
    if ((connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)) {
      perror("Connection failed");
      continue;
    }

    // Send a happy greeting
    sprintf(buffer, "Hello there, port %d! 😊", port);
    send(sock, buffer, strlen(buffer), 0);

    // Receive a response (if any)
    recv(sock, buffer, 1024, 0);

    // Print the response (if any)
    printf("Received from port %d: %s\n", port, buffer);

    // Close the connection
    close(sock);
  }

  // Close the socket
  close(sock);

  return 0;
}