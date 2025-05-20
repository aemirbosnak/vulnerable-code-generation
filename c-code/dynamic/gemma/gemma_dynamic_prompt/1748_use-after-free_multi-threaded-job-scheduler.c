#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t threads[10];
struct Job {
  char *name;
  int seconds;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
};

void *thread_func(void *arg) {
  struct Job *job = (struct Job *)arg;
  pthread_mutex_lock(&job->mutex);
  printf("%s is running\n", job->name);
  sleep(job->seconds);
  pthread_mutex_unlock(&job->mutex);
  pthread_cond_signal(&job->cond);
  return NULL;
}

int main() {
  struct Job jobs[10];
  for (int i = 0; i < 10; i++) {
    jobs[i].name = malloc(20);
    sprintf(jobs[i].name, "Job %d", i);
    jobs[i].seconds = rand() % 5 + 1;
    pthread_mutex_init(&jobs[i].mutex, NULL);
    pthread_cond_init(&jobs[i].cond, NULL);
  }

  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, &jobs[i]);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  for (int i = 0; i < 10; i++) {
    free(jobs[i].name);
    pthread_mutex_destroy(&jobs[i].mutex);
    pthread_cond_destroy(&jobs[i].cond);
  }

  return 0;
}
