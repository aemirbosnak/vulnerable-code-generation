//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The array to be searched
int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
// The number of elements in the array
int size = sizeof(arr) / sizeof(arr[0]);

// The search key
int key;

// The result of the search
int result = -1;

// The mutex to protect the result
pthread_mutex_t result_mutex = PTHREAD_MUTEX_INITIALIZER;

// The thread function
void *search(void *arg) {
  // Get the index of the thread
  int index = *(int *)arg;

  // Search the array for the key
  for (int i = index; i < size; i += 2) {
    if (arr[i] == key) {
      // Lock the mutex
      pthread_mutex_lock(&result_mutex);

      // Update the result
      result = i;

      // Unlock the mutex
      pthread_mutex_unlock(&result_mutex);

      // Break out of the loop
      break;
    }
  }

  // Return NULL
  return NULL;
}

int main() {
  // Get the search key
  printf("Enter the search key: ");
  scanf("%d", &key);

  // Create the threads
  pthread_t threads[size / 2];
  for (int i = 0; i < size / 2; i++) {
    pthread_create(&threads[i], NULL, search, (void *)&i);
  }

  // Join the threads
  for (int i = 0; i < size / 2; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print the result
  if (result == -1) {
    printf("The key was not found.\n");
  } else {
    printf("The key was found at index %d.\n", result);
  }

  // Destroy the mutex
  pthread_mutex_destroy(&result_mutex);

  return 0;
}