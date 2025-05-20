//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PINGS 10

int main()
{
  int i, sockfd, port, status, attempts = 0;
  char hostname[256];
  struct sockaddr_in server_addr;

  printf("Enter the hostname: ");
  scanf("%s", hostname);

  printf("Enter the port number: ");
  scanf("%d", &port);

  for (i = 0; i < MAX_PINGS; i++)
  {
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));

    if (sockfd < 0)
    {
      perror("Error creating socket");
      exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    status = sendto(sockfd, "PING", 4, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (status < 0)
    {
      perror("Error sending ping");
      close(sockfd);
      attempts++;
    }
    else
    {
      close(sockfd);
      break;
    }
  }

  if (attempts == MAX_PINGS)
  {
    printf("Error: unable to reach host.\n");
  }
  else
  {
    printf("Ping successful.\n");
  }

  return 0;
}