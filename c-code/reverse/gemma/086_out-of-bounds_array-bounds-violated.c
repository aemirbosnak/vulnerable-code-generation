#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>

#define MAX_BOOKS 100

struct Book {
  char title[256];
  char author[256];
  int pages;
};

struct Book books[MAX_BOOKS];

pthread_t threads[MAX_BOOKS];

void* readerThread(void* bookIndex) {
  int index = (int)bookIndex;
  books[index].pages++;
  return NULL;
}

int main() {
  int numThreads = 10;
  pthread_t threads[numThreads];

  for (int i = 0; i < numThreads; i++) {
    pthread_create(&threads[i], NULL, readerThread, (void*)i);
  }

  for (int i = 0; i < numThreads; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
