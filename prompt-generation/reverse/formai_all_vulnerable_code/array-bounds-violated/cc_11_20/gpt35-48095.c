//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <mail server IP>\n", argv[0]);
    exit(1);
  }

  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0) {
    perror("socket");
    exit(1);
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SMTP_PORT);
  inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

  if (connect(fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  char buffer[1024];
  int n = recv(fd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("recv");
    exit(1);
  }
  buffer[n] = 0;
  printf("%s", buffer);

  char* helo_cmd = "HELO example.com\r\n";
  if (send(fd, helo_cmd, strlen(helo_cmd), 0) < strlen(helo_cmd)) {
    perror("send");
    exit(1);
  }

  n = recv(fd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("recv");
    exit(1);
  }
  buffer[n] = 0;
  printf("%s", buffer);

  char* mail_from_cmd = "MAIL FROM:<sender@example.com>\r\n";
  if (send(fd, mail_from_cmd, strlen(mail_from_cmd), 0) < strlen(mail_from_cmd)) {
    perror("send");
    exit(1);
  }

  n = recv(fd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("recv");
    exit(1);
  }
  buffer[n] = 0;
  printf("%s", buffer);

  char* rcpt_to_cmd = "RCPT TO:<recipient@example.com>\r\n";
  if (send(fd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) < strlen(rcpt_to_cmd)) {
    perror("send");
    exit(1);
  }

  n = recv(fd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("recv");
    exit(1);
  }
  buffer[n] = 0;
  printf("%s", buffer);

  char* data_cmd = "DATA\r\n";
  if (send(fd, data_cmd, strlen(data_cmd), 0) < strlen(data_cmd)) {
    perror("send");
    exit(1);
  }

  n = recv(fd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("recv");
    exit(1);
  }
  buffer[n] = 0;
  printf("%s", buffer);

  char* message = "From: sender@example.com\r\n"
                  "To: recipient@example.com\r\n"
                  "Subject: Test\r\n\r\n"
                  "This is a test message.\r\n.\r\n";

  if (send(fd, message, strlen(message), 0) < strlen(message)) {
    perror("send");
    exit(1);
  }

  n = recv(fd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("recv");
    exit(1);
  }
  buffer[n] = 0;
  printf("%s", buffer);

  char* quit_cmd = "QUIT\r\n";
  if (send(fd, quit_cmd, strlen(quit_cmd), 0) < strlen(quit_cmd)) {
    perror("send");
    exit(1);
  }

  n = recv(fd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("recv");
    exit(1);
  }
  buffer[n] = 0;
  printf("%s", buffer);

  close(fd);

  return 0;
}