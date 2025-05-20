//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <time.h>

#define MAX_PINGS 10
#define TIMEOUT_MS 1000

int main() {
  int sockfd, i, j, ping_num = 0, status;
  struct sockaddr_in servaddr;
  char buf[1024];
  time_t start_time, end_time;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, htons(8));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Set up the server address
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(8888);
  servaddr.sin_addr.s_addr = inet_addr("192.168.1.1");

  // Send and receive pings
  for (i = 0; i < MAX_PINGS; i++) {
    start_time = time(NULL);

    // Send a ping
    sendto(sockfd, "PING", 5, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Receive the ping response
    recvfrom(sockfd, buf, 1024, 0, (struct sockaddr *)&servaddr, NULL);

    end_time = time(NULL);

    // Calculate the ping time
    status = end_time - start_time;

    // Print the ping time
    printf("Ping %d: %d ms\n", ping_num, status);

    ping_num++;
  }

  // Close the socket
  close(sockfd);

  return 0;
}