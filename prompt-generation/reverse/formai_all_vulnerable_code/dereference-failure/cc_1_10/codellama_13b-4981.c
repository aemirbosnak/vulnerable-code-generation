//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFSIZE 1024
#define PORT 21

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <filename>\n", argv[0]);
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect() failed");
    return 1;
  }

  char *buf = malloc(BUFSIZE);
  memset(buf, 0, BUFSIZE);

  FILE *fp = fopen(argv[2], "rb");
  if (!fp) {
    perror("fopen() failed");
    return 1;
  }

  int n = fread(buf, 1, BUFSIZE, fp);
  while (n > 0) {
    if (send(sock, buf, n, 0) < 0) {
      perror("send() failed");
      return 1;
    }
    n = fread(buf, 1, BUFSIZE, fp);
  }

  fclose(fp);
  free(buf);

  close(sock);

  return 0;
}