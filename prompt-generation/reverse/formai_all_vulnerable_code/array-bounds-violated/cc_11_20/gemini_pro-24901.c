//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
  int sock;
  struct sockaddr_in addr;
  char buf[1024];
  int len;
  char *host = "smtp.example.com";
  int port = 25;

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(host);

  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return 1;
  }

  len = recv(sock, buf, sizeof(buf), 0);
  if (len < 0) {
    perror("recv");
    return 1;
  }

  buf[len] = '\0';
  printf("Received: %s\n", buf);

  strcpy(buf, "EHLO example.com\r\n");
  len = send(sock, buf, strlen(buf), 0);
  if (len < 0) {
    perror("send");
    return 1;
  }

  len = recv(sock, buf, sizeof(buf), 0);
  if (len < 0) {
    perror("recv");
    return 1;
  }

  buf[len] = '\0';
  printf("Received: %s\n", buf);

  strcpy(buf, "MAIL FROM: <john@example.com>\r\n");
  len = send(sock, buf, strlen(buf), 0);
  if (len < 0) {
    perror("send");
    return 1;
  }

  len = recv(sock, buf, sizeof(buf), 0);
  if (len < 0) {
    perror("recv");
    return 1;
  }

  buf[len] = '\0';
  printf("Received: %s\n", buf);

  strcpy(buf, "RCPT TO: <jane@example.com>\r\n");
  len = send(sock, buf, strlen(buf), 0);
  if (len < 0) {
    perror("send");
    return 1;
  }

  len = recv(sock, buf, sizeof(buf), 0);
  if (len < 0) {
    perror("recv");
    return 1;
  }

  buf[len] = '\0';
  printf("Received: %s\n", buf);

  strcpy(buf, "DATA\r\n");
  len = send(sock, buf, strlen(buf), 0);
  if (len < 0) {
    perror("send");
    return 1;
  }

  len = recv(sock, buf, sizeof(buf), 0);
  if (len < 0) {
    perror("recv");
    return 1;
  }

  buf[len] = '\0';
  printf("Received: %s\n", buf);

  strcpy(buf, "Subject: Hello World!\r\n\r\nThis is a test email.\r\n.\r\n");
  len = send(sock, buf, strlen(buf), 0);
  if (len < 0) {
    perror("send");
    return 1;
  }

  len = recv(sock, buf, sizeof(buf), 0);
  if (len < 0) {
    perror("recv");
    return 1;
  }

  buf[len] = '\0';
  printf("Received: %s\n", buf);

  close(sock);

  return 0;
}