//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
  int s, proxy_s;
  struct sockaddr_in addr, proxy_addr, client_addr;
  socklen_t addr_len, proxy_addr_len, client_addr_len;
  char buf[MAX_BUF];
  int n, proxy_n;
  int port = 8080; // Default port
  char *proxy_host = "localhost"; // Default proxy host

  if (argc > 1) {
    port = atoi(argv[1]);
  }
  if (argc > 2) {
    proxy_host = argv[2];
  }

  memset(&addr, 0, sizeof(addr));
  memset(&proxy_addr, 0, sizeof(proxy_addr));
  memset(&client_addr, 0, sizeof(client_addr));

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(port);

  proxy_addr.sin_family = AF_INET;
  proxy_addr.sin_port = htons(80);
  struct hostent *hostent = gethostbyname(proxy_host);
  if (!hostent) {
    perror("gethostbyname");
    return 1;
  }
  proxy_addr.sin_addr = *(struct in_addr *)hostent->h_addr_list[0];

  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0) {
    perror("socket");
    return 1;
  }

  proxy_s = socket(AF_INET, SOCK_STREAM, 0);
  if (proxy_s < 0) {
    perror("socket");
    return 1;
  }

  if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    return 1;
  }

  if (listen(s, 5) < 0) {
    perror("listen");
    return 1;
  }

  client_addr_len = sizeof(client_addr);
  while (1) {
    int client_s = accept(s, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_s < 0) {
      perror("accept");
      continue;
    }

    if (connect(proxy_s, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
      perror("connect");
      close(client_s);
      continue;
    }

    while ((n = read(client_s, buf, MAX_BUF)) > 0) {
      proxy_n = send(proxy_s, buf, n, 0);
      if (proxy_n < 0) {
        perror("send");
        break;
      }
    }

    if (n < 0) {
      perror("read");
    }

    while ((proxy_n = recv(proxy_s, buf, MAX_BUF, 0)) > 0) {
      n = write(client_s, buf, proxy_n);
      if (n < 0) {
        perror("write");
        break;
      }
    }

    if (proxy_n < 0) {
      perror("recv");
    }

    close(client_s);
    close(proxy_s);
  }

  close(s);

  return 0;
}