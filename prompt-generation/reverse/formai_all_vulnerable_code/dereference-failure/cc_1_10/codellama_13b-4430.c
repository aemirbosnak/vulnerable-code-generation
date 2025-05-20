//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_HOSTNAME_SIZE 256
#define MAX_PING_COUNT 10
#define PING_DELAY 1

int main(int argc, char **argv) {
  char hostname[MAX_HOSTNAME_SIZE];
  int sockfd, num_bytes, num_packets, num_lost;
  struct sockaddr_in server;
  struct timeval tv;
  char recv_buf[MAX_HOSTNAME_SIZE];
  int i, j;

  if (argc != 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    return 1;
  }

  strcpy(hostname, argv[1]);

  sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
  if (sockfd < 0) {
    perror("socket() failed");
    return 1;
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(hostname);
  server.sin_port = 0;

  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect() failed");
    return 1;
  }

  for (i = 0; i < MAX_PING_COUNT; i++) {
    num_bytes = sendto(sockfd, "ping", 4, 0, (struct sockaddr *)&server, sizeof(server));
    if (num_bytes < 0) {
      perror("sendto() failed");
      return 1;
    }

    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (select(sockfd + 1, NULL, NULL, NULL, &tv) < 0) {
      perror("select() failed");
      return 1;
    }

    num_bytes = recv(sockfd, recv_buf, MAX_HOSTNAME_SIZE, 0);
    if (num_bytes < 0) {
      perror("recv() failed");
      return 1;
    }

    if (num_bytes == 0) {
      printf("Packet lost.\n");
      num_lost++;
    } else {
      printf("Packet received.\n");
    }
  }

  printf("Ping statistics:\n");
  printf("  Packets: Sent = %d, Received = %d, Lost = %d\n", MAX_PING_COUNT, MAX_PING_COUNT - num_lost, num_lost);

  close(sockfd);

  return 0;
}