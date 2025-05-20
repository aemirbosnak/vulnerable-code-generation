//FormAI DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_PORT 65535
#define MAX_IP_LEN INET_ADDRSTRLEN

int main(int argc, char *argv[]) {
  int sockfd, port, start_port, end_port, error;
  struct addrinfo *res, hints;
  struct sockaddr_in *addr;
  char ip_str[MAX_IP_LEN];
  bool open_ports[MAX_PORT + 1]; // initialized to false
  memset(open_ports, false, sizeof(open_ports));

  if (argc != 4) {
    printf("usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  start_port = atoi(argv[2]);
  end_port = atoi(argv[3]);
  if (start_port < 1 || end_port > MAX_PORT || start_port > end_port) {
    printf("invalid port range: %d-%d\n", start_port, end_port);
    exit(EXIT_FAILURE);
  }

  // resolve the IP address
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = PF_INET;
  hints.ai_socktype = SOCK_STREAM;
  error = getaddrinfo(argv[1], NULL, &hints, &res);
  if (error != 0) {
    fprintf(stderr, "getaddrinfo() error: %s\n", gai_strerror(error));
    exit(EXIT_FAILURE);
  }

  // create a socket
  addr = (struct sockaddr_in *) res->ai_addr;
  inet_ntop(AF_INET, &(addr->sin_addr), ip_str, INET_ADDRSTRLEN);
  printf("Scanning %s...\n", ip_str);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket() error");
    exit(EXIT_FAILURE);
  }

  // scan the ports
  for (port = start_port; port <= end_port; port++) {
    addr->sin_port = htons(port);
    error = connect(sockfd, (struct sockaddr *) addr, sizeof(*addr));
    if (error == 0) {
      printf("Port %d is open\n", port);
      open_ports[port] = true;
    } else if (errno != ECONNREFUSED) {
      perror("connect() error");
    }
  }

  // clean up and print results
  close(sockfd);
  freeaddrinfo(res);
  printf("Scan complete. Open ports:\n");
  for (port = start_port; port <= end_port; port++) {
    if (open_ports[port]) {
      printf("%d\n", port);
    }
  }

  // exit
  return 0;
}