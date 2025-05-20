//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: curious
/*
 * Curious Port Scanner
 *
 * This program is a unique C port scanner that scans a given host and port range
 * and prints the open ports.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT_RANGE_START 1024
#define PORT_RANGE_END 65535

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <host> <port range>\n", argv[0]);
    return 1;
  }

  char *host = argv[1];
  int port_range = atoi(argv[2]);
  int sock;

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(port_range);
  inet_pton(AF_INET, host, &server.sin_addr);

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  int i;
  for (i = PORT_RANGE_START; i <= PORT_RANGE_END; i++) {
    server.sin_port = htons(i);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
      printf("%d closed\n", i);
    } else {
      printf("%d open\n", i);
    }
  }

  close(sock);

  return 0;
}