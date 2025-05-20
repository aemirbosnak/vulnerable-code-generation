//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  // Establish a connection to the FTP server
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in serverAddr;
  memset(&serverAddr, 0, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(21);
  if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
    perror("connect");
    return 1;
  }

  // Receive the server's welcome message
  char buf[512];
  int n = recv(sock, buf, sizeof(buf) - 1, 0);
  if (n < 0) {
    perror("recv");
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Send the USER command
  char username[] = "username";
  sprintf(buf, "USER %s\r\n", username);
  n = send(sock, buf, strlen(buf), 0);
  if (n < 0) {
    perror("send");
    return 1;
  }

  // Receive the server's response
  n = recv(sock, buf, sizeof(buf) - 1, 0);
  if (n < 0) {
    perror("recv");
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Send the PASS command
  char password[] = "password";
  sprintf(buf, "PASS %s\r\n", password);
  n = send(sock, buf, strlen(buf), 0);
  if (n < 0) {
    perror("send");
    return 1;
  }

  // Receive the server's response
  n = recv(sock, buf, sizeof(buf) - 1, 0);
  if (n < 0) {
    perror("recv");
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Send the CWD command
  char directory[] = "/public_html";
  sprintf(buf, "CWD %s\r\n", directory);
  n = send(sock, buf, strlen(buf), 0);
  if (n < 0) {
    perror("send");
    return 1;
  }

  // Receive the server's response
  n = recv(sock, buf, sizeof(buf) - 1, 0);
  if (n < 0) {
    perror("recv");
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Send the LIST command
  sprintf(buf, "LIST\r\n");
  n = send(sock, buf, strlen(buf), 0);
  if (n < 0) {
    perror("send");
    return 1;
  }

  // Receive the server's response
  while ((n = recv(sock, buf, sizeof(buf) - 1, 0)) > 0) {
    buf[n] = '\0';
    printf("%s", buf);
  }
  if (n < 0) {
    perror("recv");
    return 1;
  }

  // Send the QUIT command
  sprintf(buf, "QUIT\r\n");
  n = send(sock, buf, strlen(buf), 0);
  if (n < 0) {
    perror("send");
    return 1;
  }

  // Close the connection
  close(sock);

  return 0;
}