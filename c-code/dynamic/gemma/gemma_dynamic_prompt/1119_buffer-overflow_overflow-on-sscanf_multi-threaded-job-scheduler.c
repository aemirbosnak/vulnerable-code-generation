#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>

void* thread_function(void* arg) {
  char buffer[10];
  scanf("%s", buffer);
  printf("Thread: %s\n", buffer);
  pthread_exit(NULL);
}

int main() {
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, thread_function, NULL);
  pthread_join(thread_id, NULL);
  return 0;
}
