//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

int main() {
  int sockfd, clientfd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[MAX_PACKET_SIZE];
  int bytes_received, packets_received = 0, time_start, time_end, total_time = 0;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
  if (sockfd == -1) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(5000);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  clientfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
  if (clientfd == -1) {
    perror("Error accepting client");
    exit(1);
  }

  // Start the timer
  time_start = time(NULL);

  // Receive packets
  while (1) {
    bytes_received = recv(clientfd, buffer, MAX_PACKET_SIZE, 0);
    if (bytes_received == -1) {
      perror("Error receiving packet");
      break;
    }

    packets_received++;
  }

  // End the timer
  time_end = time(NULL);

  // Calculate the total time
  total_time = time_end - time_start;

  // Print the results
  printf("Number of packets received: %d\n", packets_received);
  printf("Total time: %d seconds\n", total_time);
  printf("Average packet delay: %.2f milliseconds\n", (total_time * 1000) / packets_received);

  // Close the socket
  close(sockfd);

  return 0;
}