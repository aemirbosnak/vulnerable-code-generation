//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

typedef struct {
  int sockfd;
  struct sockaddr_in addr;
} client_t;

typedef struct {
  client_t clients[MAX_CONNECTIONS];
  int num_clients;
} chat_server_t;

chat_server_t server;

void *handle_client(void *arg) {
  client_t *client = (client_t *)arg;
  char buf[1024];
  int n;
  while ((n = recv(client->sockfd, buf, sizeof(buf), 0)) > 0) {
    buf[n] = '\0';
    printf("Received from client: %s\n", buf);
    for (int i = 0; i < server.num_clients; i++) {
      if (server.clients[i].sockfd != client->sockfd) {
        send(server.clients[i].sockfd, buf, n, 0);
      }
    }
  }
  close(client->sockfd);
  server.num_clients--;
  return NULL;
}

int main() {
  int sockfd, new_sockfd;
  struct sockaddr_in addr;
  pthread_t tid;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Failed to create socket");
    return 1;
  }

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("Failed to bind socket");
    return 1;
  }

  if (listen(sockfd, MAX_CONNECTIONS) == -1) {
    perror("Failed to listen on socket");
    return 1;
  }

  while (1) {
    new_sockfd = accept(sockfd, (struct sockaddr *)&addr, (socklen_t *)&addr);
    if (new_sockfd == -1) {
      perror("Failed to accept connection");
      continue;
    }

    printf("New client connected from %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));

    server.clients[server.num_clients].sockfd = new_sockfd;
    server.clients[server.num_clients].addr = addr;
    server.num_clients++;

    pthread_create(&tid, NULL, handle_client, (void *)&server.clients[server.num_clients - 1]);
  }

  close(sockfd);
  return 0;
}