#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_func(void *arg) {
  char buffer[10];
  scanf("%s", buffer);
  printf("Thread: %s, Buffer: %s\n", (int)arg, buffer);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[10];
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)i);
  }
  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
