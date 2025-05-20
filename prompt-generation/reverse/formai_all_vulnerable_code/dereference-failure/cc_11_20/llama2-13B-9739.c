//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_CLIENTS 10

int main() {
  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Set address and port
  struct sockaddr_in server_addr = {
    .sin_family = AF_INET,
    .sin_port = htons(1234),
    .sin_addr.s_addr = INADDR_ANY
  };

  // Bind the socket
  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Binding failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(sock, MAX_CLIENTS) < 0) {
    perror("Listening failed");
    exit(EXIT_FAILURE);
  }

  printf("Port scanner listening on port %d...\n", server_addr.sin_port);

  // Accept incoming connections
  int client_sock = accept(sock, NULL, NULL);
  if (client_sock < 0) {
    perror("Accept failed");
    exit(EXIT_FAILURE);
  }

  // Print client IP and port
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  getpeername(client_sock, (struct sockaddr *)&client_addr, &client_len);
  printf("Client connected from IP %s and port %d\n",
         inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

  // Close the client socket
  close(client_sock);

  // Scan for open ports on the target machine
  for (int i = 1; i <= PORT_RANGE; i++) {
    struct sockaddr_in target_addr = {
      .sin_family = AF_INET,
      .sin_port = htons(i),
      .sin_addr.s_addr = INADDR_ANY
    };

    int attempt = 0;

    do {
      // Try to connect to the target port
      int try_sock = socket(AF_INET, SOCK_STREAM, 0);
      if (try_sock < 0) {
        attempt++;
        if (attempt > 3) {
          break;
        }
        usleep(100000); // Wait for 100ms before trying again
        continue;
      }

      // Set address and port
      struct sockaddr_in *target = (struct sockaddr_in *)&try_sock;
      *target = target_addr;

      // Connect to the target port
      if (connect(try_sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
        close(try_sock);
        attempt++;
        if (attempt > 3) {
          break;
        }
        usleep(100000); // Wait for 100ms before trying again
        continue;
      }

      // If we made it here, the port is open!
      printf("Port %d is open on target IP %s\n", i, inet_ntoa(target_addr.sin_addr));
      close(try_sock);
      break;
    } while (1);
  }

  // Close the listening socket
  close(sock);

  return 0;
}