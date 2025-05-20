//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

int main()
{
  int sockfd, newsockfd, clientlen, recv_len, send_len;
  struct sockaddr_in serv_addr, client_addr;
  char buffer[MAX_PACKET_SIZE];
  time_t start_time, end_time, total_time;
  float rtt, utilization;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
  if (sockfd < 0)
  {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8080);
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  clientlen = sizeof(client_addr);
  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
  if (newsockfd < 0)
  {
    perror("Error accepting client");
    exit(1);
  }

  // Start the timer
  start_time = time(NULL);

  // Receive data from the client
  recv_len = recv(newsockfd, buffer, MAX_PACKET_SIZE, 0);
  if (recv_len < 0)
  {
    perror("Error receiving data");
    exit(1);
  }

  // End the timer
  end_time = time(NULL);

  // Calculate the total time
  total_time = end_time - start_time;

  // Calculate the RTT
  rtt = (total_time * 1000) / recv_len;

  // Calculate the utilization
  utilization = (recv_len * 100) / MAX_PACKET_SIZE;

  // Print the results
  printf("Client IP: %s\n", client_addr.sin_addr.s_addr);
  printf("RTT: %.2f ms\n", rtt);
  printf("Utilization: %.2f%\n", utilization);

  // Close the socket
  close(newsockfd);

  return 0;
}