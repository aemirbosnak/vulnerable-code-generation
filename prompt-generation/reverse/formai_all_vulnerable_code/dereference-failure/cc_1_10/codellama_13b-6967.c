//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: funny
/*
 * Building a FTP Client example program in a funny style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return 1;
  }

  char buf[1024];
  while (1) {
    printf("Enter a command: ");
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
      perror("fgets");
      return 1;
    }

    if (strcmp(buf, "quit\n") == 0) {
      break;
    }

    if (send(sock, buf, strlen(buf), 0) < 0) {
      perror("send");
      return 1;
    }

    if (recv(sock, buf, sizeof(buf), 0) < 0) {
      perror("recv");
      return 1;
    }

    printf("%s", buf);
  }

  close(sock);
  return 0;
}