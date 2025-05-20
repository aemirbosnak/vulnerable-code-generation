#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[10];
int job_queue[100];
int job_queue_size = 0;

void* worker(void* arg) {
  int i = (int)arg;
  while (1) {
    if (job_queue_size > 0) {
      int job_id = job_queue[0];
      printf("Thread %d: Processing job %d\n", i, job_id);
      free(job_queue);
      job_queue_size = 0;
    } else {
      sleep(1);
    }
  }
}

int main() {
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, worker, (void*)i);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
