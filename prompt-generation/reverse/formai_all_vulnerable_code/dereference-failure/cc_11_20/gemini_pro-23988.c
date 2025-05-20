//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>

#define BUF_LEN 1024

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <listen-port>\n", argv[0]);
    return -1;
  }

  struct sockaddr_in server_addr, client_addr;
  int listen_fd, client_fd;
  char buf[BUF_LEN];
  socklen_t client_addr_len;
  int recv_len, send_len;
  int port = atoi(argv[1]);

  // Create a TCP listening socket
  listen_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_fd < 0) {
    perror("socket");
    return -1;
  }

  // Set the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(port);

  // Bind the socket to the server address
  if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    close(listen_fd);
    return -1;
  }

  // Start listening for incoming connections
  if (listen(listen_fd, 5) < 0) {
    perror("listen");
    close(listen_fd);
    return -1;
  }

  printf("HTTP Proxy listening on port %d\n", port);

  // Main loop: accept incoming connections and handle requests
  while (1) {
    // Accept an incoming connection
    client_addr_len = sizeof(client_addr);
    client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_fd < 0) {
      perror("accept");
      continue;
    }

    // Read the request from the client
    memset(buf, 0, BUF_LEN);
    recv_len = recv(client_fd, buf, BUF_LEN, 0);
    if (recv_len <= 0) {
      perror("recv");
      close(client_fd);
      continue;
    }

    // Parse the request to get the target host and port
    char *host = strstr(buf, "Host: ");
    if (host == NULL) {
      printf("Invalid request: no Host header\n");
      close(client_fd);
      continue;
    }

    host += strlen("Host: ");
    char *port_str = strchr(host, ':');
    int target_port;
    if (port_str == NULL) {
      target_port = 80;
    } else {
      *port_str = '\0';
      target_port = atoi(port_str + 1);
    }

    // Create a TCP socket to connect to the target host
    int target_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (target_fd < 0) {
      perror("socket");
      close(client_fd);
      continue;
    }

    // Set the target host address
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(target_port);
    if (inet_pton(AF_INET, host, &target_addr.sin_addr) <= 0) {
      perror("inet_pton");
      close(target_fd);
      close(client_fd);
      continue;
    }

    // Connect to the target host
    if (connect(target_fd, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
      perror("connect");
      close(target_fd);
      close(client_fd);
      continue;
    }

    // Forward the request to the target host
    send_len = send(target_fd, buf, recv_len, 0);
    if (send_len <= 0) {
      perror("send");
      close(target_fd);
      close(client_fd);
      continue;
    }

    // Receive the response from the target host
    memset(buf, 0, BUF_LEN);
    recv_len = recv(target_fd, buf, BUF_LEN, 0);
    if (recv_len <= 0) {
      perror("recv");
      close(target_fd);
      close(client_fd);
      continue;
    }

    // Send the response to the client
    send_len = send(client_fd, buf, recv_len, 0);
    if (send_len <= 0) {
      perror("send");
      close(target_fd);
      close(client_fd);
      continue;
    }

    // Close the connections
    close(target_fd);
    close(client_fd);
  }

  // Close the listening socket
  close(listen_fd);

  return 0;
}