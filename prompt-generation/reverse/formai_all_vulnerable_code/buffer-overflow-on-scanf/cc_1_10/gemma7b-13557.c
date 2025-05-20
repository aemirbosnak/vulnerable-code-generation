//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
  char host_name[255];
  int sock_fd;
  struct sockaddr_in sock_addr;
  struct hostent *host_entry;

  printf("Enter the host name: ");
  scanf("%s", host_name);

  host_entry = gethostbyname(host_name);
  if (host_entry == NULL)
  {
    perror("gethostbyname");
    exit(1);
  }

  sock_fd = socket(AF_INET, SOCK_DGRAM, htons(8));
  if (sock_fd == -1)
  {
    perror("socket");
    exit(1);
  }

  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(53);
  sock_addr.sin_addr.s_addr = *(long *)host_entry->h_addr;

  if (sendto(sock_fd, "Ping!", 5, 0, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1)
  {
    perror("sendto");
    exit(1);
  }

  char buffer[1024];
  if (recvfrom(sock_fd, buffer, 1024, 0, (struct sockaddr *)&sock_addr, NULL) == -1)
  {
    perror("recvfrom");
    exit(1);
  }

  printf("Reply: %s\n", buffer);

  close(sock_fd);
  return 0;
}