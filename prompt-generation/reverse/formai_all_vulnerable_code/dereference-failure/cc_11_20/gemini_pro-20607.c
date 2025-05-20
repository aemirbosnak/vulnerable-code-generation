//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define PORT_RANGE 65535
#define MAX_CONNECTIONS 10

struct sockaddr_in server_addr;

int main(int argc, char *argv[]) {
  int sockfd, i, j, port, n;
  char *ip_addr;
  socklen_t addr_len;
  struct timeval timeout;
  fd_set readfds;
  int maxfd = 0;
  int connections[MAX_CONNECTIONS];
  int num_connections = 0;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip_addr> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  ip_addr = argv[1];
  port = atoi(argv[2]);

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);

  if (inet_pton(AF_INET, ip_addr, &server_addr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  connections[num_connections++] = sockfd;
  maxfd = sockfd;

  while (1) {
    FD_ZERO(&readfds);
    for (i = 0; i < num_connections; i++) {
      FD_SET(connections[i], &readfds);
    }

    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    if ((n = select(maxfd + 1, &readfds, NULL, NULL, &timeout)) == -1) {
      perror("select");
      exit(EXIT_FAILURE);
    }

    if (n == 0) {
      continue;
    }

    for (i = 0; i < num_connections; i++) {
      if (FD_ISSET(connections[i], &readfds)) {
        char buffer[1024];

        if ((n = recv(connections[i], buffer, sizeof(buffer), 0)) == 0) {
          close(connections[i]);
          connections[i] = connections[num_connections - 1];
          num_connections--;
          maxfd = 0;
          for (j = 0; j < num_connections; j++) {
            if (connections[j] > maxfd) {
              maxfd = connections[j];
            }
          }
        } else {
          buffer[n] = '\0';
          printf("%s", buffer);
        }
      }
    }
  }

  close(sockfd);

  return 0;
}