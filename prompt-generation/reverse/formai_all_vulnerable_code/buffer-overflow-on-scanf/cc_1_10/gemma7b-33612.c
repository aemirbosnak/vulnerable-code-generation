//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define SERVER_HOST "localhost"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define NUM_PINGS 5

int main()
{
  int sockfd, i, j, status, port;
  struct sockaddr_in server_addr;
  char buffer[BUFFER_SIZE];

  // Configure the server port
  printf("Enter the server port: ");
  scanf("%d", &port);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
  if (sockfd < 0)
  {
    perror("Error creating socket");
    exit(1);
  }

  // Set up the server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(SERVER_HOST);

  // Send and receive pings
  for (i = 0; i < NUM_PINGS; i++)
  {
    // Send a ping
    sprintf(buffer, "Ping!");
    sendto(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Receive a response
    recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, NULL);

    // Print the response
    printf("Response: %s\n", buffer);
  }

  // Close the socket
  close(sockfd);

  return 0;
}