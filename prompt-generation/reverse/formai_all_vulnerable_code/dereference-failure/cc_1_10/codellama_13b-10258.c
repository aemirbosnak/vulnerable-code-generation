//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define MAX_CLIENTS 5

// Struct to represent a client
typedef struct {
  int sock;
  struct sockaddr_in addr;
} Client;

// Function to create a socket
int create_socket() {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Failed to create socket");
    exit(1);
  }
  return sock;
}

// Function to bind a socket to a port
void bind_socket(int sock, int port) {
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    perror("Failed to bind socket");
    exit(1);
  }
}

// Function to listen for incoming connections
void listen_socket(int sock) {
  if (listen(sock, MAX_CLIENTS) < 0) {
    perror("Failed to listen on socket");
    exit(1);
  }
}

// Function to accept an incoming connection
Client accept_connection(int sock) {
  struct sockaddr_in addr;
  socklen_t addrlen = sizeof(addr);
  int new_sock = accept(sock, (struct sockaddr*)&addr, &addrlen);
  if (new_sock < 0) {
    perror("Failed to accept connection");
    exit(1);
  }
  Client client;
  client.sock = new_sock;
  client.addr = addr;
  return client;
}

// Function to send a message to a client
void send_message(int sock, const char* message) {
  send(sock, message, strlen(message), 0);
}

// Function to receive a message from a client
void receive_message(int sock, char* buffer, int buf_size) {
  recv(sock, buffer, buf_size, 0);
}

// Function to handle a client connection
void handle_client(Client client) {
  char buffer[BUF_SIZE];
  while (1) {
    receive_message(client.sock, buffer, BUF_SIZE);
    printf("Received message: %s\n", buffer);
    send_message(client.sock, "Hello, client!");
  }
}

int main(int argc, char* argv[]) {
  int port = 8000;
  if (argc > 1) {
    port = atoi(argv[1]);
  }

  int sock = create_socket();
  bind_socket(sock, port);
  listen_socket(sock);

  while (1) {
    Client client = accept_connection(sock);
    handle_client(client);
  }

  return 0;
}