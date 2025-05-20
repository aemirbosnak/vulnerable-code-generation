#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>

void *thread_func(void *arg) {
  // Thread function to demonstrate null pointer dereference
  int *ptr = (int *)arg;
  printf("Thread ID: %u, Value: %d\n", (unsigned int)pthread_self(), *ptr);
  (*ptr) = 10;
  return NULL;
}

int main() {
  // Declare an integer pointer and initialize it to NULL
  int *ptr = NULL;

  // Create a thread and start it
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, thread_func, (void *)ptr);

  // Join the thread to complete
  pthread_join(thread_id, NULL);

  // Attempt to dereference the null pointer
  *ptr = 5;

  return 0;
}
