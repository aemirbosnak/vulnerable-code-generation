//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Turing
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5

int main() {
  int sockfd, client_sockfd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUFFER_SIZE];
  time_t start_time, end_time;
  int bytes_read;
  float rtt_ms;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  server_addr.sin_port = htons(5000);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Wait for a client connection
  client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
  if (client_sockfd < 0) {
    perror("Error accepting client connection");
    exit(1);
  }

  // Start the timer
  start_time = time(NULL);

  // Read data from the client
  bytes_read = read(client_sockfd, buffer, BUFFER_SIZE);
  if (bytes_read < 0) {
    perror("Error reading data");
    exit(1);
  }

  // End the timer
  end_time = time(NULL);

  // Calculate the round-trip time (RTT)
  rtt_ms = (end_time - start_time) * 1000.0;

  // Print the RTT
  printf("RTT: %.2f ms\n", rtt_ms);

  // Close the client socket
  close(client_sockfd);

  // Close the server socket
  close(sockfd);

  return 0;
}