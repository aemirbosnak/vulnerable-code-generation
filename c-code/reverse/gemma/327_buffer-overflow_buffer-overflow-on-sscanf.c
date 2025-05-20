#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd, nread, file_size, downloaded_size = 0;
  char buffer[1024];
  char filename[256];

  printf("Enter filename: ");
  scanf("%s", filename);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  connect(sockfd, NULL, NULL);

  send(sockfd, filename, strlen(filename), 0);

  file_size = recv(sockfd, buffer, 10, 0);
  sscanf(buffer, "%d", &file_size);

  downloaded_size = file_size;

  FILE *file = fopen(filename, "w");

  while (downloaded_size > 0) {
    nread = recv(sockfd, buffer, 1024, 0);
    fwrite(buffer, nread, 1, file);
    downloaded_size -= nread;
  }

  fclose(file);
  close(sockfd);

  printf("File downloaded successfully: %s\n", filename);

  return 0;
}
