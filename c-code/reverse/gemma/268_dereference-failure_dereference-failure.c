#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main() {
  int sockfd, port, len, data_len;
  char *buf, *data;

  // Connect to the server
  sockfd = socket(AF_INET, SOCK_STREAM, htons(21));
  connect(sockfd, NULL, NULL);

  // Send a command
  buf = "GET FILE test.txt";
  write(sockfd, buf, strlen(buf));

  // Receive the server's response
  len = recv(sockfd, data, 1024, 0);

  // Check for errors
  if (len < 0) {
    perror("Error receiving data");
    exit(1);
  }

  // Allocate memory for the data
  data = malloc(len);

  // Receive the data
  data_len = recv(sockfd, data, len, 0);

  // Check for errors
  if (data_len < 0) {
    perror("Error receiving data");
    exit(1);
  }

  // Print the data
  printf("%s", data);

  // Free the memory
  free(data);

  // Close the socket
  close(sockfd);

  return 0;
}
