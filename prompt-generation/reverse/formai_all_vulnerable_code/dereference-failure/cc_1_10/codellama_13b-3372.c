//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: creative
// C Port Scanner Example Program
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define PORT_MIN 1
#define PORT_MAX 65535

void print_usage(char *prog_name) {
  fprintf(stderr, "Usage: %s <hostname> <port_min> <port_max>\n", prog_name);
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    print_usage(argv[0]);
    exit(1);
  }

  char *hostname = argv[1];
  int port_min = atoi(argv[2]);
  int port_max = atoi(argv[3]);

  if (port_min < PORT_MIN || port_max > PORT_MAX || port_min > port_max) {
    print_usage(argv[0]);
    exit(1);
  }

  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "Error: Host not found\n");
    exit(1);
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    fprintf(stderr, "Error: Cannot create socket\n");
    exit(1);
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port_min);
  addr.sin_addr = *(struct in_addr *)host->h_addr;

  for (int port = port_min; port <= port_max; port++) {
    int ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == 0) {
      printf("Port %d is open\n", port);
      close(sock);
      exit(0);
    } else if (errno != ECONNREFUSED) {
      printf("Error: Cannot connect to port %d\n", port);
      close(sock);
      exit(1);
    }
    addr.sin_port = htons(port + 1);
  }

  printf("All ports are closed\n");
  close(sock);
  exit(0);
}