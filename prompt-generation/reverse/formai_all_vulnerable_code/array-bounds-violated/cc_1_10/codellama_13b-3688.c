//Code Llama-13B DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5

int main(int argc, char *argv[]) {
  int sockfd, new_fd;
  struct sockaddr_in server_addr, client_addr;
  socklen_t sin_size = sizeof(client_addr);
  char buffer[1024];

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Error creating socket!\n");
    return 1;
  }

  // Setup server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Bind and listen
  if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    printf("Error binding!\n");
    return 1;
  }
  listen(sockfd, MAX_CLIENTS);

  // Accept clients
  while (1) {
    new_fd = accept(sockfd, (struct sockaddr*)&client_addr, &sin_size);
    if (new_fd == -1) {
      printf("Error accepting client!\n");
      return 1;
    }

    // Receive and print data
    int n = recv(new_fd, buffer, 1024, 0);
    if (n < 0) {
      printf("Error receiving data!\n");
      return 1;
    }
    buffer[n] = '\0';
    printf("Received: %s\n", buffer);

    // Send response
    char response[] = "Hello, client!";
    n = send(new_fd, response, strlen(response), 0);
    if (n < 0) {
      printf("Error sending data!\n");
      return 1;
    }

    // Close client socket
    close(new_fd);
  }

  return 0;
}