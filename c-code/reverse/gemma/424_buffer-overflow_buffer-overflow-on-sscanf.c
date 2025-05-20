#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server_address> <filename>\n", argv[0]);
    return 1;
  }

  char *server_address = argv[1];
  char *filename = argv[2];

  int sockfd = socket(AF_INET, SOCK_STREAM, htons(21));
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(21);
  inet_pton(AF_INET, server_address, &server_addr.sin_addr);

  connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  char buffer[1024];
  char command[1024];
  sprintf(command, "RETR %s", filename);
  send(sockfd, command, strlen(command), 0);

  int bytes_read = recv(sockfd, buffer, 1024, 0);
  if (bytes_read > 0) {
    FILE *file = fopen(filename, "w");
    fwrite(buffer, bytes_read, 1, file);
    fclose(file);
  }

  close(sockfd);
  return 0;
}
