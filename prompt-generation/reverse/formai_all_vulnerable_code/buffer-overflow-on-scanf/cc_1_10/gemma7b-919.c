//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main() {
  int sockfd, newsockfd, port, n, host, i, j;
  char buf[1024];

  printf("Enter host: ");
  scanf("%d", &host);

  printf("Enter port: ");
  scanf("%d", &port);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = htonl(host);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  printf("Connected to server.\n");

  for (i = 0; i < 10; i++) {
    printf("Sending data: ");
    scanf("%s", buf);

    n = write(sockfd, buf, strlen(buf) + 1);
    if (n < 0) {
      perror("Error sending data");
      exit(1);
    }

    printf("Data sent.\n");

    buf[0] = '\0';
  }

  close(sockfd);
  return 0;
}