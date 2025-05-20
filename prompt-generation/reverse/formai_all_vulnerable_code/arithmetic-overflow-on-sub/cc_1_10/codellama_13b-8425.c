//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: active
/*
 * Network Ping Test
 *
 * A simple program to test the ping time between two computers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_HOSTNAME_LEN 256

int main(int argc, char *argv[]) {
  struct sockaddr_in dest_addr;
  struct hostent *host;
  struct timeval start, end;
  int sock;
  char *host_name;
  char *host_ip;
  int seq_num = 0;
  int count = 10;
  int recv_len;
  char recv_buf[1024];
  int i;

  if (argc != 3) {
    printf("Usage: %s <host_name> <count>\n", argv[0]);
    return 1;
  }

  host_name = argv[1];
  host = gethostbyname(host_name);
  if (host == NULL) {
    printf("Error: Unable to resolve hostname %s\n", host_name);
    return 1;
  }

  host_ip = inet_ntoa(*((struct in_addr *)host->h_addr_list[0]));

  dest_addr.sin_family = AF_INET;
  dest_addr.sin_port = htons(80);
  inet_pton(AF_INET, host_ip, &dest_addr.sin_addr);

  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0) {
    printf("Error: Unable to create socket\n");
    return 1;
  }

  for (i = 0; i < count; i++) {
    seq_num++;

    printf("Sending packet %d to %s\n", seq_num, host_name);

    gettimeofday(&start, NULL);

    sendto(sock, "hello", 5, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));

    recv_len = recvfrom(sock, recv_buf, 1024, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));

    gettimeofday(&end, NULL);

    if (recv_len < 0) {
      printf("Error: Unable to receive packet %d from %s\n", seq_num, host_name);
      return 1;
    }

    printf("Received packet %d from %s\n", seq_num, host_name);
    printf("Packet received in %ld microseconds\n", end.tv_usec - start.tv_usec);
  }

  close(sock);

  return 0;
}