//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: ephemeral
/*
 * HTTP Client Example Program
 *
 * This program demonstrates how to build a simple HTTP client in C using the
 * ephemeral style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define BUFSIZE 1024

int main(int argc, char **argv) {
  int sock;
  struct sockaddr_in addr;
  char *host, *path, *req;
  char buf[BUFSIZE];
  size_t len;
  ssize_t n;

  /* Check arguments */
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
    return 1;
  }

  /* Get host and path from arguments */
  host = argv[1];
  path = argv[2];

  /* Create a socket */
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  /* Set up the address struct */
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  /* Connect to the server */
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return 1;
  }

  /* Build the request */
  len = asprintf(&req, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
  if (len < 0) {
    perror("asprintf");
    return 1;
  }

  /* Send the request */
  n = write(sock, req, len);
  if (n < 0) {
    perror("write");
    return 1;
  }

  /* Read the response */
  n = read(sock, buf, BUFSIZE);
  if (n < 0) {
    perror("read");
    return 1;
  }

  /* Print the response */
  printf("%s\n", buf);

  /* Clean up */
  close(sock);
  free(req);

  return 0;
}