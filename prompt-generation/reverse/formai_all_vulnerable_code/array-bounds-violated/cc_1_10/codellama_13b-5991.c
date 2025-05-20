//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: surrealist
// A surrealist socket program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
  // create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  // configure socket
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(8080);
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  // connect to the server
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect failed");
    exit(EXIT_FAILURE);
  }

  // send data
  char message[] = "Hello, world!";
  if (send(sock, message, strlen(message), 0) < 0) {
    perror("send failed");
    exit(EXIT_FAILURE);
  }

  // receive data
  char buffer[1024];
  int bytes_received = recv(sock, buffer, 1024, 0);
  if (bytes_received < 0) {
    perror("recv failed");
    exit(EXIT_FAILURE);
  }
  buffer[bytes_received] = '\0';

  // print received data
  printf("Received: %s\n", buffer);

  // close the socket
  close(sock);

  return EXIT_SUCCESS;
}