//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <port> <destination>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create the listener socket
  int listener_fd;
  if ((listener_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set socket options to reuse address and port
  int optval = 1;
  if (setsockopt(listener_fd, SOL_SOCKET, SO_REUSEADDR, &optval,
                 sizeof(optval)) < 0) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to the provided port
  struct sockaddr_in serv_addr = {
      .sin_family = AF_INET,
      .sin_addr.s_addr = htonl(INADDR_ANY),
      .sin_port = htons(atoi(argv[1])),
  };
  if (bind(listener_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(listener_fd, 10) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  printf("Listening on port %s...\n", argv[1]);

  while (1) {
    // Accept an incoming connection
    int conn_fd;
    if ((conn_fd = accept(listener_fd, NULL, NULL)) < 0) {
      perror("accept");
      continue;
    }

    printf("Accepted connection\n");

    // Create a new socket to connect with the destination server
    int server_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      perror("socket");
      close(conn_fd);
      continue;
    }

    // Look up the destination address and port
    struct addrinfo hints = {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_STREAM,
    };
    struct addrinfo *results;
    if (getaddrinfo(argv[2], "80", &hints, &results) != 0) {
      perror("getaddrinfo");
      close(conn_fd);
      close(server_fd);
      continue;
    }
    struct sockaddr_in *dest_addr = (struct sockaddr_in *)results->ai_addr;

    // Connect to the destination server
    if (connect(server_fd, (struct sockaddr *)dest_addr, sizeof(*dest_addr)) <
        0) {
      perror("connect");
      freeaddrinfo(results);
      close(conn_fd);
      close(server_fd);
      continue;
    }
    freeaddrinfo(results);

    // Forward traffic in both directions
    char buf[BUF_SIZE];
    ssize_t nbytes;
    while ((nbytes = read(conn_fd, buf, sizeof(buf))) > 0) {
      if (write(server_fd, buf, nbytes) < 0) {
        perror("write");
        break;
      }
    }
    close(server_fd);

    while ((nbytes = read(conn_fd, buf, sizeof(buf))) > 0) {
      if (write(conn_fd, buf, nbytes) < 0) {
        perror("write");
        break;
      }
    }
    close(conn_fd);
  }

  return 0;
}