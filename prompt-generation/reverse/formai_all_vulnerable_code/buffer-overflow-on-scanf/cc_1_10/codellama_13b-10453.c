//Code Llama-13B DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define MAX_BUF 1024

int main(int argc, char *argv[]) {
  int sock, valread;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[MAX_BUF];

  if (argc != 3) {
    printf("Usage: %s <ip> <port>\n", argv[0]);
    return 1;
  }

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    printf("Socket creation failed\n");
    return 1;
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  server = gethostbyname(argv[1]);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("Connection failed\n");
    return 1;
  }

  printf("Connected to server\n");

  while (1) {
    printf("Enter command: ");
    scanf("%s", buffer);
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, MAX_BUF);
    valread = recv(sock, buffer, MAX_BUF, 0);
    printf("Received: %s\n", buffer);
  }

  return 0;
}