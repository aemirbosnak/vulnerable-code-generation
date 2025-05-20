#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_Jobs 10

typedef struct Job {
  char *name;
  int priority;
  pthread_t thread;
} Job;

void *job_thread(void *job) {
  Job *j = (Job *)job;
  printf("Job name: %s, priority: %d\n", j->name, j->priority);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[MAX_Jobs];
  Job jobs[MAX_Jobs];

  for (int i = 0; i < MAX_Jobs; i++) {
    jobs[i].name = malloc(20);
    jobs[i].priority = i + 1;
    pthread_create(&threads[i], NULL, job_thread, &jobs[i]);
  }

  for (int i = 0; i < MAX_Jobs; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
