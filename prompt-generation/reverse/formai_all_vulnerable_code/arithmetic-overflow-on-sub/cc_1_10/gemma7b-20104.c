//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
  int sockfd, newsockfd, client_len;
  struct sockaddr_in serv_addr, client_addr;
  char buffer[BUFFER_SIZE];
  clock_t start, end;
  double time_taken;
  int bytes_received;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SERVER_PORT);
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  client_len = sizeof(client_addr);
  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
  if (newsockfd < 0) {
    perror("Error accepting client");
    exit(1);
  }

  // Start the timer
  start = clock();

  // Receive data from the client
  bytes_received = recv(newsockfd, buffer, BUFFER_SIZE, 0);
  if (bytes_received < 0) {
    perror("Error receiving data");
    exit(1);
  }

  // Stop the timer
  end = clock();

  // Calculate the time taken
  time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  // Print the results
  printf("Time taken: %.2f seconds\n", time_taken);
  printf("Number of bytes received: %d\n", bytes_received);

  // Close the socket
  close(newsockfd);
  close(sockfd);

  return 0;
}