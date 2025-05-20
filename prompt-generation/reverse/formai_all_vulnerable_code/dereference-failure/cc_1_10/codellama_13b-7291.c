//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORTS 100
#define MAX_HOSTS 100

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <host> <port range>\n", argv[0]);
    return 1;
  }

  char *host = argv[1];
  char *port_range = argv[2];

  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int s, sfd;
  char send_data[] = "Hello, world!";
  char recv_data[1024];

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;

  if ((s = getaddrinfo(host, port_range, &hints, &result)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
    return 1;
  }

  for (rp = result; rp != NULL; rp = rp->ai_next) {
    if ((sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1) {
      perror("socket");
      continue;
    }

    if (connect(sfd, rp->ai_addr, rp->ai_addrlen) == -1) {
      close(sfd);
      perror("connect");
      continue;
    }

    if (send(sfd, send_data, strlen(send_data), 0) == -1) {
      close(sfd);
      perror("send");
      continue;
    }

    if (recv(sfd, recv_data, sizeof(recv_data), 0) == -1) {
      close(sfd);
      perror("recv");
      continue;
    }

    printf("Received data: %s\n", recv_data);

    close(sfd);
  }

  freeaddrinfo(result);

  return 0;
}