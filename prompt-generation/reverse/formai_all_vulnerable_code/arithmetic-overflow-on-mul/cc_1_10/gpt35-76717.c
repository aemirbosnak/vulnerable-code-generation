//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// S = {1,2}
typedef enum {ONE = 1, TWO = 2} set_t;

typedef struct {
  set_t s;  // s ∈ S
  int n;    // n ∈ ℤ
  char c;   // c ∈ Σ
} triple_t;

int main() {
  // Define socket address and port number
  struct sockaddr_in server_address;
  int port = 8080;

  // Create server socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Set server address and port
  memset(&server_address, '0', sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_port = htons(port);

  // Bind the server socket to the address and port
  bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

  // Listen for incoming connections
  listen(server_socket, 10);

  // Define client socket and address
  int client_socket;
  struct sockaddr_in client_address;
  int client_address_length = sizeof(client_address);

  // Accept incoming connection
  client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&client_address_length);

  // Receive data from client
  triple_t t;
  read(client_socket, &t, sizeof(t));

  // Process data
  switch(t.s) {
    case ONE:
      printf("%d\n", t.n * 2);
      break;
    case TWO:
      printf("%c\n", t.c + 1);
      break;
    default:
      printf("Invalid set\n");
  }

  // Send result back to client
  write(client_socket, &t, sizeof(t));

  // Close server and client sockets
  close(server_socket);
  close(client_socket);

  return 0;
}