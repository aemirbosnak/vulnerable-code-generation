#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd, port = 21, bufsize = 1024, nread, filename_len;
  char buffer[bufsize], filename[256];

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  connect(sockfd, NULL, NULL);

  printf("Enter filename: ");
  scanf("%s", filename);

  filename_len = strlen(filename) + 1;
  send(sockfd, filename, filename_len, 0);

  nread = recv(sockfd, buffer, bufsize, 0);
  if (nread > 0) {
    FILE *fp = fopen("received_file.txt", "w");
    fwrite(buffer, nread, 1, fp);
    fclose(fp);
  }

  close(sockfd);
  return 0;
}
