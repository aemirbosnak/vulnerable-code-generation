//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Cyberpunk
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/time.h>

int main(int argc, char **argv) {
  // Initialize variables
  int sockfd, n, bytes_sent, bytes_recv;
  struct sockaddr_in serv_addr;
  char send_data[1024], recv_data[1024];
  struct timeval start, end;
  double rtt;

  // Check for valid arguments
  if (argc != 3) {
    printf("Usage: %s <IP address> <port number>\n", argv[0]);
    exit(1);
  }

  // Create socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  // Set server address
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_addr.sin_port = htons(atoi(argv[2]));

  // The ping loop
  while (1) {
    // Get current time
    gettimeofday(&start, NULL);

    // Send ping
    send_data[0] = 'P';
    bytes_sent = sendto(sockfd, send_data, 1, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (bytes_sent < 0) {
      perror("sendto");
      exit(1);
    }

    // Wait for response
    bytes_recv = recvfrom(sockfd, recv_data, 1024, 0, (struct sockaddr *)&serv_addr, &serv_addr);
    if (bytes_recv < 0) {
      perror("recvfrom");
      exit(1);
    }

    // Get current time
    gettimeofday(&end, NULL);

    // Calculate RTT
    rtt = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    // Print response
    printf("Ping: %s:%d\tRTT: %lf ms\n", argv[1], atoi(argv[2]), rtt);

    // Sleep for 1 second
    sleep(1);
  }

  // Close socket
  close(sockfd);

  return 0;
}