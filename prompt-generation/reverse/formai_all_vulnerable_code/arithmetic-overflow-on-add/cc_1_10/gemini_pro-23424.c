//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the minimum and maximum password lengths
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

// Define the character set for the password
#define CHARSET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()"

// Define the number of threads to use
#define NUM_THREADS 4

// Define the mutex to protect the password buffer
pthread_mutex_t password_mutex = PTHREAD_MUTEX_INITIALIZER;

// Define the condition variable to signal when a password is generated
pthread_cond_t password_cond = PTHREAD_COND_INITIALIZER;

// Define the password buffer
char password[MAX_PASSWORD_LENGTH + 1];

// Define the thread function
void *generate_password(void *args) {
  // Get the thread number
  int thread_num = *(int *)args;

  // Set the random seed
  srand(time(NULL) + thread_num);

  // Generate a random password
  for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
    // Get a random character from the character set
    int index = rand() % strlen(CHARSET);
    char character = CHARSET[index];

    // Lock the password buffer
    pthread_mutex_lock(&password_mutex);

    // Add the character to the password buffer
    password[i] = character;

    // Unlock the password buffer
    pthread_mutex_unlock(&password_mutex);
  }

  // Signal that a password has been generated
  pthread_cond_signal(&password_cond);

  // Return NULL
  return NULL;
}

// Define the main function
int main() {
  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, generate_password, &i);
  }

  // Wait for a password to be generated
  pthread_cond_wait(&password_cond, &password_mutex);

  // Print the password
  printf("Password: %s\n", password);

  // Destroy the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the mutex and condition variable
  pthread_mutex_destroy(&password_mutex);
  pthread_cond_destroy(&password_cond);

  // Return 0
  return 0;
}