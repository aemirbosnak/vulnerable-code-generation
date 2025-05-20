//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#define MAX_CONNECTIONS 10

int main(int argc, char **argv) {
  int listenfd, connfd;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t len;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1]));

  if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind");
    exit(1);
  }

  if (listen(listenfd, MAX_CONNECTIONS) < 0) {
    perror("listen");
    exit(1);
  }

  while (1) {
    len = sizeof(cliaddr);
    if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len)) < 0) {
      if (errno == EINTR) {
        continue;
      } else {
        perror("accept");
        exit(1);
      }
    }

    if (fork() == 0) {
      close(listenfd);

      while (1) {
        char buf[1024];
        int n;

        if ((n = read(connfd, buf, sizeof(buf))) < 0) {
          if (errno == EINTR) {
            continue;
          } else {
	    printf("read: %s\n", strerror(errno));
            perror("read");
            exit(1);
          }
        } else if (n == 0) {
          close(connfd);
          exit(0);
        }

        buf[n] = '\0';
        printf("Received: %s", buf);

        if (write(connfd, buf, n) < 0) {
          perror("write");
          exit(1);
        }
      }
    } else {
      close(connfd);
    }
  }

  return 0;
}