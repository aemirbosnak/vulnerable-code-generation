//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define TIMEOUT_SECONDS 5

int main() {
  int sockfd, sin_port, client_len, recv_len, send_len;
  struct sockaddr_in sin;
  struct sockaddr_in client_sin;
  char buffer[MAX_PACKET_SIZE];
  time_t start_time, end_time, total_time;
  int packets_sent = 0, packets_received = 0;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, htons(8));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  sin.sin_port = htons(65432);
  if (bind(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  while (1) {
    // Get the client's address and port number
    client_len = sizeof(client_sin);
    recv_len = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&client_sin, &client_len);

    // Check if the packet was received successfully
    if (recv_len > 0) {
      packets_received++;
    }

    // Send a reply
    send_len = sendto(sockfd, buffer, recv_len, 0, (struct sockaddr *)&client_sin, client_len);
    packets_sent++;

    // Measure the time taken to send and receive the packet
    start_time = time(NULL);
    send_len = sendto(sockfd, buffer, recv_len, 0, (struct sockaddr *)&client_sin, client_len);
    end_time = time(NULL);
    total_time = end_time - start_time;

    // Print the results
    printf("Packet sent: %d, Packet received: %d, Time taken: %.2f seconds\n", packets_sent, packets_received, total_time);
  }

  return 0;
}