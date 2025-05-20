//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <user>\n", argv[0]);
    exit(1);
  }

  char *host = argv[1];
  char *user = argv[2];

  struct hostent *server = gethostbyname(host);
  if (!server) {
    fprintf(stderr, "Error: host not found\n");
    exit(1);
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    exit(1);
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(POP3_PORT);
  server_addr.sin_addr = *((struct in_addr *)server->h_addr);

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  char buffer[256];
  int bytes_read;

  // Send user
  if (send(sock, "USER ", 5, 0) < 0) {
    perror("send");
    exit(1);
  }

  // Read server response
  bytes_read = recv(sock, buffer, 255, 0);
  if (bytes_read < 0) {
    perror("recv");
    exit(1);
  }

  buffer[bytes_read] = '\0';
  printf("Server response: %s\n", buffer);

  // Send pass
  if (send(sock, "PASS ", 5, 0) < 0) {
    perror("send");
    exit(1);
  }

  // Read server response
  bytes_read = recv(sock, buffer, 255, 0);
  if (bytes_read < 0) {
    perror("recv");
    exit(1);
  }

  buffer[bytes_read] = '\0';
  printf("Server response: %s\n", buffer);

  // Send STAT
  if (send(sock, "STAT\r\n", 5, 0) < 0) {
    perror("send");
    exit(1);
  }

  // Read server response
  bytes_read = recv(sock, buffer, 255, 0);
  if (bytes_read < 0) {
    perror("recv");
    exit(1);
  }

  buffer[bytes_read] = '\0';
  printf("Server response: %s\n", buffer);

  // Send QUIT
  if (send(sock, "QUIT\r\n", 5, 0) < 0) {
    perror("send");
    exit(1);
  }

  // Read server response
  bytes_read = recv(sock, buffer, 255, 0);
  if (bytes_read < 0) {
    perror("recv");
    exit(1);
  }

  buffer[bytes_read] = '\0';
  printf("Server response: %s\n", buffer);

  close(sock);
  return 0;
}