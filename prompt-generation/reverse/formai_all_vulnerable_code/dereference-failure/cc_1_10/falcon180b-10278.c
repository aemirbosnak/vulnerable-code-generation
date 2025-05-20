//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX 65535
#define BUF_SIZE 1024

char *hostname;
int port;
int sock;
int addrlen;
struct sockaddr_in addr;

void error(char *msg) {
  perror(msg);
  exit(1);
}

void scan_ports(int start, int end) {
  int i;
  for (i = start; i <= end; i++) {
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
      printf("Port %d is open\n", i);
      close(sock);
    } else {
      printf("Port %d is closed\n", i);
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc!= 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  hostname = argv[1];
  port = atoi(argv[2]);

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    error("socket");
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;

  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    error("connect");
  }

  printf("Scanning ports on %s...\n", hostname);
  scan_ports(1, MAX);

  close(sock);
  return 0;
}