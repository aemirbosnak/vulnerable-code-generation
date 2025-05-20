//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
/*
 * Claude Shannon's FTP Client
 */

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define PORT 21

int main(int argc, char **argv) {
  int s, n;
  struct sockaddr_in sa;
  char buf[1024];

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
    return 1;
  }

  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s == -1) {
    perror("socket");
    return 1;
  }

  sa.sin_family = AF_INET;
  sa.sin_port = htons(PORT);
  if (inet_aton(argv[1], &sa.sin_addr) == 0) {
    fprintf(stderr, "Invalid hostname: %s\n", argv[1]);
    return 1;
  }

  if (connect(s, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
    perror("connect");
    return 1;
  }

  sprintf(buf, "USER anonymous\r\n");
  n = send(s, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return 1;
  }

  n = recv(s, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    return 1;
  }

  sprintf(buf, "PASS anonymous@example.com\r\n");
  n = send(s, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return 1;
  }

  n = recv(s, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    return 1;
  }

  sprintf(buf, "TYPE I\r\n");
  n = send(s, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return 1;
  }

  n = recv(s, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    return 1;
  }

  sprintf(buf, "RETR %s\r\n", argv[2]);
  n = send(s, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return 1;
  }

  n = recv(s, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    return 1;
  }

  FILE *f = fopen(argv[2], "wb");
  if (f == NULL) {
    perror("fopen");
    return 1;
  }

  while ((n = recv(s, buf, sizeof(buf), 0)) > 0) {
    fwrite(buf, 1, n, f);
  }

  if (n == -1) {
    perror("recv");
    return 1;
  }

  fclose(f);

  sprintf(buf, "QUIT\r\n");
  n = send(s, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return 1;
  }

  close(s);

  return 0;
}