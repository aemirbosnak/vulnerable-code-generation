//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: happy
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
  // Check if we have enough arguments
  if (argc < 5) {
    printf("Usage: %s <server> <port> <sender> <recipient> [message]\n", argv[0]);
    return 1;
  }

  // Parse the arguments
  char *server = argv[1];
  int port = atoi(argv[2]);
  char *sender = argv[3];
  char *recipient = argv[4];
  char *message = argc > 5 ? argv[5] : "Hello, world!";

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Connect to the server
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  if (inet_aton(server, &addr.sin_addr) == 0) {
    perror("inet_aton");
    return 1;
  }
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send the HELO command
  char buf[1024];
  snprintf(buf, sizeof(buf), "HELO %s\r\n", "example.com");
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the response
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }

  // Send the MAIL FROM command
  snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", sender);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the response
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }

  // Send the RCPT TO command
  snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", recipient);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the response
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }

  // Send the DATA command
  snprintf(buf, sizeof(buf), "DATA\r\n");
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the response
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }

  // Send the message
  snprintf(buf, sizeof(buf), "%s\r\n", message);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send the QUIT command
  snprintf(buf, sizeof(buf), "QUIT\r\n");
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the response
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }

  // Close the socket
  close(sock);

  return 0;
}