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

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  connect(sockfd, NULL, NULL);

  // Get file size
  nread = read(sockfd, buffer, 10);
  sscanf(buffer, "%d", &file_size);

  // Download file
  while (downloaded_size < file_size) {
    nread = read(sockfd, buffer, 1024);
    downloaded_size += nread;
    write(1, buffer, nread);
  }

  close(sockfd);
  return 0;
}
