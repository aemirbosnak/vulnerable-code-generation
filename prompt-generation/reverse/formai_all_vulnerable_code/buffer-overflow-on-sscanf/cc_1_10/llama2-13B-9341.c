//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
  int sock, client_sock;
  struct sockaddr_in server, client;
  socklen_t client_len = sizeof(client);
  char buffer[256];

  // Create the server socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Set up the server address
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(PORT);

  // Bind the server socket
  if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(sock, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d...\n", PORT);

  while (1) {
    // Accept an incoming connection
    client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
    if (client_sock < 0) {
      perror("accept failed");
      exit(EXIT_FAILURE);
    }

    // Read data from the client
    read(client_sock, buffer, 256);
    printf("Client message: %s\n", buffer);

    // Solve the math problem and send the solution back to the client
    int num1, num2, result;
    sscanf(buffer, "%d%d=%d", &num1, &num2, &result);
    printf("Result: %d\n", result);
    send(client_sock, "Solution: %d", result, 0);

    // Close the client socket
    close(client_sock);
  }

  return 0;
}