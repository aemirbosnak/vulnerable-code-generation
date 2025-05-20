//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define SERVER_ADDRESS "localhost"
#define SERVER_PORT 8080

int main() {
  int client_socket, bytes_received;
  char buffer[BUFFER_SIZE];
  struct sockaddr_in server_address;

  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    perror("socket");
    exit(1);
  }

  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  inet_pton(AF_INET, SERVER_ADDRESS, &server_address.sin_addr);

  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("connect");
    exit(1);
  }

  while (1) {
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
      break;
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);
  }

  close(client_socket);
  return 0;
}