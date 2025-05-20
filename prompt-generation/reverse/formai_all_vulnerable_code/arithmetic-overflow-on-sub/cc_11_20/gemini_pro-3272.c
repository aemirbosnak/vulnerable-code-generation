//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <hostname or IP address>\n", argv[0]);
    exit(1);
  }

  char *server = (argv[1]);
  int sockfd;
  struct sockaddr_in servaddr;
  struct timeval start, end, timeout;

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(33434);
  switch (inet_pton(AF_INET, server, &servaddr.sin_addr)) {
    case 1:
      break;
    case 0:
      printf("Invalid address: %s\n", server);
      exit(1);
    case -1:
      perror("inet_pton");
      exit(1);
  }

  timeout.tv_sec = 1;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
    perror("setsockopt");
    exit(1);
  }

  while (1) {
    gettimeofday(&start, NULL);
    if (sendto(sockfd, "PING", 4, 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
      perror("sendto");
      exit(1);
    }

    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);
    int retval = select(sockfd + 1, &rfds, NULL, NULL, &timeout);
    if (retval < 0) {
      perror("select");
      exit(1);
    }
    if (retval == 0) {
      printf("Timeout: no response received\n");
    } else if (FD_ISSET(sockfd, &rfds)) {
      char buffer[4096];
      struct sockaddr_in sender;
      socklen_t sender_len = sizeof(sender);
      int nrecv = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&sender, &sender_len);
      if (nrecv < 0) {
        perror("recvfrom");
        exit(1);
      }

      gettimeofday(&end, NULL);
      double elapsed = ((end.tv_sec - start.tv_sec) * 1000000.0) + ((end.tv_usec - start.tv_usec));
      printf("Received response from %s: %s (%.3f ms)\n", inet_ntoa(sender.sin_addr), buffer, elapsed / 1000.0);
    }
  }

  close(sockfd);
  return 0;
}