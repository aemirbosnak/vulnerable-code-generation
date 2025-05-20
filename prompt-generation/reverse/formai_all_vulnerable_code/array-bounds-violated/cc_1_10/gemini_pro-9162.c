//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define MAX_MSG_LEN 1024

struct client {
  int sockfd;
  char username[32];
  char password[32];
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
  int sockfd = *(int *)arg;
  char msg[MAX_MSG_LEN];
  int len;

  // Receive username
  len = recv(sockfd, msg, MAX_MSG_LEN, 0);
  msg[len] = '\0';
  strcpy(clients[num_clients].username, msg);

  // Receive password
  len = recv(sockfd, msg, MAX_MSG_LEN, 0);
  msg[len] = '\0';
  strcpy(clients[num_clients].password, msg);

  // Send welcome message
  snprintf(msg, MAX_MSG_LEN, "Welcome, %s!\n", clients[num_clients].username);
  send(sockfd, msg, strlen(msg), 0);

  // Receive and broadcast messages
  while ((len = recv(sockfd, msg, MAX_MSG_LEN, 0)) > 0) {
    msg[len] = '\0';

    // Broadcast message to all other clients
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < num_clients; i++) {
      if (i == num_clients) continue;
      send(clients[i].sockfd, msg, strlen(msg), 0);
    }
    pthread_mutex_unlock(&mutex);
  }

  // Client disconnected
  pthread_mutex_lock(&mutex);
  num_clients--;
  pthread_mutex_unlock(&mutex);

  close(sockfd);
  return NULL;
}

int main() {
  int server_sockfd, client_sockfd;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_addr_len;

  // Create server socket
  server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Set server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(8080);

  // Bind socket to address
  if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(server_sockfd, MAX_CLIENTS) == -1) {
    perror("listen");
    exit(1);
  }

  // Accept incoming connections and create threads
  while (1) {
    client_addr_len = sizeof(client_addr);
    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd == -1) {
      perror("accept");
      exit(1);
    }

    pthread_t thread;
    if (pthread_create(&thread, NULL, handle_client, &client_sockfd) != 0) {
      perror("pthread_create");
      exit(1);
    }

    pthread_mutex_lock(&mutex);
    clients[num_clients].sockfd = client_sockfd;
    num_clients++;
    pthread_mutex_unlock(&mutex);
  }

  // Close server socket
  close(server_sockfd);

  return 0;
}