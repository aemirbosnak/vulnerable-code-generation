//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define IMAP_PORT 143

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <username>\n", argv[0]);
    return 1;
  }

  char *host = argv[1];
  char *username = argv[2];

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Set up the address structure
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(IMAP_PORT);
  if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
    fprintf(stderr, "inet_pton failed\n");
    return 1;
  }

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send the username
  char *send_buf = "a001 login ";
  send_buf = strcat(send_buf, username);
  send_buf = strcat(send_buf, "\r\n");
  if (send(sock, send_buf, strlen(send_buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Read the response
  char recv_buf[1024];
  if (recv(sock, recv_buf, sizeof(recv_buf), 0) < 0) {
    perror("recv");
    return 1;
  }

  // Print the response
  printf("Response: %s\n", recv_buf);

  // Close the socket
  close(sock);

  return 0;
}