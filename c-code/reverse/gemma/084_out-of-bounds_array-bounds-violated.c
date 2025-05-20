#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 10

struct Book {
  char title[256];
  char author[256];
  int pages;
};

void* readerThread(void* bookIndex) {
  int index = (int)bookIndex;
  struct Book books[MAX_BOOKS];

  // Accessing memory beyond allocated array bounds
  books[index].pages = 100;

  printf("Book %d: %s by %s, %d pages\n", index, books[index].title, books[index].author, books[index].pages);

  pthread_exit(NULL);
}

int main() {
  pthread_t threads[MAX_BOOKS];
  struct Book books[MAX_BOOKS];

  for (int i = 0; i < MAX_BOOKS; i++) {
    books[i].title[0] = '\0';
    books[i].author[0] = '\0';
    books[i].pages = 0;
  }

  for (int i = 0; i < MAX_BOOKS; i++) {
    pthread_create(&threads[i], NULL, readerThread, (void*)i);
  }

  for (int i = 0; i < MAX_BOOKS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
