#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>

void *thread_func(void *arg) {
  char buffer[10];
  gets(buffer);
  printf("Thread: %s, Data: %s\n", (char *)arg, buffer);
  return NULL;
}

int main() {
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, thread_func, "Thread 1");
  pthread_create(&thread_id, NULL, thread_func, "Thread 2");
  pthread_join(thread_id, NULL);
  pthread_join(thread_id, NULL);
  return 0;
}
