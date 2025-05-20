//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
  int sockfd, clientfd, serverfd;
  struct sockaddr_in client_addr, server_addr;
  char buffer[MAX_BUFFER_SIZE];
  int nread, nwrite;
  char host[256], port[6];

  printf("Enter host name: ");
  scanf("%s", host);

  printf("Enter port number: ");
  scanf("%s", port);

  serverfd = socket(AF_INET, SOCK_STREAM, htons(80));
  if (serverfd == -1)
  {
    perror("Error creating socket");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(port));
  server_addr.sin_addr.s_addr = inet_addr(host);

  if (bind(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
  {
    perror("Error binding socket");
    exit(1);
  }

  clientfd = accept(serverfd, (struct sockaddr *)&client_addr, NULL);
  if (clientfd == -1)
  {
    perror("Error accepting client connection");
    exit(1);
  }

  nread = read(clientfd, buffer, MAX_BUFFER_SIZE);
  if (nread > 0)
  {
    nwrite = write(clientfd, buffer, nread);
    if (nwrite == -1)
    {
      perror("Error writing to client");
    }
  }

  close(clientfd);
  close(serverfd);

  return 0;
}