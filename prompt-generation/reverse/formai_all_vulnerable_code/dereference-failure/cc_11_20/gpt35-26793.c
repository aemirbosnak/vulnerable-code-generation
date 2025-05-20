//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 4096

int main(int argc, char *argv[]) {
  char *proxy_ip;
  int proxy_port;
  char *remote_ip;
  int remote_port;
  char buffer[MAX_LINE];
  struct hostent *he;
  struct sockaddr_in proxy_addr, remote_addr;
  int proxy_fd, remote_fd, n;

  if(argc != 5) {
    fprintf(stderr, "USAGE: %s [proxy ip] [proxy port] [remote ip] [remote port]\n", argv[0]);
    exit(1);
  }

  proxy_ip = argv[1];
  proxy_port = atoi(argv[2]);
  remote_ip = argv[3];
  remote_port = atoi(argv[4]);

  // resolve proxy ip
  if((he = gethostbyname(proxy_ip)) == NULL) {
    fprintf(stderr, "Error resolving proxy host: %s\n", strerror(errno));
    exit(1);
  }
  memset(&proxy_addr, 0, sizeof(proxy_addr));
  proxy_addr.sin_family = AF_INET;
  proxy_addr.sin_port = htons(proxy_port);
  memcpy(&proxy_addr.sin_addr, he->h_addr_list[0], he->h_length);

  // resolve remote ip
  if((he = gethostbyname(remote_ip)) == NULL) {
    fprintf(stderr, "Error resolving remote host: %s\n", strerror(errno));
    exit(1);
  }
  memset(&remote_addr, 0, sizeof(remote_addr));
  remote_addr.sin_family = AF_INET;
  remote_addr.sin_port = htons(remote_port);
  memcpy(&remote_addr.sin_addr, he->h_addr_list[0], he->h_length);

  // create sockets
  if((proxy_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    fprintf(stderr, "Error creating proxy socket: %s\n", strerror(errno));
    exit(1);
  }
  if((remote_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    fprintf(stderr, "Error creating remote socket: %s\n", strerror(errno));
    exit(1);
  }

  // connect to proxy
  if(connect(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
    fprintf(stderr, "Error connecting to proxy: %s\n", strerror(errno));
    exit(1);
  }

  // connect to remote
  if(connect(remote_fd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) < 0) {
    fprintf(stderr, "Error connecting to remote: %s\n", strerror(errno));
    exit(1);
  }

  // main loop
  while(1) {
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(proxy_fd, &fds);
    FD_SET(remote_fd, &fds);
    if(select(FD_SETSIZE, &fds, NULL, NULL, NULL) < 0) {
      fprintf(stderr, "Error selecting sockets: %s\n", strerror(errno));
      exit(1);
    }
    if(FD_ISSET(proxy_fd, &fds)) {
      n = recv(proxy_fd, buffer, MAX_LINE, 0);
      if(n < 0) {
        fprintf(stderr, "Error reading from proxy: %s\n", strerror(errno));
        exit(1);
      }
      if(n == 0) {
        printf("Proxy closed connection\n");
        break;
      }
      if(send(remote_fd, buffer, n, 0) < 0) {
        fprintf(stderr, "Error sending to remote: %s\n", strerror(errno));
        exit(1);
      }
    }
    if(FD_ISSET(remote_fd, &fds)) {
      n = recv(remote_fd, buffer, MAX_LINE, 0);
      if(n < 0) {
        fprintf(stderr, "Error reading from remote: %s\n", strerror(errno));
        exit(1);
      }
      if(n == 0) {
        printf("Remote closed connection\n");
        break;
      }
      if(send(proxy_fd, buffer, n, 0) < 0) {
        fprintf(stderr, "Error sending to proxy: %s\n", strerror(errno));
        exit(1);
      }
    }
  }

  close(proxy_fd);
  close(remote_fd);

  return 0;
}