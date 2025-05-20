#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
  char buffer[10];
  scanf("%s", buffer);
  printf("Thread: %s, Buffer: %s\n", (int)arg, buffer);
  pthread_exit(NULL);
}

int main() {
  pthread_t thread_id[10];
  char* thread_args[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

  for(int i = 0; i < 10; i++) {
    pthread_create(&thread_id[i], NULL, thread_func, (void*)thread_args[i]);
  }

  for(int i = 0; i < 10; i++) {
    pthread_join(thread_id[i], NULL);
  }

  return 0;
}
