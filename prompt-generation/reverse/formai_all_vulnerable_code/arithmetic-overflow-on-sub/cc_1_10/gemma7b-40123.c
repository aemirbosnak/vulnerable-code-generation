//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_HOSTS 100

int main() {
  int i, host_num, sockfd, status;
  char host[MAX_HOSTS][256];
  struct sockaddr_in serv_addr;
  time_t start_time, end_time;

  // Get the number of hosts to ping
  printf("Enter the number of hosts to ping: ");
  scanf("%d", &host_num);

  // Allocate memory for host names
  for (i = 0; i < host_num; i++) {
    host[i][0] = '\0';
  }

  // Get the host names
  printf("Enter the host names: ");
  for (i = 0; i < host_num; i++) {
    scanf("%s", host[i]);
  }

  // Start the timer
  start_time = time(NULL);

  // Ping each host
  for (i = 0; i < host_num; i++) {
    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(53));

    // Set up the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, host[i], &serv_addr.sin_addr);

    // Send a ping message
    sendto(sockfd, "PING", 5, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Receive the ping response
    char resp[1024];
    recvfrom(sockfd, resp, 1024, 0, (struct sockaddr *)&serv_addr, NULL);

    // Close the socket
    close(sockfd);

    // Print the ping response
    printf("Host: %s, Response: %s\n", host[i], resp);
  }

  // End the timer
  end_time = time(NULL);

  // Calculate the total time taken
  printf("Total time taken: %ld seconds\n", end_time - start_time);

  return 0;
}