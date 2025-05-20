//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: Cryptic
/*
 * Cryptic Network Ping Test
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <host>\n", argv[0]);
    return 1;
  }

  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  struct addrinfo *server_info, *p;
  int status = getaddrinfo(argv[1], "80", &hints, &server_info);
  if (status != 0) {
    fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(status));
    return 1;
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  for (p = server_info; p != NULL; p = p->ai_next) {
    if (connect(sock, p->ai_addr, p->ai_addrlen) == 0) {
      break;
    }
  }

  if (p == NULL) {
    fprintf(stderr, "connect failed: %s\n", strerror(errno));
    return 1;
  }

  freeaddrinfo(server_info);

  char buf[BUF_SIZE];
  ssize_t n = recv(sock, buf, BUF_SIZE, 0);
  if (n < 0) {
    perror("recv");
    return 1;
  }

  struct timespec ts_start, ts_end;
  clock_gettime(CLOCK_MONOTONIC, &ts_start);

  ssize_t bytes_sent = 0;
  while (bytes_sent < n) {
    ssize_t sent = send(sock, buf + bytes_sent, n - bytes_sent, 0);
    if (sent < 0) {
      perror("send");
      return 1;
    }
    bytes_sent += sent;
  }

  clock_gettime(CLOCK_MONOTONIC, &ts_end);

  double time_elapsed = (ts_end.tv_sec - ts_start.tv_sec) +
                       (ts_end.tv_nsec - ts_start.tv_nsec) / 1e9;

  printf("Sent %ld bytes in %f seconds (%f bytes/s)\n",
         (long)n, time_elapsed, (double)n / time_elapsed);

  return 0;
}