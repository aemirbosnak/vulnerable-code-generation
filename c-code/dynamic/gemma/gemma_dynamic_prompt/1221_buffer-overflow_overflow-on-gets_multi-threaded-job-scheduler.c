#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>

void *thread(void *arg) {
  char buffer[1024];
  gets(buffer);
  printf("Thread: %s\n", buffer);
  pthread_exit(NULL);
}

int main() {
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, thread, NULL);
  pthread_join(thread_id, NULL);
  return 0;
}
