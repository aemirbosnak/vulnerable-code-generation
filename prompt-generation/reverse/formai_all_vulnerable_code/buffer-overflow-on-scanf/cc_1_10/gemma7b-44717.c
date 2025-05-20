//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
  int sockfd, port, n, i, target_port, found = 0;
  char buffer[1024], target_ip[256];

  printf("Enter target IP: ");
  scanf("%s", target_ip);

  printf("Enter target port: ");
  scanf("%d", &target_port);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(8));
  if (sockfd < 0)
  {
    perror("Error creating socket");
    exit(1);
  }

  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(target_port);
  serv_addr.sin_addr.s_addr = inet_addr(target_ip);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    perror("Error connecting to server");
    exit(1);
  }

  printf("Scanning ports...\n");

  for (port = 1; port <= 65535; port++)
  {
    send(sockfd, "SCANNING", 8, 0);
    n = recv(sockfd, buffer, 1024, 0);

    if (n > 0)
    {
      if (strcmp(buffer, "FOUND") == 0)
      {
        found = 1;
        printf("Port %d is open.\n", port);
      }
    }
  }

  if (!found)
  {
    printf("No ports are open.\n");
  }

  close(sockfd);

  return 0;
}