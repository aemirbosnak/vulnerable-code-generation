#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>

void *thread_func(void *arg) {
  char buffer[10];
  fscanf(stdin, "%s", buffer);
  printf("Thread: %s\n", buffer);
  pthread_exit(NULL);
}

int main() {
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, thread_func, NULL);
  pthread_join(thread_id, NULL);

  return 0;
}
