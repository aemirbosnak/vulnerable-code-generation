#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg) {
  pthread_t thread_id = (pthread_t)arg;
  int *job_id = (int *)pthread_getspecific(thread_id);

  // Invalid memory access
  int data = *(int *)job_id;

  printf("Thread %d: Job ID %d\n", thread_id, data);

  return NULL;
}

int main() {
  pthread_t threads[10];
  int job_id[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)job_id[i]);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
