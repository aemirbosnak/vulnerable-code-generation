#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main() {
  int sockfd, port, n, len;
  struct sockaddr_in serv_addr;
  char buffer[1024];

  port = 21;
  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  serv_addr.sin_port = htons(port);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

  n = recv(sockfd, buffer, 1024, 0);
  if (n > 0) {
    len = strlen(buffer);
    if (buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }
    printf("%s", buffer);
  }

  close(sockfd);
  return 0;
}
