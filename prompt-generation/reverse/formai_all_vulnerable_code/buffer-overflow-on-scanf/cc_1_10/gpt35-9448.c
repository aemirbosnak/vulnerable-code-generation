//FormAI DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

// Declare global variables
int num_threads = 1;
pthread_mutex_t mutex;

// Define the function that each thread will execute
void *thread_function(void *arg) {
   // Lock the mutex
   pthread_mutex_lock(&mutex);

   // Get the thread number from the argument
   int thread_num = *(int*)arg;

   printf("Thread %d is starting.\n", thread_num);

   // Create a filename with the thread number
   char filename[20];
   sprintf(filename, "file%d.txt", thread_num);

   // Open the file for writing
   FILE *file = fopen(filename, "w");
   if (file == NULL) {
      perror("Error opening file.");
      exit(1);
   }

   // Write some data to the file
   fprintf(file, "This is thread %d.\n", thread_num);

   // Close the file
   fclose(file);

   printf("Thread %d is done.\n", thread_num);

   // Unlock the mutex
   pthread_mutex_unlock(&mutex);

   // Exit the thread
   pthread_exit(NULL);
}

int main() {
   // Initialize the mutex
   pthread_mutex_init(&mutex, NULL);

   // Get the number of threads from the user
   printf("How many threads do you want to run? ");
   scanf("%d", &num_threads);

   // Validate user input
   if (num_threads > MAX_THREADS) {
      printf("Maximum number of threads is %d. Using %d threads instead.\n", MAX_THREADS, MAX_THREADS);
      num_threads = MAX_THREADS;
   } else if (num_threads < 1) {
      printf("Minimum number of threads is 1. Using 1 thread instead.\n");
      num_threads = 1;
   }

   // Create an array of pthread_t objects to store the thread IDs
   pthread_t threads[num_threads];

   // Create an array of thread numbers to pass to the thread function
   int thread_nums[num_threads];
   for (int i = 0; i < num_threads; i++) {
      thread_nums[i] = i + 1;
   }

   // Create the threads
   for (int i = 0; i < num_threads; i++) {
      pthread_create(&threads[i], NULL, thread_function, &thread_nums[i]);
   }

   // Wait for the threads to finish
   for (int i = 0; i < num_threads; i++) {
      pthread_join(threads[i], NULL);
   }

   // Destroy the mutex
   pthread_mutex_destroy(&mutex);

   return 0;
}