//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>

#define SERVER_PORT 5000
#define MAX_BUFFER_SIZE 1024

int main() {
  int sockfd, client_sockfd, new_sockfd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[MAX_BUFFER_SIZE];
  int bytes_read, bytes_written;
  struct timeval tv_start, tv_end;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  // Bind the socket to a port
  server_addr.sin_port = htons(SERVER_PORT);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    return 1;
  }

  // Listen for clients
  new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
  if (new_sockfd < 0) {
    perror("Error accepting client");
    return 1;
  }

  // Start the timer
  gettimeofday(&tv_start, NULL);

  // Read data from the client
  bytes_read = read(new_sockfd, buffer, MAX_BUFFER_SIZE);
  if (bytes_read < 0) {
    perror("Error reading data");
    return 1;
  }

  // Write data to the client
  bytes_written = write(new_sockfd, buffer, bytes_read);
  if (bytes_written < 0) {
    perror("Error writing data");
    return 1;
  }

  // Stop the timer
  gettimeofday(&tv_end, NULL);

  // Calculate the time taken
  long time_taken = tv_end.tv_sec - tv_start.tv_sec + (tv_end.tv_usec - tv_start.tv_usec) / 1000000;

  // Print the time taken
  printf("Time taken: %ld milliseconds\n", time_taken);

  // Close the socket
  close(new_sockfd);
  close(sockfd);

  return 0;
}