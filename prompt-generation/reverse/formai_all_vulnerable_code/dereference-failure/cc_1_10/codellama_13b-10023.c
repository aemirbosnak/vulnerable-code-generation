//Code Llama-13B DATASET v1.0 Category: Networking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int sock, conn, len;
  struct sockaddr_in server, client;
  char buf[1024];

  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    exit(1);
  }

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[1]));
  server.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("bind");
    exit(1);
  }

  listen(sock, 3);
  len = sizeof(client);
  conn = accept(sock, (struct sockaddr *)&client, &len);
  if (conn < 0) {
    perror("accept");
    exit(1);
  }

  while (1) {
    memset(buf, 0, 1024);
    if (read(conn, buf, 1024) < 0) {
      perror("read");
      exit(1);
    }
    printf("Received: %s\n", buf);
    if (strcmp(buf, "exit") == 0) {
      break;
    }
    memset(buf, 0, 1024);
    printf("Send: ");
    fgets(buf, 1024, stdin);
    if (write(conn, buf, strlen(buf)) < 0) {
      perror("write");
      exit(1);
    }
  }

  close(conn);
  close(sock);
  return 0;
}