//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads
#define NUM_THREADS 4

// Define the number of dice rolls per thread
#define ROLLS_PER_THREAD 1000000

// Define the mutex to protect the shared variable
pthread_mutex_t mutex;

// Define the shared variable to store the total number of rolls
int total_rolls = 0;

// Define the thread function
void *roll_dice(void *arg) {
  // Get the thread ID
  int tid = (int)arg;

  // Initialize the random number generator
  srand(time(NULL) + tid);

  // Roll the dice ROLLS_PER_THREAD times
  for (int i = 0; i < ROLLS_PER_THREAD; i++) {
    // Get the roll result
    int roll = rand() % 6 + 1;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Increment the total number of rolls
    total_rolls++;

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);
  }

  // Return NULL to indicate success
  return NULL;
}

// Define the main function
int main() {
  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, roll_dice, (void *)i);
  }

  // Join the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print the total number of rolls
  printf("Total rolls: %d\n", total_rolls);

  // Return 0 to indicate success
  return 0;
}