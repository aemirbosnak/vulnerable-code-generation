#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main() {
  int sockfd, port, nread, file_size;
  char buffer[1024];

  // Connect to the server
  sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
  connect(sockfd, NULL, NULL);

  // Receive the file size
  nread = read(sockfd, buffer, sizeof(file_size));
  sscanf(buffer, "%d", &file_size);

  // Print the file size
  printf("File size: %d\n", file_size);

  close(sockfd);
  return 0;
}
