//GEMINI-pro DATASET v1.0 Category: Networking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[BUF_SIZE];
  struct sockaddr_in serv_addr, cli_addr;

  // Check for proper usage
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  // Initialize the server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  // Create the server socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for client connections
  if (listen(sockfd, 5) < 0) {
    perror("Error listening for clients");
    exit(1);
  }

  // Accept client connections
  while (1) {
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("Error accepting client connection");
      continue;
    }

    // Fork a child process to handle the client
    pid_t pid = fork();
    if (pid < 0) {
      perror("Error forking child process");
      continue;
    }

    if (pid == 0) {
      // Child process
      close(sockfd);

      // Receive the message from the client
      memset(buffer, 0, BUF_SIZE);
      ssize_t n = recv(newsockfd, buffer, BUF_SIZE - 1, 0);
      if (n < 0) {
        perror("Error receiving message from client");
        exit(1);
      }

      // Print the message
      printf("Received message from client: %s\n", buffer);

      // Send a response to the client
      const char *response = "Hello from the server!";
      n = send(newsockfd, response, strlen(response), 0);
      if (n < 0) {
        perror("Error sending response to client");
        exit(1);
      }

      // Close the client connection
      close(newsockfd);
      exit(0);
    } else {
      // Parent process
      close(newsockfd);
    }
  }

  // Close the server socket
  close(sockfd);

  return 0;
}