//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

#define NUM_THREADS 4
#define MAX_FORTUNE_LENGTH 1024

typedef struct {
  int tid;
  char fortune[MAX_FORTUNE_LENGTH];
} fortune_t;

pthread_mutex_t mutex;
pthread_cond_t cond;

int fortunes_ready = 0;

void *fortune_teller(void *arg) {
  fortune_t *fortune = (fortune_t *)arg;
  
  // Seed the random number generator with the thread ID
  srand(time(NULL) + fortune->tid);

  // Generate a random fortune
  int length = rand() % (MAX_FORTUNE_LENGTH - 1) + 1;
  for (int i = 0; i < length; i++) {
    fortune->fortune[i] = (char)('a' + rand() % ('z' - 'a' + 1));
  }
  fortune->fortune[length] = '\0';

  // Lock the mutex and signal that a fortune is ready
  pthread_mutex_lock(&mutex);
  fortunes_ready++;
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main() {
  // Initialize the mutex and condition variable
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);

  // Create the fortune teller threads
  pthread_t threads[NUM_THREADS];
  fortune_t fortunes[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    fortunes[i].tid = i;
    pthread_create(&threads[i], NULL, fortune_teller, &fortunes[i]);
  }

  // Wait for all the fortunes to be ready
  pthread_mutex_lock(&mutex);
  while (fortunes_ready < NUM_THREADS) {
    pthread_cond_wait(&cond, &mutex);
  }
  pthread_mutex_unlock(&mutex);

  // Print the fortunes
  for (int i = 0; i < NUM_THREADS; i++) {
    printf("Fortune %d: %s\n", i + 1, fortunes[i].fortune);
  }

  // Join the fortune teller threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the mutex and condition variable
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);

  return 0;
}