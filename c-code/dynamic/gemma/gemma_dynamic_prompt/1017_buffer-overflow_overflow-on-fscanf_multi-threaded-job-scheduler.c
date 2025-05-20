#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* thread_function(void* thread_id) {
  int job_id = (int)thread_id;
  char buffer[1024];
  fscanf(stdin, "%s", buffer);
  printf("Job %d: Received command: %s\n", job_id, buffer);
  return NULL;
}

int main() {
  pthread_t threads[10];
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_function, (void*)i);
  }
  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
