//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int port, sock, max_fd;
  struct sockaddr_in server;
  char buffer[BUFFER_SIZE];
  fd_set master_fds, read_fds;

  if (argc!= 3) {
    printf("Usage: %s <IP Address> <Port>\n", argv[0]);
    exit(1);
  }

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    printf("Error creating socket.\n");
    exit(1);
  }

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[2]));
  inet_pton(AF_INET, argv[1], &server.sin_addr);

  if (connect(sock, (struct sockaddr *)&server, sizeof(server))!= 0) {
    printf("Error connecting to server.\n");
    exit(1);
  }

  FD_ZERO(&master_fds);
  FD_ZERO(&read_fds);
  FD_SET(sock, &master_fds);
  max_fd = sock;

  for (port = 1; port <= MAX_PORTS; port++) {
    if (port == atoi(argv[2]))
      continue;

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
      printf("Port %d is open.\n", port);
      close(sock);
      exit(0);
    } else {
      printf("Port %d is closed.\n", port);
    }
  }

  while (1) {
    read_fds = master_fds;
    if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) == -1) {
      printf("Error selecting.\n");
      exit(1);
    }

    if (FD_ISSET(sock, &read_fds)) {
      memset(buffer, 0, BUFFER_SIZE);
      if (recv(sock, buffer, BUFFER_SIZE, 0) <= 0) {
        printf("Error receiving data.\n");
        exit(1);
      }
      printf("%s", buffer);
    }
  }

  return 0;
}