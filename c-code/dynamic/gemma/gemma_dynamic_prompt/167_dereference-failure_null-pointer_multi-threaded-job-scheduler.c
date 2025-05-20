#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_func(void *arg) {
  pthread_t thread_id = (pthread_t)arg;
  int *job_id = (int *)pthread_getspecific(thread_id);
  printf("Thread %ld: Job ID %d\n", thread_id, *job_id);
  return NULL;
}

int main() {
  pthread_t threads[10];
  int job_ids[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)job_ids[i]);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
