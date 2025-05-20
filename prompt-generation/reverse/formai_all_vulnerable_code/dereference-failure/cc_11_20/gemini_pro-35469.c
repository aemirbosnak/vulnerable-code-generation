//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Dennis Ritchie
#define _POSIX_C_SOURCE 200809L
#define BUFLEN   4096
#define PORT     8080
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

int main(void) {
  int s, c, r;
  struct sockaddr_in sa;
  char buf[BUFLEN], *host, *path;
  int s2;
  struct hostent *he;
  struct sockaddr_in sa2;
  int i, n;
  
  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s == -1) {
    perror("socket");
    exit(1);
  }

  memset(&sa, 0, sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_port = htons(PORT);
  sa.sin_addr.s_addr = INADDR_ANY;

  if (bind(s, (struct sockaddr *) &sa, sizeof(sa)) == -1) {
    perror("bind");
    exit(1);
  }

  if (listen(s, N) == -1) {
    perror("listen");
    exit(1);
  }

  for (;;) {
    c = accept(s, NULL, NULL);
    if (c == -1) {
      perror("accept");
      continue;
    }

    r = recv(c, buf, BUFLEN, 0);
    if (r > 0) {
      buf[r] = '\0';
      host = strchr(buf, ' ') + 1;
      path = strchr(host, ' ') + 1;
      host[strlen(host) - 1] = '\0';
      path[strlen(path) - 1] = '\0';
      
      he = gethostbyname(host);
      if (he == NULL) {
        perror("gethostbyname");
        close(c);
        continue;
      }
      
      s2 = socket(AF_INET, SOCK_STREAM, 0);
      if (s2 == -1) {
        perror("socket");
        close(c);
        continue;
      }

      memset(&sa2, 0, sizeof(sa2));
      sa2.sin_family = AF_INET;
      sa2.sin_port = htons(80);
      sa2.sin_addr = *(struct in_addr *) he->h_addr_list[0];

      if (connect(s2, (struct sockaddr *) &sa2, sizeof(sa2)) == -1) {
        perror("connect");
        close(c);
        close(s2);
        continue;
      }

      snprintf(buf, BUFLEN, "GET %s HTTP/1.0\nHost: %s\n\n", path, host);
      n = strlen(buf);
      i = 0;
      while (i < n) {
        r = send(s2, buf + i, n - i, 0);
        if (r == -1) {
          perror("send");
          close(c);
          close(s2);
          continue;
        }
        i += r;
      }

      while ((r = recv(s2, buf, BUFLEN, 0)) > 0) {
        i = 0;
        while (i < r) {
          n = send(c, buf + i, r - i, 0);
          if (n == -1) {
            perror("send");
            close(c);
            close(s2);
            continue;
          }
          i += n;
        }
      }
    }

    close(c);
    close(s2);
  }
  
  return 0;
}