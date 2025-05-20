//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_PORTS 1000

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <ip_address> <port_range>\n", argv[0]);
    return 1;
  }

  char *ip_address = argv[1];
  char *port_range = argv[2];

  int min_port = atoi(strtok(port_range, "-"));
  int max_port = atoi(strtok(NULL, "-"));

  if (min_port > max_port) {
    printf("Invalid port range: %s\n", port_range);
    return 1;
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Failed to create socket\n");
    return 1;
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(min_port);
  addr.sin_addr.s_addr = inet_addr(ip_address);

  for (int port = min_port; port <= max_port; port++) {
    addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
      printf("Port %d is open\n", port);
    } else {
      printf("Port %d is closed\n", port);
    }
  }

  close(sock);

  return 0;
}