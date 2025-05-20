#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

void *thread(void *arg) {
  int *ptr = (int *)arg;
  char buf[10] = "Hello, world!";
  buf[*ptr] = 'A';
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[10];
  int i;
  for (i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread, (void *)i);
  }
  for (i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
