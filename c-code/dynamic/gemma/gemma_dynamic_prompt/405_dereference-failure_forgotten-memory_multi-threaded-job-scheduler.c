#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

pthread_t threads[10];
int* thread_data[10];

void* thread_func(void* data) {
  thread_data[pthread_self()] = (int*)data;
  sleep(thread_data[pthread_self()]);
  printf("Thread %d finished\n", thread_data[pthread_self()]);
  return NULL;
}

int main() {
  for(int i = 0; i < 10; i++) {
    thread_data[i] = malloc(sizeof(int));
    pthread_create(&threads[i], NULL, thread_func, (void*)thread_data[i]);
  }

  for(int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
