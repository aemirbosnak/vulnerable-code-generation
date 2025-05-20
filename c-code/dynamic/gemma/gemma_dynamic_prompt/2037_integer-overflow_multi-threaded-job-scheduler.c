#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[100];
int job_queue[100] = {0};
int job_count = 0;

void *thread_func(void *arg) {
  while (1) {
    if (job_count > 0) {
      int job_index = rand() % job_count;
      printf("Thread: Starting job %d\n", job_index);
      sleep(rand() % 5);
      printf("Thread: Finishing job %d\n", job_index);
      job_queue[job_index] = 0;
    } else {
      sleep(1);
    }
  }
}

int main() {
  pthread_t thread_id;
  for (int i = 0; i < 10; i++) {
    pthread_create(&thread_id, NULL, thread_func, NULL);
  }

  while (1) {
    printf("Enter job number: ");
    int job_num = atoi(stdin);
    if (job_num > 0) {
      job_queue[job_count] = job_num;
      job_count++;
    } else {
      break;
    }
  }

  for (int i = 0; i < job_count; i++) {
    printf("Job %d is waiting...\n", job_queue[i]);
  }

  return 0;
}
