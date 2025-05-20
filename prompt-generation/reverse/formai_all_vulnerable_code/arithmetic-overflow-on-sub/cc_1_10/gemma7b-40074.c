//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

int main() {
  int sockfd, sin_len, client_len;
  struct sockaddr_in server_addr, client_addr;
  char buffer[1024];
  time_t start_time, end_time, duration;
  int packets_sent = 0, packets_received = 0, loss_ratio = 0;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  server_addr.sin_port = htons(8080);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  sin_len = sizeof(client_addr);
  client_len = sizeof(client_addr);
  while (1) {
    // Accept a client connection
    sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (sockfd < 0) {
      perror("Error accepting client connection");
      continue;
    }

    // Start the timer
    start_time = time(NULL);

    // Send and receive packets
    while (1) {
      // Send a packet
      printf("Sent packet %d\n", packets_sent);
      send(sockfd, buffer, 1024, 0);
      packets_sent++;

      // Receive a packet
      recv(sockfd, buffer, 1024, 0);
      packets_received++;

      // Check if the client has closed the connection
      if (recv(sockfd, buffer, 1, 0) < 0) {
        break;
      }
    }

    // End the timer
    end_time = time(NULL);

    // Calculate the duration
    duration = end_time - start_time;

    // Calculate the loss ratio
    loss_ratio = (packets_sent - packets_received) * 100 / packets_sent;

    // Print the results
    printf("Client connection successful.\n");
    printf("Number of packets sent: %d\n", packets_sent);
    printf("Number of packets received: %d\n", packets_received);
    printf("Loss ratio: %d%%\n", loss_ratio);
    printf("Duration: %ld seconds\n", duration);

    // Close the socket
    close(sockfd);
  }

  return 0;
}