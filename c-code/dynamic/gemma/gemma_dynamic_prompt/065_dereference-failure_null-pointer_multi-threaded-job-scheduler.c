#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t threads[10];
int job_queue[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void* thread_function(void* thread_id) {
  int i = (int)thread_id;
  while (1) {
    if (job_queue[i] != NULL) {
      printf("Thread %d: Executing job %d\n", i, job_queue[i]);
      sleep(job_queue[i]);
      job_queue[i] = NULL;
    } else {
      printf("Thread %d: Waiting for job\n", i);
      sleep(1);
    }
  }
}

int main() {
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_function, (void*)i);
  }

  for (int i = 0; i < 10; i++) {
    job_queue[i] = rand() % 10 + 1;
  }

  pthread_join(threads[0], NULL);
  return 0;
}
