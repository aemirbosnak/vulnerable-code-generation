//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
  int sock, conn_sock;
  struct sockaddr_in server, client;
  char buffer[1024];
  int num1, num2, sum;

  // Initialize socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    exit(1);
  }

  // Set up server socket
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

  // Bind server socket
  if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("Bind failed");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sock, 3) < 0) {
    perror("Listen failed");
    exit(1);
  }

  // Accept incoming connection
  conn_sock = accept(sock, (struct sockaddr *)&client, NULL);
  if (conn_sock < 0) {
    perror("Accept failed");
    exit(1);
  }

  // Read num1 from client
  read(conn_sock, &num1, sizeof(num1));
  printf("Received num1: %d\n", num1);

  // Read num2 from client
  read(conn_sock, &num2, sizeof(num2));
  printf("Received num2: %d\n", num2);

  // Calculate sum
  sum = num1 + num2;
  printf("Sum: %d\n", sum);

  // Send sum to client
  send(conn_sock, &sum, sizeof(sum), 0);

  // Close sockets
  close(sock);
  close(conn_sock);

  return 0;
}