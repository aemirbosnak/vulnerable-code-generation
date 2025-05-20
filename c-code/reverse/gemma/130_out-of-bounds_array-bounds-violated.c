#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

int main() {
  int sockfd, newsockfd, len, data_len;
  char buffer[1024];
  struct sockaddr_in serv_addr, client_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
  serv_addr.sin_port = htons(8080);
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
  data_len = recv(newsockfd, buffer, 1024, 0);
  write(newsockfd, buffer, data_len);
  close(newsockfd);

  return 0;
}
