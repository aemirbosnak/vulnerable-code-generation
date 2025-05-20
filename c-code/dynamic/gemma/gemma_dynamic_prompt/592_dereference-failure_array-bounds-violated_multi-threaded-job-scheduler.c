#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

pthread_t threads[10];
int arr[10] = {0};

void *thread_func(void *arg) {
  int i = (int)arg;
  arr[i] = 10;
  return NULL;
}

int main() {
  pthread_create(threads, NULL, thread_func, (void *)0);
  pthread_create(threads, NULL, thread_func, (void *)1);
  pthread_create(threads, NULL, thread_func, (void *)2);
  pthread_join(threads, NULL);

  return 0;
}
