//Falcon-180B DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT "8080"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, addrlen, client_len;
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUFFER_SIZE];
  char *message = "Welcome to the server!";
  int opt = 1;
  int client_socket;
  int bytes_received;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(atoi(PORT));

  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(sockfd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  printf("Server is listening on port %s\n", PORT);

  while (1) {
    addrlen = sizeof(client_addr);
    client_socket = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);

    if (client_socket < 0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
      perror("recv");
      exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0';
    printf("Client sent message: %s\n", buffer);

    send(client_socket, message, strlen(message), 0);
  }

  close(sockfd);
  return 0;
}