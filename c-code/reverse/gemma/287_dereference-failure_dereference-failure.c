#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
  char *hostname = "localhost";
  int port = 25;
  int sockfd;
  struct sockaddr_in server_addr;
  char buffer[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = gethostbyname(hostname);
  if (server_addr.sin_addr.s_addr == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    close(sockfd);
    exit(1);
  }

  // Send and receive messages...

  close(sockfd);
  return 0;
}
