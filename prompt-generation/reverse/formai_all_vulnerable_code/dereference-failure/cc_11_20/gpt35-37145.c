//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_BUFFER_LEN 2048

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <proxy_port> <server_ip>\n", argv[0]);
    exit(1);
  }

  int proxy_port = atoi(argv[1]);
  char *server_ip = argv[2];

  // Create the socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock < 0) {
    perror("Failed to create socket");
    exit(1);
  }

  // Set Address
  struct sockaddr_in proxy_addr;
  proxy_addr.sin_family = AF_INET;
  proxy_addr.sin_port = htons(proxy_port);
  proxy_addr.sin_addr.s_addr = INADDR_ANY;

  // Bind socket to address
  if(bind(sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
    perror("Failed to bind");
    exit(1);
  }

  // Listen for connections
  listen(sock, 10);

  printf("Proxy listening on port: %d\n", proxy_port);

  while(1) {
    int client_sock = accept(sock, NULL, NULL);

    // Receive the request from the client
    char buffer[MAX_BUFFER_LEN];
    memset(buffer, 0, MAX_BUFFER_LEN);
    int n = recv(client_sock, buffer, MAX_BUFFER_LEN-1, 0);
    if(n < 0) {
      perror("recv failed");
      close(client_sock);
      continue;
    }

    printf("========================\n");
    printf("Received request:\n%s\n", buffer);

    // Create a new socket to communicate with the server
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock < 0) {
      perror("Failed to create server socket");
      close(client_sock);
      exit(1);
    }

    // Set the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    if(inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
      perror("inet_pton failed");
      close(client_sock);
      exit(1);
    }

    if(connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("Failed to connect to server");
      close(client_sock);
      exit(1);
    }

    // Send the request to the server
    if(send(server_sock, buffer, strlen(buffer), 0) < 0) {
      perror("Failed to send to server");
      close(client_sock);
      close(server_sock);
      exit(1);
    }

    // Receive the response from the server
    memset(buffer, 0, MAX_BUFFER_LEN);
    n = recv(server_sock, buffer, MAX_BUFFER_LEN, 0);
    if(n < 0) {
      perror("Failed to receive from server");
      close(client_sock);
      close(server_sock);
      continue;
    }

    printf("========================\n");
    printf("Received response:\n%s\n", buffer);

    // Send the response to the client
    if(send(client_sock, buffer, strlen(buffer), 0) < 0) {
      perror("Failed to send to client");
      close(client_sock);
      close(server_sock);
      break;
    }

    close(client_sock);
    close(server_sock);
  }

  return 0;
}