//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// A simple SMTP client that sends an email.

int main(int argc, char **argv) {
  if (argc != 6) {
    printf("Usage: %s <server> <port> <sender> <recipient> <message>\n", argv[0]);
    return 1;
  }

  // Create a socket.
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Connect to the SMTP server.
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[2]));
  addr.sin_addr.s_addr = inet_addr(argv[1]);
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Read the SMTP server's greeting.
  char buf[1024];
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s", buf);

  // Send the HELO command.
  sprintf(buf, "HELO %s\r\n", argv[1]);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Read the SMTP server's response.
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s", buf);

  // Send the MAIL FROM command.
  sprintf(buf, "MAIL FROM: <%s>\r\n", argv[3]);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Read the SMTP server's response.
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s", buf);

  // Send the RCPT TO command.
  sprintf(buf, "RCPT TO: <%s>\r\n", argv[4]);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Read the SMTP server's response.
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s", buf);

  // Send the DATA command.
  if (send(sock, "DATA\r\n", 6, 0) < 0) {
    perror("send");
    return 1;
  }

  // Read the SMTP server's response.
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s", buf);

  // Send the message.
  if (send(sock, argv[5], strlen(argv[5]), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send the dot (.) to indicate the end of the message.
  if (send(sock, ".\r\n", 3, 0) < 0) {
    perror("send");
    return 1;
  }

  // Read the SMTP server's response.
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s", buf);

  // Send the QUIT command.
  if (send(sock, "QUIT\r\n", 6, 0) < 0) {
    perror("send");
    return 1;
  }

  // Read the SMTP server's response.
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s", buf);

  // Close the socket.
  close(sock);

  return 0;
}