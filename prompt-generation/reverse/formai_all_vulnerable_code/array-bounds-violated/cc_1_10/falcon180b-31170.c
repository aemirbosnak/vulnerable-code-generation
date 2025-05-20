//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BACKLOG 10
#define BUFLEN 1024

int main(int argc, char *argv[]) {
  int opt = 1;
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
    printf("Error setting socket option\n");
    exit(EXIT_FAILURE);
  }

  if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Error binding socket\n");
    exit(EXIT_FAILURE);
  }

  if (listen(server_socket, BACKLOG) < 0) {
    printf("Error listening on socket\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    printf("Waiting for client...\n");
    int client_socket = accept(server_socket, NULL, NULL);
    printf("Client connected\n");

    char message[BUFLEN];
    memset(message, 0, BUFLEN);

    while (1) {
      ssize_t bytes_received = recv(client_socket, message, BUFLEN, 0);
      if (bytes_received <= 0) {
        printf("Client disconnected\n");
        close(client_socket);
        break;
      }

      message[bytes_received - 1] = '\0';
      printf("Received message: %s\n", message);

      time_t now = time(NULL);
      struct tm *local_time = localtime(&now);

      char formatted_time[80];
      strftime(formatted_time, 80, "%Y-%m-%d %H:%M:%S", local_time);

      send(client_socket, formatted_time, strlen(formatted_time), 0);
    }
  }

  close(server_socket);
  return 0;
}