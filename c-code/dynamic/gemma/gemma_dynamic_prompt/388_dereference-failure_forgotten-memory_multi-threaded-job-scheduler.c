#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[10];
int *data;

void *thread_func(void *arg) {
  int i = (int)arg;
  data[i] = 10;
  pthread_exit(NULL);
}

int main() {
  data = (int *)malloc(10 * sizeof(int));
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)i);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  free(data);
  return 0;
}
