//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <server address> <port>\n", argv[0]);
    return 1;
  }

  char *server_address = argv[1];
  int port = atoi(argv[2]);

  struct sockaddr_in server;

  // initialize the socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("unable to create socket");
    return 1;
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(server_address);
  server.sin_port = htons(port);

  // connect to the server
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
    perror("unable to connect to server");
    return 1;
  }

  printf("Connected to server at %s:%d\n", server_address, port);

  while (1) {
    char buffer[MAX_BUFFER_SIZE];

    memset(buffer, 0, MAX_BUFFER_SIZE);

    printf("Enter HTTP request: ");
    if (fgets(buffer, MAX_BUFFER_SIZE, stdin) == NULL) {
      printf("unable to read input\n");
      continue;
    }

    // remove newline character from input
    int len = strlen(buffer);
    if (buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }

    // send the request to the server
    if (send(sock, buffer, strlen(buffer), 0) == -1) {
      perror("unable to send request to server");
      continue;
    }

    printf("Sent request\n");

    // receive the response from the server
    memset(buffer, 0, MAX_BUFFER_SIZE);

    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) == -1) {
      perror("unable to receive response from server");
      continue;
    }

    printf("Received response:\n%s\n", buffer);
  }

  // close the socket
  close(sock);

  return 0;
}