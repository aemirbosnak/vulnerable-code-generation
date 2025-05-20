//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PINGS 10

int main()
{
  int sockfd, port, n, i;
  struct sockaddr_in servaddr;
  char buf[1024];

  printf("Enter port number: ");
  scanf("%d", &port);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0)
  {
    perror("Error creating socket");
    exit(1);
  }

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  for (i = 0; i < MAX_PINGS; i++)
  {
    n = write(sockfd, "PING", 5);
    if (n < 0)
    {
      perror("Error sending ping");
      exit(1);
    }

    n = read(sockfd, buf, 1024);
    if (n < 0)
    {
      perror("Error receiving ping");
      exit(1);
    }

    printf("Received: %s\n", buf);
  }

  close(sockfd);
  return 0;
}