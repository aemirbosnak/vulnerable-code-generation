#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>

pthread_t threads[10];
char buffers[10][1024];

void* thread_func(void* thread_num) {
  int i = (int)thread_num;
  char buffer[1024];
  gets(buffer);
  strcpy(buffers[i], buffer);
  pthread_exit(NULL);
}

int main() {
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void*)i);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  for (int i = 0; i < 10; i++) {
    printf("%s\n", buffers[i]);
  }

  return 0;
}
