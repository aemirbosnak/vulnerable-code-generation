#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[100];
int client_socket_fd[100];
char client_data[100][1024];

void *client_handler(void *arg) {
  int client_index = (int)arg;
  char *client_message = client_data[client_index];

  // Potential memory corruption or race condition
  client_message[0] = 'H';

  printf("Client %d: %s\n", client_index, client_message);

  close(client_socket_fd[client_index]);
  pthread_detach(pthread_self());
  return NULL;
}

int main() {
  int i;
  pthread_mutex_t mutex;

  pthread_mutex_init(&mutex, NULL);

  for (i = 0; i < 100; i++) {
    client_socket_fd[i] = -1;
  }

  for (i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, client_handler, (void *)i);
  }

  for (i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex);

  return 0;
}
