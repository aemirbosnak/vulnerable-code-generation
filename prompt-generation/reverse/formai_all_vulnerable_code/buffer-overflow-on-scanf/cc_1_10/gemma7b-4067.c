//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024

int main() {
  int sockfd, newsockfd, port, clientlen;
  struct sockaddr_in serv_addr, client_addr;
  char buffer[BUFFER_SIZE];
  time_t start, end, duration;
  int packets_sent = 0, packets_received = 0;

  // Set up the server socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the server socket to a port
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8080);
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  while (1) {
    // Accept a client connection
    clientlen = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
    if (newsockfd < 0) {
      perror("Error accepting client connection");
      continue;
    }

    // Start the timer
    start = time(NULL);

    // Send and receive packets
    while (1) {
      // Send a packet
      printf("Enter packet content: ");
      scanf("%s", buffer);
      send(newsockfd, buffer, BUFFER_SIZE, 0);
      packets_sent++;

      // Receive a packet
      recv(newsockfd, buffer, BUFFER_SIZE, 0);
      packets_received++;
    }

    // End the timer
    end = time(NULL);
    duration = end - start;

    // Calculate the average packet loss
    int packet_loss = (packets_sent - packets_received) * 100 / packets_sent;

    // Print the results
    printf("Client connection successful!\n");
    printf("Number of packets sent: %d\n", packets_sent);
    printf("Number of packets received: %d\n", packets_received);
    printf("Duration: %d seconds\n", duration);
    printf("Packet loss: %d%\n", packet_loss);
    printf("------------------------\n");

    // Close the client connection
    close(newsockfd);
  }

  return 0;
}