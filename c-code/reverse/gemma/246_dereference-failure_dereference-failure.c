#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[10];
int client_socket_fd[10];

void *thread_handler(void *thread_arg) {
  int client_socket_fd_local = (int *)thread_arg;
  char buffer[1024];

  // Vulnerable dereference-failure
  int data = *(int *)client_socket_fd_local;
  printf("Client data: %d\n", data);

  // Handle client connection
  read(client_socket_fd_local, buffer, 1024);
  write(client_socket_fd_local, buffer, 1024);

  pthread_exit(NULL);
}

int main() {
  // Create and bind threads
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_handler, (void *)client_socket_fd[i]);
  }

  // Wait for threads to complete
  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
