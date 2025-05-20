//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: standalone
// ftp_client.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 21 // FTP port
#define MAX_BUF 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid server address\n");
    return 1;
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  char buf[MAX_BUF];
  sprintf(buf, "USER %s\r\n", "anonymous");
  send(sock, buf, strlen(buf), 0);

  sprintf(buf, "PASS %s\r\n", "anonymous@");
  send(sock, buf, strlen(buf), 0);

  sprintf(buf, "PASV\r\n");
  send(sock, buf, strlen(buf), 0);

  recv(sock, buf, MAX_BUF, 0);
  printf("%s", buf);

  char* ptr = strstr(buf, "(");
  char* port_str = ptr + 1;
  char* end = strstr(port_str, ")");
  *end = '\0';

  int port = atoi(port_str);
  struct sockaddr_in data_server_addr;
  memset(&data_server_addr, 0, sizeof(data_server_addr));
  data_server_addr.sin_family = AF_INET;
  data_server_addr.sin_port = htons(port);
  data_server_addr.sin_addr = server_addr.sin_addr;

  int data_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (data_sock < 0) {
    perror("socket");
    return 1;
  }

  if (connect(data_sock, (struct sockaddr *)&data_server_addr, sizeof(data_server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  sprintf(buf, "TYPE I\r\n");
  send(data_sock, buf, strlen(buf), 0);

  sprintf(buf, "RETR %s\r\n", argv[2]);
  send(data_sock, buf, strlen(buf), 0);

  FILE* file = fopen(argv[2], "w");
  if (file == NULL) {
    perror("fopen");
    return 1;
  }

  int n;
  while ((n = recv(data_sock, buf, MAX_BUF, 0)) > 0) {
    fwrite(buf, 1, n, file);
  }

  fclose(file);
  close(data_sock);
  close(sock);

  return 0;
}