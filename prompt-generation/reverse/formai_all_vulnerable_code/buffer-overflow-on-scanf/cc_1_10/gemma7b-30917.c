//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_PINGS 10

int main() {
  int sockfd, port, i, j, k, l;
  char hostname[256];
  struct sockaddr_in server_addr;
  struct hostent *hp;
  int ping_count = 0;
  char ping_reply[1024];

  printf("Enter hostname: ");
  scanf("%s", hostname);

  port = 5000;
  hp = gethostbyname(hostname);

  if (hp == NULL) {
    fprintf(stderr, "Error getting host information: %s\n", hostname);
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = hp->h_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

  if (sockfd < 0) {
    fprintf(stderr, "Error creating socket: %s\n", hostname);
    exit(1);
  }

  for (i = 0; i < MAX_PINGS; i++) {
    send(sockfd, "PING", 4, 0);

    if (recv(sockfd, ping_reply, 1024, 0) > 0) {
      printf("Reply from %s: %s\n", hostname, ping_reply);
      ping_count++;
    } else {
      fprintf(stderr, "Error receiving reply: %s\n", hostname);
    }

    sleep(1);
  }

  printf("Number of pings: %d\n", ping_count);

  close(sockfd);
  return 0;
}