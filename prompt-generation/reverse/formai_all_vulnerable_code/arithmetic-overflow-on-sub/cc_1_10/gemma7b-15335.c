//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: minimalist
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <time.h>

#define SERVER_PORT 5000

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[1024];
  time_t start_time, end_time;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  // Bind the socket to a port
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    return 1;
  }

  // Listen for connections
  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
  if (newsockfd < 0) {
    perror("Error accepting connection");
    return 1;
  }

  // Start the timer
  start_time = time(NULL);

  // Receive data
  recv(newsockfd, buffer, 1024, 0);

  // End the timer
  end_time = time(NULL);

  // Calculate the time taken
  int time_taken = end_time - start_time;

  // Print the time taken
  printf("Time taken: %d seconds\n", time_taken);

  // Close the connection
  close(newsockfd);

  return 0;
}