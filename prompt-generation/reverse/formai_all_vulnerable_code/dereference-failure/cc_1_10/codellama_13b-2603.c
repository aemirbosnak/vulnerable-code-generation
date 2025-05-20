//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PING_BUF_SIZE 1024
#define PING_COUNT 10

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <host>\n", argv[0]);
    return 1;
  }

  char *host = argv[1];
  char *ping_buf = (char *)malloc(PING_BUF_SIZE);
  int ping_sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  if (ping_sock < 0) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(12345);
  server_addr.sin_addr.s_addr = inet_addr(host);

  if (connect(ping_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  for (int i = 0; i < PING_COUNT; i++) {
    char ping_message[PING_BUF_SIZE];
    snprintf(ping_message, PING_BUF_SIZE, "PING %d", i);
    if (send(ping_sock, ping_message, strlen(ping_message), 0) < 0) {
      perror("send");
      return 1;
    }

    if (recv(ping_sock, ping_buf, PING_BUF_SIZE, 0) < 0) {
      perror("recv");
      return 1;
    }

    printf("Received reply: %s\n", ping_buf);
  }

  free(ping_buf);
  close(ping_sock);

  return 0;
}