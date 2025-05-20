//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 5555
#define IP_ADDRESS "192.168.1.100"

int main() {
  // Create a socket for communication
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Set up the server address
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, IP_ADDRESS, &server_addr.sin_addr) <= 0) {
    perror("invalid IP address");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connection failed");
    exit(EXIT_FAILURE);
  }

  // Main control loop
  while (1) {
    // Get the user input
    printf("Enter command (w/a/s/d/q): ");
    char command[2];
    scanf("%s", command);

    // Send the command to the server
    if (send(sockfd, command, strlen(command), 0) < 0) {
      perror("send failed");
      exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
      perror("recv failed");
      exit(EXIT_FAILURE);
    }

    // Print the response
    printf("Response: %s\n", response);

    // Check if the user wants to quit
    if (strcmp(command, "q") == 0) {
      break;
    }
  }

  // Close the socket
  close(sockfd);

  return 0;
}