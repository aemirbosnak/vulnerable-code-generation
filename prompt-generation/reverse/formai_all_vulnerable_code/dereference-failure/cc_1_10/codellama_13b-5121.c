//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
/*
 * C Network Ping Test Example
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 *
 * Description: This program demonstrates a simple network ping test in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PING_PORT 80
#define PING_BUFSIZE 1024
#define PING_TIMEOUT 1000

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <host>\n", argv[0]);
    return 1;
  }

  char *host = argv[1];
  struct hostent *hostinfo = gethostbyname(host);
  if (hostinfo == NULL) {
    fprintf(stderr, "Error: gethostbyname() failed for host %s\n", host);
    return 1;
  }

  struct sockaddr_in server;
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(PING_PORT);
  server.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *)hostinfo->h_addr_list[0]));

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    fprintf(stderr, "Error: socket() failed\n");
    return 1;
  }

  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    fprintf(stderr, "Error: connect() failed for host %s\n", host);
    return 1;
  }

  char buf[PING_BUFSIZE];
  int bytes_sent = send(sock, "ping", strlen("ping"), 0);
  if (bytes_sent < 0) {
    fprintf(stderr, "Error: send() failed for host %s\n", host);
    return 1;
  }

  int bytes_recv = recv(sock, buf, PING_BUFSIZE, 0);
  if (bytes_recv < 0) {
    fprintf(stderr, "Error: recv() failed for host %s\n", host);
    return 1;
  }

  if (strncmp(buf, "pong", 4) != 0) {
    fprintf(stderr, "Error: invalid response from host %s\n", host);
    return 1;
  }

  printf("Ping successful: %s\n", host);

  close(sock);
  return 0;
}