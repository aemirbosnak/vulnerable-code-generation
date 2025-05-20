//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 5000
#define MAX_CLIENTS 10
#define MAX_MESSAGE_LEN 1024

typedef struct {
  int sockfd;
  char username[20];
} Client;

Client clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast_message(char *message) {
  for (int i = 0; i < num_clients; i++) {
    send(clients[i].sockfd, message, strlen(message), 0);
  }
}

void handle_client(int sockfd) {
  char buffer[MAX_MESSAGE_LEN];
  while (1) {
    int len = recv(sockfd, buffer, MAX_MESSAGE_LEN, 0);
    if (len == 0) {
      printf("Client disconnected\n");
      close(sockfd);
      break;
    } else if (len < 0) {
      perror("recv");
      close(sockfd);
      break;
    }

    buffer[len] = '\0';
    printf("Received message: %s\n", buffer);
    broadcast_message(buffer);
  }
}

int main() {
  int serverfd, clientfd;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_addr_len;

  serverfd = socket(AF_INET, SOCK_STREAM, 0);
  if (serverfd < 0) {
    perror("socket");
    return 1;
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  if (bind(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    close(serverfd);
    return 1;
  }

  if (listen(serverfd, MAX_CLIENTS) < 0) {
    perror("listen");
    close(serverfd);
    return 1;
  }

  printf("Server listening on port %d\n", PORT);

  while (1) {
    client_addr_len = sizeof(client_addr);
    clientfd = accept(serverfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (clientfd < 0) {
      perror("accept");
      continue;
    }

    if (num_clients >= MAX_CLIENTS) {
      send(clientfd, "Server full", strlen("Server full"), 0);
      close(clientfd);
      continue;
    }

    char welcome_message[MAX_MESSAGE_LEN];
    sprintf(welcome_message, "Welcome to the chat server, %s!", inet_ntoa(client_addr.sin_addr));
    send(clientfd, welcome_message, strlen(welcome_message), 0);

    printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

    clients[num_clients].sockfd = clientfd;
    strcpy(clients[num_clients].username, inet_ntoa(client_addr.sin_addr));
    num_clients++;

    handle_client(clientfd);
  }

  close(serverfd);
  return 0;
}