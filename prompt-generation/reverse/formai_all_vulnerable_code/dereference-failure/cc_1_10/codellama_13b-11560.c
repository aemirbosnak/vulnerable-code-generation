//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: happy
// Building a SMTP Client in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024
#define MAX_ADDRESS_SIZE 256

int main(int argc, char **argv) {
  if (argc != 4) {
    printf("Usage: %s <server_ip> <server_port> <message>\n", argv[0]);
    return 1;
  }

  // Get server IP and port
  char *server_ip = argv[1];
  int server_port = atoi(argv[2]);
  char *message = argv[3];

  // Create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Set server address
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(server_port);
  inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send message
  char buf[MAX_BUF_SIZE];
  sprintf(buf, "HELO %s\r\n", inet_ntoa(server_addr.sin_addr));
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  sprintf(buf, "MAIL FROM:<%s>\r\n", "from@example.com");
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  sprintf(buf, "RCPT TO:<%s>\r\n", "to@example.com");
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  sprintf(buf, "DATA\r\n");
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  sprintf(buf, "%s\r\n", message);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  sprintf(buf, ".\r\n");
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Close socket
  close(sock);

  return 0;
}