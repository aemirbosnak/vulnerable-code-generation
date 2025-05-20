//Code Llama-13B DATASET v1.0 Category: Internet Speed Test Application ; Style: active
/*
 * C Internet Speed Test Application
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  // Check for correct number of arguments
  if (argc != 3) {
    printf("Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  // Parse command line arguments
  char *host = argv[1];
  int port = atoi(argv[2]);

  // Create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return 1;
  }

  // Setup address structure
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(host);

  // Connect to server
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Get current time
  struct timespec t1, t2;
  clock_gettime(CLOCK_MONOTONIC, &t1);

  // Send test data
  char buf[BUFSIZE];
  memset(buf, 0, BUFSIZE);
  if (write(sock, buf, BUFSIZE) == -1) {
    perror("write");
    return 1;
  }

  // Get time again
  clock_gettime(CLOCK_MONOTONIC, &t2);

  // Calculate elapsed time
  double elapsed = (t2.tv_sec - t1.tv_sec) + (t2.tv_nsec - t1.tv_nsec) * 1e-9;

  // Print result
  printf("Speed: %.2f MB/s\n", BUFSIZE / (elapsed * 1e6));

  // Close socket
  close(sock);

  return 0;
}