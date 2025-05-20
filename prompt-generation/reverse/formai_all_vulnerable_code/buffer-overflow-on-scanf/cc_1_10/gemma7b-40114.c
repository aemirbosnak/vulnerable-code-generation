//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PINGS 5
#define BUFFER_SIZE 1024

int main() {
  int i, sockfd, port, status, count = 0;
  char hostname[256], buffer[BUFFER_SIZE];
  struct sockaddr_in serv_addr;

  // Get the hostname from the user
  printf("Enter the hostname: ");
  scanf("%s", hostname);

  // Set the port number
  port = 5000;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));

  // Connect to the server
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = inet_addr(hostname);

  // Send a ping message
  for (i = 0; i < MAX_PINGS; i++) {
    sprintf(buffer, "Ping %d", i + 1);
    sendto(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Receive the reply
    recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&serv_addr, NULL);

    // Print the reply
    printf("Reply from %s: %s\n", hostname, buffer);

    // Increment the count if the ping was successful
    if (strcmp(buffer, "Alive") == 0) {
      count++;
    }
  }

  // Print the number of successful pings
  printf("Number of successful pings: %d\n", count);

  // Close the socket
  close(sockfd);

  return 0;
}