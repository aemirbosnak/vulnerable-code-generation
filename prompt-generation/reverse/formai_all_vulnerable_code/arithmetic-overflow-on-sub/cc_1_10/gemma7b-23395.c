//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define MONITOR_INTERVAL 1

int main() {
  int sockfd, newsockfd, clientlen;
  struct sockaddr_in servaddr, clientaddr;
  char packet[MAX_PACKET_SIZE];
  int packet_size, received_bytes, sent_bytes, total_bytes = 0, start_time, end_time, elapsed_time;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
  if (sockfd < 0) {
    perror("Error creating socket");
    return -1;
  }

  // Bind the socket
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(5000);
  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Error binding socket");
    return -1;
  }

  // Listen for clients
  clientlen = sizeof(clientaddr);
  newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientlen);
  if (newsockfd < 0) {
    perror("Error accepting client connection");
    return -1;
  }

  // Start the timer
  start_time = time(NULL);

  // Receive packets
  while (received_bytes = recv(newsockfd, packet, MAX_PACKET_SIZE, 0) > 0) {
    packet_size = received_bytes;
    total_bytes += packet_size;
  }

  // End the timer
  end_time = time(NULL);

  // Calculate elapsed time
  elapsed_time = end_time - start_time;

  // Print the results
  printf("Total bytes received: %d\n", total_bytes);
  printf("Elapsed time: %d seconds\n", elapsed_time);
  printf("Average packet size: %.2f bytes\n", (double)total_bytes / elapsed_time);

  // Close the socket
  close(newsockfd);
  close(sockfd);

  return 0;
}