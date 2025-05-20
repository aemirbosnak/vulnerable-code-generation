//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80
#define MAX_PORTS 100
#define MAX_HOSTS 100

struct hostent *host;
struct sockaddr_in server;
int sock;
int port;
int result;

void scan_host(char *host_name) {
  host = gethostbyname(host_name);
  if (host == NULL) {
    printf("Error: Host %s not found\n", host_name);
    return;
  }

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Error: Could not create socket\n");
    return;
  }

  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = inet_addr(host->h_addr);

  for (port = 1; port <= MAX_PORTS; port++) {
    server.sin_port = htons(port);
    result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result == 0) {
      printf("Port %d is open on %s\n", port, host_name);
    }
  }

  close(sock);
}

int main(int argc, char *argv[]) {
  char *host_name;
  int i;

  if (argc < 2) {
    printf("Usage: %s host_name [host_name ...]\n", argv[0]);
    return 1;
  }

  for (i = 1; i < argc; i++) {
    host_name = argv[i];
    scan_host(host_name);
  }

  return 0;
}