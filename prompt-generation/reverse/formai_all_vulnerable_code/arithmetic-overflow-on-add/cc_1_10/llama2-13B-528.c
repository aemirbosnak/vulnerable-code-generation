//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
  int sock1, sock2;
  struct sockaddr_in server_addr, client_addr;
  char buffer[1024];
  int bytes_sent, bytes_received;

  // Create the socket
  sock1 = socket(AF_INET, SOCK_STREAM, 0);
  if (sock1 < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Set up the server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // Bind the socket to the address and port
  if (bind(sock1, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(sock1, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  // Accept an incoming connection
  sock2 = accept(sock1, (struct sockaddr *)&client_addr, &bytes_received);
  if (sock2 < 0) {
    perror("accept failed");
    exit(EXIT_FAILURE);
  }

  // Send the first number to the client
  sprintf(buffer, "%d", 10);
  bytes_sent = send(sock2, buffer, strlen(buffer), 0);
  if (bytes_sent < 0) {
    perror("send failed");
    exit(EXIT_FAILURE);
  }

  // Receive the second number from the client
  bytes_received = recv(sock2, buffer, 1024, 0);
  if (bytes_received < 0) {
    perror("recv failed");
    exit(EXIT_FAILURE);
  }
  printf("Received %d from client\n", atoi(buffer));

  // Calculate the sum of the two numbers
  int sum = 10 + atoi(buffer);
  printf("Sum = %d\n", sum);

  // Send the sum back to the client
  sprintf(buffer, "%d", sum);
  bytes_sent = send(sock2, buffer, strlen(buffer), 0);
  if (bytes_sent < 0) {
    perror("send failed");
    exit(EXIT_FAILURE);
  }

  // Close the sockets
  close(sock1);
  close(sock2);

  return 0;
}