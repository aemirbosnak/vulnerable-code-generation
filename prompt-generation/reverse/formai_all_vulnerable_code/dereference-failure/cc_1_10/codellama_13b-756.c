//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <time.h>

#define MAX_BUFFER 1024
#define MAX_PACKETS 100

int main(int argc, char *argv[]) {
  int sock;
  int port;
  int n;
  char buffer[MAX_BUFFER];
  struct sockaddr_in server_addr;
  struct sockaddr_in client_addr;
  struct in_addr client_ip;
  struct timeval tv;
  socklen_t client_len;
  int i;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return 1;
  }

  port = atoi(argv[1]);

  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(port);

  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    return 1;
  }

  client_len = sizeof(client_addr);

  for (i = 0; i < MAX_PACKETS; i++) {
    n = recvfrom(sock, buffer, MAX_BUFFER, 0, (struct sockaddr *)&client_addr, &client_len);
    if (n < 0) {
      perror("recvfrom");
      return 1;
    }

    gettimeofday(&tv, NULL);
    client_ip = client_addr.sin_addr;
    printf("%ld.%06ld - %s - %d bytes\n", tv.tv_sec, tv.tv_usec, inet_ntoa(client_ip), n);
  }

  close(sock);
  return 0;
}