#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

struct Job {
  char **data;
  pthread_t thread;
  int idx;
};

void *job_thread(void *arg) {
  struct Job *job = (struct Job *)arg;
  job->data[job->idx] = malloc(1024);
  return NULL;
}

int main() {
  pthread_t threads[10];
  struct Job jobs[10];

  for (int i = 0; i < 10; i++) {
    jobs[i].idx = i;
    jobs[i].data = malloc(1024);
    pthread_create(&threads[i], NULL, job_thread, &jobs[i]);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
