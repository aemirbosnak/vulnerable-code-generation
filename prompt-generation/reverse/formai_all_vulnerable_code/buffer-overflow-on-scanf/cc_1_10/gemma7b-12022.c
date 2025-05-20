//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
  int sockfd, port, n, status, ping_status;
  char hostname[256], buffer[1024];

  printf("Enter the hostname of the server: ");
  scanf("%s", hostname);

  printf("Enter the port number of the server: ");
  scanf("%d", &port);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0)
  {
    perror("Error creating socket");
    exit(1);
  }

  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  inet_aton(hostname, &serv_addr.sin_addr);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    perror("Error connecting to server");
    exit(1);
  }

  ping_status = 0;
  while (1)
  {
    n = recv(sockfd, buffer, 1024, 0);
    if (n < 0)
    {
      perror("Error receiving data");
      exit(1);
    }

    if (strcmp(buffer, "PING") == 0)
    {
      ping_status = 1;
      printf("Server is alive.\n");
    }

    if (strcmp(buffer, "BYE") == 0)
    {
      printf("Server is shutting down.\n");
      break;
    }

    send(sockfd, buffer, n, 0);
  }

  close(sockfd);
  return 0;
}