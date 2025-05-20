//FormAI DATASET v1.0 Category: Socket programming ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
  int client_sock, sock_len, read_size;
  struct sockaddr_in server_addr;
  char message[100];

  // Create socket
  client_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (client_sock == -1) {
    perror("Failed to create socket");
    exit(EXIT_FAILURE);
  }
  puts("Socket created!");

  // Set server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_addr.sin_port = htons(8888);

  // Connect to remote server
  if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Could not connect to server");
    exit(EXIT_FAILURE);
  }

  puts("Connected to server!");

  // Send message to server
  strcpy(message, "Hello server!");
  if (send(client_sock, message, strlen(message), 0) < 0) {
    perror("Failed to send message to server");
    exit(EXIT_FAILURE);
  }

  // Receive response from server
  sock_len = sizeof(server_addr);
  if ((read_size = recv(client_sock, message, 100, 0)) < 0) {
    perror("Failed to receive response from server");
    exit(EXIT_FAILURE);
  }
  message[read_size] = '\0';

  printf("Server response: %s\n", message);

  // Close socket
  close(client_sock);

  return 0;
}