//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_PINGS 10
#define TIMEOUT 2

int main()
{
  int i, sockfd, port, status, attempts = 0;
  char host[256];

  printf("Enter host name: ");
  scanf("%s", host);

  for (i = 0; i < MAX_PINGS && attempts < MAX_PINGS; i++)
  {
    port = 53;
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    if (sockfd == -1)
    {
      perror("Error creating socket");
      exit(1);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
      perror("Error connecting to server");
      attempts++;
    }
    else
    {
      status = send(sockfd, "PING", 5, 0);
      if (status == -1)
      {
        perror("Error sending ping");
      }
      else
      {
        char reply[1024];
        recv(sockfd, reply, 1024, 0);
        printf("Reply: %s\n", reply);
      }

      close(sockfd);
    }
  }

  if (attempts == MAX_PINGS)
  {
    printf("Sorry, but the host is unreachable.\n");
  }

  return 0;
}