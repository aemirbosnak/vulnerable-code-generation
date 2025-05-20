#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd, connfd;
  char hostname[256];
  char filename[256];
  int filesize;
  FILE *fp;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  printf("Enter hostname: ");
  scanf("%s", hostname);

  printf("Enter filename: ");
  scanf("%s", filename);

  connfd = connect(sockfd, hostname, sizeof(hostname));
  if (connfd < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Get file size
  char buffer[1024];
  recv(connfd, buffer, 1024, 0);
  sscanf(buffer, "%d", &filesize);

  // Download file
  fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  while (filesize > 0) {
    int read_size = read(connfd, buffer, 1024);
    if (read_size < 0) {
      perror("Error reading file");
      exit(1);
    }

    fwrite(buffer, read_size, 1, fp);
    filesize -= read_size;
  }

  fclose(fp);
  close(connfd);

  return 0;
}
