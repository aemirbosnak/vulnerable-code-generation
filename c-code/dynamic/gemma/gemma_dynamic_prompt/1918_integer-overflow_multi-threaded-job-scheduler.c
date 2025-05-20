#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t threads[1000];
int job_queue[1000] = {0};
int job_queue_size = 0;

void* thread_func(void* arg) {
  int i = (int)arg;
  while (1) {
    if (job_queue_size > 0) {
      int job_id = job_queue[0];
      job_queue[0] = 0;
      job_queue_size--;

      int job_delay = rand() % 1000;
      sleep(job_delay);

      printf("Thread %d completed job %d\n", i, job_id);
    } else {
      sleep(1);
    }
  }
}

int main() {
  pthread_t thread_id;
  for (int i = 0; i < 1000; i++) {
    pthread_create(&thread_id, NULL, thread_func, (void*)i);
  }

  for (int i = 0; i < 1000; i++) {
    pthread_join(thread_id, NULL);
  }

  return 0;
}
