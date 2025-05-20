//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
  int start;
  int end;
  int count;
} thread_args;

void* prime_generator(void* args) {
  thread_args* arg = (thread_args*) args;

  for (int i = arg->start; i <= arg->end; i++) {
    int is_prime = 1;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }

    if (is_prime) {
      arg->count++;
    }
  }

  pthread_exit(NULL);
}

int main() {
  int num_threads, range_start, range_end;
  printf("Enter the number of threads: ");
  scanf("%d", &num_threads);
  printf("Enter the range of numbers (start, end): ");
  scanf("%d %d", &range_start, &range_end);

  if (num_threads > MAX_THREADS || num_threads <= 0) {
    printf("Invalid number of threads\n");
    return 1;
  }

  if (range_start > range_end) {
    printf("Invalid range of numbers\n");
    return 1;
  }

  int range_size = range_end - range_start + 1;
  int range_per_thread = range_size / num_threads;

  pthread_t threads[num_threads];
  thread_args args[num_threads];

  for (int i = 0; i < num_threads; i++) {
    args[i].start = range_start + (i * range_per_thread);
    args[i].end = range_start + ((i + 1) * range_per_thread) - 1;
    args[i].count = 0;
  }

  for (int i = 0; i < num_threads; i++) {
    pthread_create(&threads[i], NULL, prime_generator, (void*) &args[i]);
  }

  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  int total_primes = 0;
  for (int i = 0; i < num_threads; i++) {
    total_primes += args[i].count;
  }

  printf("Total prime numbers found: %d\n", total_primes);

  return 0;
}