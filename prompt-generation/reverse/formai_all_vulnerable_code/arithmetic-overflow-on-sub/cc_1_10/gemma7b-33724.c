//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: inquisitive
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define SERVER_PORT 8080

int main() {
  int sockfd, newsockfd, client_len;
  struct sockaddr_in server_addr, client_addr;
  char buffer[1024];
  int bytes_read, bytes_written;
  time_t start_time, end_time;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
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
  start_time = time(NULL);

  // Read data from the client
  bytes_read = read(newsockfd, buffer, 1024);
  if (bytes_read < 0) {
    perror("Error reading data");
    exit(1);
  }

  // Write data to the client
  bytes_written = write(newsockfd, buffer, bytes_read);
  if (bytes_written < 0) {
    perror("Error writing data");
    exit(1);
  }

  // End the timer
  end_time = time(NULL);

  // Calculate the time taken
  int time_taken = end_time - start_time;

  // Print the time taken
  printf("Time taken: %d seconds\n", time_taken);

  // Close the socket
  close(newsockfd);
  close(sockfd);

  return 0;
}