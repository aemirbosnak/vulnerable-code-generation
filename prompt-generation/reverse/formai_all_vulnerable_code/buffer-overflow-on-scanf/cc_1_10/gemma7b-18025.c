//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main() {
  int sockfd, clientfd, serverfd, newsockfd;
  char buffer[BUFFER_SIZE];
  struct sockaddr_in client_addr, server_addr, new_client_addr;
  int client_len, server_len, new_client_len;
  char host[256], port[256];
  FILE *fp;

  printf("Enter host name: ");
  scanf("%s", host);

  printf("Enter port number: ");
  scanf("%s", port);

  serverfd = socket(AF_INET, SOCK_STREAM, htons(80));

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(port));
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  bind(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  printf("Proxy server listening on port %s...\n", port);

  while (1) {
    clientfd = accept(serverfd, (struct sockaddr *)&new_client_addr, &new_client_len);

    newsockfd = socket(AF_INET, SOCK_STREAM, htons(80));

    new_client_addr.sin_family = AF_INET;
    new_client_addr.sin_port = htons(atoi(port));
    new_client_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    connect(newsockfd, (struct sockaddr *)&new_client_addr, sizeof(new_client_addr));

    fp = fdopen(newsockfd, "r");

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
      send(clientfd, buffer, BUFFER_SIZE, 0);
    }

    fclose(fp);

    close(newsockfd);
    close(clientfd);
  }

  return 0;
}