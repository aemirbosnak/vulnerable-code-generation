#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>

void *thread_func(void *arg) {
  char buffer[1024];
  gets(buffer);
  printf("Thread: %s, Buffer: %s\n", (char *)arg, buffer);
  pthread_exit(NULL);
}

int main() {
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, thread_func, "Thread 1");
  pthread_create(&thread_id, NULL, thread_func, "Thread 2");

  pthread_join(thread_id, NULL);
  pthread_join(thread_id, NULL);

  return 0;
}
