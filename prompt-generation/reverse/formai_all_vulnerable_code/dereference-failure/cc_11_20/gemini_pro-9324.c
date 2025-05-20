//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
  // Create the enchanted socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to a celestial port
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
    perror("Socket bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming whispers
  if (listen(sockfd, 10) == -1) {
    perror("Socket listen failed");
    exit(EXIT_FAILURE);
  }

  // Accept a connection from the mortal realm
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  int clientfd = accept(sockfd, (struct sockaddr*) &client_addr, &client_len);
  if (clientfd == -1) {
    perror("Socket accept failed");
    exit(EXIT_FAILURE);
  }

  // Send a warm greeting to the mortal
  char* greeting = "Greetings, mortal! I am the enchanted socket.";
  if (send(clientfd, greeting, strlen(greeting), 0) == -1) {
    perror("Socket send failed");
    exit(EXIT_FAILURE);
  }

  // Receive a message from the mortal
  char buffer[1024];
  int bytes_received = recv(clientfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("Socket receive failed");
    exit(EXIT_FAILURE);
  }

  // Parse the mortal's message
  char* command = strtok(buffer, " ");
  char* argument = strtok(NULL, " ");

  // Respond to the mortal's command
  if (strcmp(command, "wisdom") == 0) {
    char* wisdom = "The wise socket knows that knowledge is a precious gem.";
    if (send(clientfd, wisdom, strlen(wisdom), 0) == -1) {
      perror("Socket send failed");
      exit(EXIT_FAILURE);
    }
  } else if (strcmp(command, "power") == 0) {
    char* power = "The enchanted socket commands the flow of data through arcane arts.";
    if (send(clientfd, power, strlen(power), 0) == -1) {
      perror("Socket send failed");
      exit(EXIT_FAILURE);
    }
  } else {
    char* unknown = "Thy command bewilders the enchanted socket. Please seek guidance from the ancient texts.";
    if (send(clientfd, unknown, strlen(unknown), 0) == -1) {
      perror("Socket send failed");
      exit(EXIT_FAILURE);
    }
  }

  // Close the connection and return to the ethereal realm
  close(clientfd);
  close(sockfd);
  return 0;
}