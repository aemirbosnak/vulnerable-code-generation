//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <sys/time.h>
  #include <time.h>

  #define PORT_RANGE 1024
  #define MAX_PORTS 65535
  #define MAX_CONNECTIONS 10

  int main(int argc, char *argv[]) {
    int sock, port, i;
    struct sockaddr_in server;
    struct timeval timeout;
    fd_set read_fds;
    int max_fd;

    if (argc < 2) {
      printf("Usage: %s <ip address>\n", argv[0]);
      return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
      perror("socket");
      return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = 0;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
      perror("connect");
      return 1;
    }

    port = ntohs(server.sin_port);

    for (i = 0; i < MAX_CONNECTIONS; i++) {
      if (i % 2 == 0) {
        server.sin_port = htons(port + i);
      } else {
        server.sin_port = htons(port - i);
      }

      if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
      }

      FD_ZERO(&read_fds);
      FD_SET(sock, &read_fds);
      timeout.tv_sec = 1;
      timeout.tv_usec = 0;
      select(sock + 1, &read_fds, NULL, NULL, &timeout);

      if (FD_ISSET(sock, &read_fds)) {
        printf("Port %d is open\n", port + i);
      } else {
        printf("Port %d is closed\n", port + i);
      }
    }

    close(sock);
    return 0;
  }