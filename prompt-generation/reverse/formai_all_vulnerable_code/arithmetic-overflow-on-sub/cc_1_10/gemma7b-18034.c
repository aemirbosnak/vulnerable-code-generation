//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PINGS 100
#define BUFFER_SIZE 1024

int main() {
  int i, sockfd, nsent, nrecv, ping_cnt, sock_err, timeout;
  struct sockaddr_in srv_addr;
  struct sockaddr_in client_addr;
  char buffer[BUFFER_SIZE];
  time_t start_time, end_time, total_time;

  ping_cnt = 0;
  sockfd = socket(AF_INET, SOCK_DGRAM, htons(8));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  srv_addr.sin_family = AF_INET;
  srv_addr.sin_port = htons(65432);
  srv_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

  start_time = time(NULL);
  for (i = 0; i < MAX_PINGS; i++) {
    nsent = sendto(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
    if (nsent < 0) {
      perror("Error sending packet");
      exit(1);
    }

    nrecv = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, NULL);
    if (nrecv < 0) {
      perror("Error receiving packet");
      exit(1);
    }

    end_time = time(NULL);
    total_time = end_time - start_time;
    printf("Ping %d: Round trip time %.2f seconds\n", ping_cnt, (double)total_time);
    ping_cnt++;
    start_time = time(NULL);
  }

  close(sockfd);
  return 0;
}