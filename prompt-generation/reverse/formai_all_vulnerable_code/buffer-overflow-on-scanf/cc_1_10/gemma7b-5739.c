//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PINGS 10
#define BUFFER_SIZE 128

int main()
{

  int sockfd, port, n, i, j;
  struct sockaddr_in serv_addr;
  char buffer[BUFFER_SIZE];

  printf("Enter the port number: ");
  scanf("%d", &port);

  sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
  if (sockfd < 0)
  {
    perror("Error creating socket");
    exit(1);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = inet_addr("localhost");

  for (i = 0; i < MAX_PINGS; i++)
  {
    n = sendto(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (n < 0)
    {
      perror("Error sending message");
      exit(1);
    }

    n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&serv_addr, NULL);
    if (n < 0)
    {
      perror("Error receiving message");
      exit(1);
    }

    printf("Ping: %d, Response: %s\n", i + 1, buffer);
  }

  close(sockfd);
  return 0;
}