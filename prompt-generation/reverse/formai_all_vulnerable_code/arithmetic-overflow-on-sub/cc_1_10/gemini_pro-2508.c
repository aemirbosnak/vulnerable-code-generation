//GEMINI-pro DATASET v1.0 Category: Networking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// A simple function to send a message to a socket
int send_message(int sockfd, char *message) {
  int len = strlen(message);
  int sent = 0;

  while (sent < len) {
    int n = send(sockfd, message + sent, len - sent, 0);
    if (n == -1) {
      return -1;
    }
    sent += n;
  }

  return 0;
}

// A simple function to receive a message from a socket
int receive_message(int sockfd, char *buffer, int len) {
  int received = 0;

  while (received < len) {
    int n = recv(sockfd, buffer + received, len - received, 0);
    if (n == -1) {
      return -1;
    }
    received += n;
  }

  return 0;
}

int main(int argc, char **argv) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Bind the socket to an address
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(5000);
  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for connections
  if (listen(sockfd, 5) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept a connection
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
  if (client_sockfd == -1) {
    perror("accept");
    return EXIT_FAILURE;
  }

  // Send a message to the client
  char *message = "Greetings, traveler! Welcome to my humble abode.";
  if (send_message(client_sockfd, message) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive a message from the client
  char buffer[1024];
  if (receive_message(client_sockfd, buffer, sizeof(buffer)) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the message from the client
  printf("The traveler says: %s\n", buffer);

  // Close the client socket
  close(client_sockfd);

  // Close the server socket
  close(sockfd);

  return EXIT_SUCCESS;
}