#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_CLIENTS 10

pthread_t threads[MAX_CLIENTS];
int client_sockets[MAX_CLIENTS];

void* handle_client(int sockfd) {
  char message[1024];
  recv(sockfd, message, 1024, 0);
  send(sockfd, message, strlen(message) + 1, 0);
  close(sockfd);
  return NULL;
}

int main() {
  int listen_fd, client_fd;
  struct sockaddr_in server_addr, client_addr;
  pthread_t thread_id;

  listen_fd = socket(AF_INET, SOCK_STREAM, htons(80));
  bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  while (1) {
    client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, NULL);
    client_sockets[client_fd] = client_fd;
    pthread_create(&threads[client_fd], NULL, handle_client, (void *)client_fd);
  }

  for (int i = 0; i < MAX_CLIENTS; i++) {
    pthread_join(threads[i], NULL);
  }

  close(listen_fd);
  return 0;
}
