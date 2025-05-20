//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: multiplayer
// smtp_client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <host> <port> <message>\n", argv[0]);
    return 1;
  }

  char *host = argv[1];
  int port = atoi(argv[2]);
  char *message = argv[3];

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return 1;
  }

  // Get the address info
  struct addrinfo hints, *res, *ai;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;

  int err = getaddrinfo(host, port, &hints, &res);
  if (err) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
    return 1;
  }

  // Connect to the server
  for (ai = res; ai; ai = ai->ai_next) {
    if (connect(sock, ai->ai_addr, ai->ai_addrlen) == -1) {
      perror("connect");
      continue;
    }
    break;
  }

  if (ai == NULL) {
    fprintf(stderr, "Failed to connect to %s\n", host);
    return 1;
  }

  // Send the message
  int len = strlen(message);
  int n = send(sock, message, len, 0);
  if (n < len) {
    perror("send");
    return 1;
  }

  // Receive the response
  char buf[BUF_SIZE];
  n = recv(sock, buf, BUF_SIZE, 0);
  if (n < 0) {
    perror("recv");
    return 1;
  }

  // Print the response
  printf("%s\n", buf);

  // Clean up
  close(sock);
  freeaddrinfo(res);

  return 0;
}