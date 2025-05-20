//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
int main() {
  int sock, port;
  struct sockaddr_in server_addr;
  char buf[1024];
  printf("Enter the SMTP server IP address: ");
  scanf("%s", buf);
  printf("Enter the SMTP server port: ");
  scanf("%d", &port);
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return 1;
  }
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, buf, &server_addr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }
  printf("Connected to SMTP server at %s:%d\n", buf, port);
  printf("Enter the sender email address: ");
  scanf("%s", buf);
  snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", buf);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }
  printf("Enter the recipient email address: ");
  scanf("%s", buf);
  snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", buf);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }
  printf("Enter the email subject: ");
  scanf("%s", buf);
  snprintf(buf, sizeof(buf), "SUBJECT: %s\r\n", buf);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }
  printf("Enter the email body:\n");
  while (fgets(buf, sizeof(buf), stdin)) {
    if (strcmp(buf, ".\r\n") == 0) {
      break;
    }
    if (send(sock, buf, strlen(buf), 0) < 0) {
      perror("send");
      return 1;
    }
  }
  if (send(sock, ".\r\n", 3, 0) < 0) {
    perror("send");
    return 1;
  }
  printf("Email sent\n");
  close(sock);
  return 0;
}