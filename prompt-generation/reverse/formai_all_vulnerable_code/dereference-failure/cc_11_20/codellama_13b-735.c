//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define POP3_CMD_USER "USER"
#define POP3_CMD_PASS "PASS"
#define POP3_CMD_STAT "STAT"
#define POP3_CMD_LIST "LIST"
#define POP3_CMD_RETR "RETR"
#define POP3_CMD_DELE "DELE"
#define POP3_CMD_NOOP "NOOP"
#define POP3_CMD_QUIT "QUIT"

int main(int argc, char *argv[]) {
  int sock;
  struct sockaddr_in server;
  char buffer[256];
  char *username, *password;
  int ret;

  if (argc != 3) {
    printf("Usage: %s <server> <port>\n", argv[0]);
    return 1;
  }

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[2]));
  server.sin_addr.s_addr = inet_addr(argv[1]);

  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect");
    return 1;
  }

  username = "testuser";
  password = "testpassword";

  ret = send(sock, POP3_CMD_USER, strlen(POP3_CMD_USER), 0);
  if (ret < 0) {
    perror("send");
    return 1;
  }

  ret = send(sock, username, strlen(username), 0);
  if (ret < 0) {
    perror("send");
    return 1;
  }

  ret = send(sock, POP3_CMD_PASS, strlen(POP3_CMD_PASS), 0);
  if (ret < 0) {
    perror("send");
    return 1;
  }

  ret = send(sock, password, strlen(password), 0);
  if (ret < 0) {
    perror("send");
    return 1;
  }

  ret = send(sock, POP3_CMD_STAT, strlen(POP3_CMD_STAT), 0);
  if (ret < 0) {
    perror("send");
    return 1;
  }

  ret = recv(sock, buffer, sizeof(buffer), 0);
  if (ret < 0) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  ret = send(sock, POP3_CMD_LIST, strlen(POP3_CMD_LIST), 0);
  if (ret < 0) {
    perror("send");
    return 1;
  }

  ret = recv(sock, buffer, sizeof(buffer), 0);
  if (ret < 0) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  ret = send(sock, POP3_CMD_RETR, strlen(POP3_CMD_RETR), 0);
  if (ret < 0) {
    perror("send");
    return 1;
  }

  ret = recv(sock, buffer, sizeof(buffer), 0);
  if (ret < 0) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  ret = send(sock, POP3_CMD_DELE, strlen(POP3_CMD_DELE), 0);
  if (ret < 0) {
    perror("send");
    return 1;
  }

  ret = send(sock, "1", strlen("1"), 0);
  if (ret < 0) {
    perror("send");
    return 1;
  }

  ret = send(sock, POP3_CMD_NOOP, strlen(POP3_CMD_NOOP), 0);
  if (ret < 0) {
    perror("send");
    return 1;
  }

  ret = send(sock, POP3_CMD_QUIT, strlen(POP3_CMD_QUIT), 0);
  if (ret < 0) {
    perror("send");
    return 1;
  }

  close(sock);

  return 0;
}