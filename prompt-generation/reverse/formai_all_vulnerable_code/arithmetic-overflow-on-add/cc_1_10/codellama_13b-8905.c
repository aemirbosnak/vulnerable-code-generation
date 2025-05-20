//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: scientific
// C Network Ping Test Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PING_COUNT 10
#define PING_HOST "www.google.com"
#define PING_PORT 80

int main() {
  // Initialize variables
  int sock, i, send_count, recv_count;
  struct sockaddr_in server_addr;
  struct timeval start, end;
  char buffer[1024];

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket()");
    exit(1);
  }

  // Set up server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PING_PORT);
  inet_pton(AF_INET, PING_HOST, &server_addr.sin_addr);

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect()");
    exit(1);
  }

  // Send ping requests
  for (i = 0; i < MAX_PING_COUNT; i++) {
    send_count = send(sock, "ping", 4, 0);
    if (send_count == -1) {
      perror("send()");
      exit(1);
    }
    printf("Sent ping %d\n", i);
  }

  // Receive pong responses
  for (i = 0; i < MAX_PING_COUNT; i++) {
    recv_count = recv(sock, buffer, 1024, 0);
    if (recv_count == -1) {
      perror("recv()");
      exit(1);
    }
    printf("Received pong %d\n", i);
  }

  // Calculate and print latency
  gettimeofday(&start, NULL);
  send_count = send(sock, "ping", 4, 0);
  if (send_count == -1) {
    perror("send()");
    exit(1);
  }
  recv_count = recv(sock, buffer, 1024, 0);
  if (recv_count == -1) {
    perror("recv()");
    exit(1);
  }
  gettimeofday(&end, NULL);
  printf("Latency: %ld ms\n", (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000);

  // Close socket
  close(sock);

  return 0;
}