//Code Llama-13B DATASET v1.0 Category: Drone Remote Control ; Style: genius
// Drone Remote Control Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
  int sock, n;
  struct sockaddr_in server;
  char buffer[BUFFER_SIZE];

  if (argc != 3) {
    printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
    return 1;
  }

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(argv[1]);
  server.sin_port = htons(atoi(argv[2]));

  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect() failed");
    return 1;
  }

  printf("Connected to server\n");

  while (1) {
    memset(buffer, 0, BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE, stdin);
    n = send(sock, buffer, strlen(buffer), 0);
    if (n < 0) {
      perror("send() failed");
      break;
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sock, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
      perror("recv() failed");
      break;
    }

    printf("Received: %s\n", buffer);
  }

  close(sock);
  return 0;
}