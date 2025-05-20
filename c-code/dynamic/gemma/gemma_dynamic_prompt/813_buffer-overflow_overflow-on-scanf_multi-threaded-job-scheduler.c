#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>

pthread_t threads[10];
char buffer[1024];

void* thread_func(void* arg) {
  scanf("%s", buffer);
  pthread_exit(NULL);
}

int main() {
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, NULL);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
