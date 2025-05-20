//GEMINI-pro DATASET v1.0 Category: Networking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Recursive function to send data over a network
int send_data(int sockfd, char *buffer, int len) {
  if (len == 0) {
    return 0;
  } else {
    int sent = send(sockfd, buffer, len, 0);
    if (sent < 0) {
      perror("send");
      return -1;
    } else {
      return send_data(sockfd, buffer + sent, len - sent);
    }
  }
}

// Recursive function to receive data over a network
int receive_data(int sockfd, char *buffer, int len) {
  if (len == 0) {
    return 0;
  } else {
    int received = recv(sockfd, buffer, len, 0);
    if (received < 0) {
      perror("recv");
      return -1;
    } else {
      return receive_data(sockfd, buffer + received, len - received);
    }
  }
}

// Main function
int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Bind the socket to an address
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    return -1;
  }

  // Listen for connections
  if (listen(sockfd, 5) < 0) {
    perror("listen");
    return -1;
  }

  // Accept a connection
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_sockfd < 0) {
    perror("accept");
    return -1;
  }

  // Send data to the client
  char *buffer = "Hello, world!";
  int len = strlen(buffer);
  if (send_data(client_sockfd, buffer, len) < 0) {
    perror("send_data");
    return -1;
  }

  // Receive data from the client
  buffer = malloc(1024);
  len = 1024;
  if (receive_data(client_sockfd, buffer, len) < 0) {
    perror("receive_data");
    return -1;
  }

  // Print the data received from the client
  printf("Received: %s\n", buffer);

  // Close the connection
  close(client_sockfd);
  close(sockfd);

  return 0;
}