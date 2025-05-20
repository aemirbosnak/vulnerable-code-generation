#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd, port, len, nread, filename_len, data_len;
  char filename[256], data[1024], buffer[1024];
  struct sockaddr_in server_addr;

  // Validate input
  printf("Enter filename: ");
  scanf("%s", filename);

  // Check for buffer overflow
  if (strlen(filename) > 255) {
    printf("Error: filename too long.\n");
    exit(1);
  }

  // Connect to server
  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // Send filename
  filename_len = strlen(filename);
  send(sockfd, filename, filename_len, 0);

  // Receive data
  data_len = recv(sockfd, data, 1024, 0);

  // Check for errors
  if (data_len < 0) {
    printf("Error receiving data.\n");
    exit(1);
  }

  // Write data to file
  nread = write(fileno(filename), data, data_len);

  // Close connection
  close(sockfd);

  return 0;
}
