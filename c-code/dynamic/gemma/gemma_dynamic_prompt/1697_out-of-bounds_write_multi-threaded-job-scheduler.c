#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t threads[100];
int job_queue[100] = {0};
int job_index = 0;

void* worker(void* thread_id) {
  while (1) {
    if (job_index < 0) {
      pthread_exit((int)thread_id);
    }

    int job_id = job_queue[job_index];
    job_queue[job_index] = 0;
    job_index--;

    printf("Thread %ld executing job %d\n", (int)thread_id, job_id);

    sleep(rand() % 5);
  }
}

int main() {
  int num_threads = 10;

  for (int i = 0; i < num_threads; i++) {
    pthread_create(&threads[i], NULL, worker, (void*)i);
  }

  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
