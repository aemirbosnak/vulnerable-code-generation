//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ITEMS 100

// Global variables
int thread_count;
int item_count;
int items[MAX_ITEMS];
pthread_mutex_t mutex;

// Function prototypes
void *Producer(void *rank);
void *Consumer(void *rank);

int main(int argc, char* argv[]) {
  long  thread_id;
  pthread_t* thread_handles;

  // Get user input for thread count and items count
  printf("Enter the number of threads (max 10): ");
  scanf("%d", &thread_count);

  printf("Enter the number of items to produce and consume (max 100): ");
  scanf("%d", &item_count);

  if (thread_count > MAX_THREADS || item_count > MAX_ITEMS) {
    printf("Error: Invalid input, please stay within max limits.\n");
    exit(1);
  }

  // Initialize mutex
  pthread_mutex_init(&mutex, NULL);

  // Allocate memory for thread handle array
  thread_handles = (pthread_t*) malloc (thread_count*sizeof(pthread_t));

  // Create the Producer threads
  for (thread_id = 0; thread_id < thread_count; thread_id++)
    pthread_create(&thread_handles[thread_id], NULL,
        Producer, (void*) thread_id);

  // Create the Consumer threads
  for (thread_id = 0; thread_id < thread_count; thread_id++)
    pthread_create(&thread_handles[thread_id], NULL,
        Consumer, (void*) thread_id);

  // Wait for threads to complete
  for (thread_id = 0; thread_id < thread_count; thread_id++)
    pthread_join(thread_handles[thread_id], NULL);

  // Free memory
  free(thread_handles);
  pthread_mutex_destroy(&mutex);

  return 0;
}


void *Producer(void *rank) {
  long my_rank = (long) rank;
  int generated_items;

  // Generate items
  for (int i = 0; i < item_count; i++) {
    generated_items = rand() % 50;

    // Acquire mutex before modifying shared data
    pthread_mutex_lock(&mutex);

    // Critical section
    items[i] = generated_items;
    printf("Producer %ld generated item %d: %d\n", my_rank, i+1, generated_items);

    // Release mutex after modifying shared data
    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}

void *Consumer(void *rank) {
  long my_rank = (long) rank;
  int consumed_items;

  // Consume items
  for (int i = 0; i < item_count; i++) {
    // Acquire mutex before accessing shared data
    pthread_mutex_lock(&mutex);

    // Critical section
    consumed_items = items[i];
    printf("Consumer %ld consumed item %d: %d\n", my_rank, i+1, consumed_items);

    // Release mutex after accessing shared data
    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}