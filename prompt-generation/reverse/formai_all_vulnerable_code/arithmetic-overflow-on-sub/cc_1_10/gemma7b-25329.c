//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

int main()
{
  // Socket setup
  int sockfd, newsockfd;
  struct sockaddr_in server_addr, client_addr;

  // QoS monitoring variables
  int packets_sent = 0;
  int packets_received = 0;
  double average_delay = 0.0;
  time_t start_time, end_time;

  // Loop to handle clients
  while (1)
  {
    // Accept connection
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);

    // Monitor packet statistics
    packets_sent++;
    packets_received++;

    // Calculate packet delay
    start_time = time(NULL);
    send(newsockfd, "Hello, client!", MAX_PACKET_SIZE, 0);
    end_time = time(NULL);
    double delay = (double)(end_time - start_time) * 1000.0;
    average_delay += delay;

    // Close connection
    close(newsockfd);
  }

  // Print QoS statistics
  printf("Packets sent: %d\n", packets_sent);
  printf("Packets received: %d\n", packets_received);
  printf("Average delay: %.2f ms\n", average_delay / packets_received);

  return 0;
}