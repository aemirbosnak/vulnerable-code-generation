//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888

// Server side
int main() {
  int sock;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(sock, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d...\n", PORT);

  int client_sock;
  while (1) {
    client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
      perror("accept failed");
      exit(EXIT_FAILURE);
    }

    // Client side
    int num1, num2, sum;
    char op;

    // Read input from client
    read(client_sock, &op, 1);
    read(client_sock, &num1, sizeof(num1));
    read(client_sock, &num2, sizeof(num2));

    // Evaluate expression and send result to client
    if (op == '+') {
      sum = num1 + num2;
    } else if (op == '-') {
      sum = num1 - num2;
    } else if (op == '*') {
      sum = num1 * num2;
    } else if (op == '/') {
      sum = num1 / num2;
    } else {
      sum = -1; // invalid operation
    }

    write(client_sock, &sum, sizeof(sum));

    // Close client socket
    close(client_sock);
  }

  return 0;
}