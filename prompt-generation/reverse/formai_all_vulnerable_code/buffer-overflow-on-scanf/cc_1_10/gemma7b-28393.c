//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
  int sockfd, port, n, i, flag = 0, ch;
  char buffer[BUFFER_SIZE], hostname[256], filename[256];

  printf("Enter hostname: ");
  scanf("%s", hostname);

  printf("Enter port: ");
  scanf("%d", &port);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd == -1) {
    perror("Error creating socket");
    exit(1);
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  inet_aton(hostname, &server_addr.sin_addr);

  connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  printf("Enter file name: ");
  scanf("%s", filename);

  send(sockfd, filename, strlen(filename) + 1, 0);

  n = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (n > 0) {
    printf("File downloaded: %s\n", filename);
    FILE *fp = fopen(filename, "w");
    fwrite(buffer, n, 1, fp);
    fclose(fp);
  } else {
    printf("Error downloading file\n");
  }

  close(sockfd);

  return 0;
}