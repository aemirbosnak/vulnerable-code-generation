//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: energetic
// SMTP Client Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "smtp.gmail.com"
#define PORT 587

int main(int argc, char *argv[]) {
  int sock, n;
  char buf[1024];
  struct addrinfo hints, *res, *p;
  struct sockaddr_in server;
  char *message = "Hello, World!";

  // Get server address
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  getaddrinfo(SERVER, PORT, &hints, &res);

  // Create a socket
  sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sock == -1) {
    perror("socket");
    exit(1);
  }

  // Connect to server
  if (connect(sock, res->ai_addr, res->ai_addrlen) == -1) {
    perror("connect");
    exit(1);
  }

  // Send message
  n = send(sock, message, strlen(message), 0);
  if (n == -1) {
    perror("send");
    exit(1);
  }

  // Receive response
  n = recv(sock, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    exit(1);
  }

  // Print response
  printf("Response: %s\n", buf);

  // Close socket
  close(sock);
  return 0;
}