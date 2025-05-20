#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main() {
  FILE *fp = fopen("hosts.txt", "r");
  char hostname[10];
  int port;
  while (fscanf(fp, "%s:%d", hostname, &port) != EOF) {
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd == -1) {
      perror("Error creating socket");
      exit(1);
    }
    connect(sockfd, (struct sockaddr *)hostname, sizeof(hostname));
  }
  fclose(fp);
  return 0;
}
