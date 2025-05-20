//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_PINGS 10
#define TIMEOUT 5

int main() {
  int i, sockfd, ping_count = 0, status, sent_bytes, recv_bytes;
  struct sockaddr_in serv_addr;
  char msg[1024], recv_msg[1024];
  time_t start_time, end_time;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, htons(8));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Set up the server address
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8888);
  serv_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

  // Send and receive pings
  for (i = 0; i < MAX_PINGS; i++) {
    start_time = time(NULL);

    // Send a ping message
    sprintf(msg, "Ping!");
    sent_bytes = sendto(sockfd, msg, sizeof(msg), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (sent_bytes < 0) {
      perror("Error sending ping");
      exit(1);
    }

    // Receive a ping response
    recv_bytes = recvfrom(sockfd, recv_msg, sizeof(recv_msg), 0, (struct sockaddr *)&serv_addr, NULL);
    if (recv_bytes < 0) {
      perror("Error receiving ping");
      exit(1);
    }

    end_time = time(NULL);

    // Calculate the ping time
    int ping_time = end_time - start_time;

    // Print the ping time
    printf("Ping: %d ms\n", ping_time);

    // Increment the ping count
    ping_count++;
  }

  // Print the number of pings
  printf("Total pings: %d\n", ping_count);

  // Close the socket
  close(sockfd);

  return 0;
}