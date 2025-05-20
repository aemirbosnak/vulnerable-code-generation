//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define TIMEOUT 1000

int main() {
  int sockfd, sin_port, nbytes, server_port, client_addr_len;
  struct sockaddr_in client_addr, server_addr;
  char buffer[1024];
  time_t start_time, end_time, elapsed_time;
  double avg_delay = 0, total_delay = 0;

  // Server port number
  server_port = 8080;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(server_port));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  server_addr.sin_port = htons(server_port);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Wait for a client connection
  client_addr_len = sizeof(client_addr);
  sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);

  // Start the timer
  start_time = time(NULL);

  // Receive data from the client
  nbytes = recv(sockfd, buffer, 1024, 0);

  // End the timer
  end_time = time(NULL);

  // Calculate the elapsed time
  elapsed_time = end_time - start_time;

  // Calculate the delay
  total_delay += elapsed_time * nbytes;

  // Calculate the average delay
  avg_delay = total_delay / nbytes;

  // Print the results
  printf("Client IP: %s\n", client_addr.sin_addr.s_addr);
  printf("Average delay: %.2f milliseconds\n", avg_delay);

  // Close the socket
  close(sockfd);

  return 0;
}