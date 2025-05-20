//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_PACKET_SIZE 1500
#define QOS_MONITOR_PORT 5000
#define QOS_MONITOR_INTERVAL 1000 // milliseconds

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno, clilen, sd;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[MAX_PACKET_SIZE];
  int val, max_sd;
  fd_set readfds;
  struct timeval tv;

  if (argc!= 2) {
    printf("Usage: %s <interface>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    printf("socket failed\n");
    exit(1);
  }

  portno = QOS_MONITOR_PORT;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *) &val, sizeof(val)) < 0) {
    printf("setsockopt failed\n");
    exit(1);
  }

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("bind failed\n");
    exit(1);
  }

  while (1) {
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    max_sd = sockfd;

    tv.tv_sec = QOS_MONITOR_INTERVAL / 1000;
    tv.tv_usec = (QOS_MONITOR_INTERVAL % 1000) * 1000;

    if (select(max_sd + 1, &readfds, NULL, NULL, &tv) < 0) {
      printf("select failed\n");
      exit(1);
    }

    if (FD_ISSET(sockfd, &readfds)) {
      clilen = sizeof(cli_addr);
      newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

      if (newsockfd < 0) {
        printf("accept failed\n");
        exit(1);
      }

      if (setsockopt(newsockfd, IPPROTO_IP, IP_TOS, "0xB8", sizeof("0xB8")) < 0) {
        printf("setsockopt failed\n");
        exit(1);
      }

      close(newsockfd);
    }
  }

  return 0;
}