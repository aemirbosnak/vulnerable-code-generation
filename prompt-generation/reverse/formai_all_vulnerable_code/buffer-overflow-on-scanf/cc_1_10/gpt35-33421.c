//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 2
#define MAX_TEMP 100

pthread_mutex_t temperature_mutex;

int current_temp = 50;
int is_running = 1;

void *temperature_monitor(void *threadid) {
  long tid = (long)threadid;
  while(is_running) {
    // Simulate temperature changes
    int temperature_change = rand() % 5;
    int direction = rand() % 2;

    if(direction == 0) {
      current_temp -= temperature_change;
    } else {
      current_temp += temperature_change;
    }

    // Check if temperature is over max limit
    if(current_temp > MAX_TEMP) {
      printf("ALERT: Temperature is too high! Current temp: %d\n", current_temp);
    }

    pthread_mutex_lock(&temperature_mutex);
    printf("Thread[%ld]: Current temperature is %d\n", tid, current_temp);
    pthread_mutex_unlock(&temperature_mutex);

    sleep(1);
  }

  printf("Thread[%ld]: Stopping temperature monitor.\n", tid);
  pthread_exit(NULL);
}

void *user_input(void *threadid) {
  long tid = (long)threadid;

  while(is_running) {
    // Get user input
    char input;
    scanf(" %c", &input);

    // If user enters 'q', stop the program
    if(input == 'q') {
      is_running = 0;
      break;
    }
  }

  printf("Thread[%ld]: Stopping user input.\n", tid);
  pthread_exit(NULL);
}

int main() {
  printf("Starting temperature monitor...\n");

  pthread_t threads[NUM_THREADS];
  int rc;

  rc = pthread_mutex_init(&temperature_mutex, NULL);
  if(rc != 0) {
    printf("ERROR: Mutex initialization failed, exiting program.\n");
    exit(1);
  }

  long t;
  for(t = 0; t < NUM_THREADS; t++) {
    if(t == 0) {
      rc = pthread_create(&threads[t], NULL, temperature_monitor, (void *)t);
    } else {
      rc = pthread_create(&threads[t], NULL, user_input, (void *)t);
    }

    if(rc) {
      printf("ERROR: Return code from pthread_create() is %d, exiting program.\n", rc);
      exit(1);
    }
  }

  for(t = 0; t < NUM_THREADS; t++) {
    rc = pthread_join(threads[t], NULL);

    if(rc) {
      printf("ERROR: Return code from pthread_join() is %d, exiting program.\n", rc);
      exit(1);
    }
  }

  pthread_mutex_destroy(&temperature_mutex);

  printf("Exited program successfully.\n");
  return 0;
}