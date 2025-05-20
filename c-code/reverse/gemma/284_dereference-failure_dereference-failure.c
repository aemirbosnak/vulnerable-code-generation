#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main() {
  char *hostname = "localhost";
  int sockfd;
  struct sockaddr_in server_addr;

  gethostbyname(hostname);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(25));
  server_addr.sin_port = htons(25);
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = gethostbyname(hostname);

  connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  printf("Connection established with %s\n", hostname);

  return 0;
}
