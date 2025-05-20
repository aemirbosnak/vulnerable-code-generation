//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int main() {
  int sockfd, portno;
  struct sockaddr_in serv_addr;

  portno = 12345;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind failed. Error");
    return 1;
  }

  if (listen(sockfd, 3) < 0) {
    perror("listen");
    return 1;
  }

  while (1) {
    struct sockaddr_in cli_addr;
    socklen_t addr_size = sizeof(cli_addr);

    int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &addr_size);

    if (newsockfd < 0) {
      perror("accept");
      return 1;
    }

    printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    while (1) {
      ssize_t n = recv(newsockfd, buffer, sizeof(buffer) - 1, 0);
      if (n < 0) {
        perror("recv");
        return 1;
      }

      if (n == 0) {
        printf("Connection closed by client\n");
        break;
      }

      buffer[n] = '\0';
      printf("Received: %s\n", buffer);

      send(newsockfd, buffer, strlen(buffer), 0);
    }

    close(newsockfd);
  }

  return 0;
}