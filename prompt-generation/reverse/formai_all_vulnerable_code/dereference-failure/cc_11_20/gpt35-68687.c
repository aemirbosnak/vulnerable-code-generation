//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <server_ip> <port>\n", argv[0]);
    exit(1);
  }

  // Create a socket
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd < 0) {
    perror("socket");
    exit(1);
  }

  // Resolve server IP address
  struct hostent *server = gethostbyname(argv[1]);
  if (server == NULL) {
    printf("Unable to resolve host %s\n", argv[1]);
    exit(1);
  }

  // Set up server address
  struct sockaddr_in server_addr;
  bzero((char *)&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr_list[0], (char *)&server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(atoi(argv[2]));

  // Connect to server
  if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Send HELO command
  char buf[BUF_SIZE];
  sprintf(buf, "HELO %s\r\n", argv[1]);
  if (send(sock_fd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive response
  char resp[BUF_SIZE];
  if (recv(sock_fd, resp, BUF_SIZE, 0) < 0) {
    perror("recv");
    exit(1);
  }

  // Print response
  printf("%s", resp);

  // Send MAIL FROM command
  sprintf(buf, "MAIL FROM:<user@domain.com>\r\n");
  if (send(sock_fd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive response
  if (recv(sock_fd, resp, BUF_SIZE, 0) < 0) {
    perror("recv");
    exit(1);
  }

  // Print response
  printf("%s", resp);

  // Send RCPT TO command
  sprintf(buf, "RCPT TO:<recipient@domain.com>\r\n");
  if (send(sock_fd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive response
  if (recv(sock_fd, resp, BUF_SIZE, 0) < 0) {
    perror("recv");
    exit(1);
  }

  // Print response
  printf("%s", resp);

  // Send DATA command
  sprintf(buf, "DATA\r\n");
  if (send(sock_fd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive response
  if (recv(sock_fd, resp, BUF_SIZE, 0) < 0) {
    perror("recv");
    exit(1);
  }

  // Print response
  printf("%s", resp);

  // Send message body
  sprintf(buf, "From: user@domain.com\r\nTo: recipient@domain.com\r\nSubject: Test email\r\n\r\nHello, this is a test email.\r\n.\r\n");
  if (send(sock_fd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive response
  if (recv(sock_fd, resp, BUF_SIZE, 0) < 0) {
    perror("recv");
    exit(1);
  }

  // Print response
  printf("%s", resp);

  // Send QUIT command
  sprintf(buf, "QUIT\r\n");
  if (send(sock_fd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive response
  if (recv(sock_fd, resp, BUF_SIZE, 0) < 0) {
    perror("recv");
    exit(1);
  }

  // Print response
  printf("%s", resp);

  // Close connection
  close(sock_fd);

  return 0;
}