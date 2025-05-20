//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  // Welcome message
  printf("Greetings, my esteemed client. I am Sherlock Holmes, the world's greatest consulting detective.\n");
  printf("I understand you have a peculiar case that requires my assistance.\n");
  printf("Fear not, I am here to unravel the mystery and bring justice to light.\n\n");

  // Get the client's IP address
  char client_ip[INET_ADDRSTRLEN];
  printf("May I inquire as to your current location, my dear client?\n");
  scanf("%s", client_ip);

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to the client's IP address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(client_ip);
  server_addr.sin_port = htons(5000);
  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for connections
  if (listen(sock, 5) < 0) {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }

  // Accept a connection
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_sock < 0) {
    perror("Accept failed");
    exit(EXIT_FAILURE);
  }

  // Read the client's message
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));
  if (read(client_sock, buffer, sizeof(buffer)) < 0) {
    perror("Read failed");
    exit(EXIT_FAILURE);
  }

  // Print the client's message
  printf("The client says: %s\n", buffer);

  // Send a response to the client
  char response[] = "Your case has piqued my interest, my dear client. I shall commence my investigation forthwith.";
  if (write(client_sock, response, strlen(response)) < 0) {
    perror("Write failed");
    exit(EXIT_FAILURE);
  }

  // Close the client socket
  close(client_sock);

  // Close the server socket
  close(sock);

  return 0;
}