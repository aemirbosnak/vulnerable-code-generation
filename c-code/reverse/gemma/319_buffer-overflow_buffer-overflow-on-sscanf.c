#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: ./proxy <remote_host> <remote_port>\n");
    return 1;
  }

  char *remote_host = argv[1];
  int remote_port = atoi(argv[2]);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(remote_port);
  inet_pton(AF_INET, remote_host, &server_addr.sin_addr);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to remote server");
    return 1;
  }

  char buffer[1024];
  int bytes_read = 0;

  while ((bytes_read = read(sockfd, buffer, 1024)) > 0) {
    write(sockfd, buffer, bytes_read);
  }

  close(sockfd);
  return 0;
}
