#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 10
#define MAX_READERS 10

struct Book {
  char title[256];
  int pages;
  int currentPage;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
};

struct Reader {
  pthread_t threadId;
  struct Book* book;
  int pagesRead;
  bool finishedReading;
};

void* readerThread(void* reader) {
  struct Reader* r = (struct Reader*)reader;
  r->finishedReading = false;
  while (!r->finishedReading) {
    pthread_mutex_lock(&r->book->mutex);
    if (r->book->currentPage < r->book->pages) {
      r->pagesRead++;
      r->book->currentPage++;
    } else {
      r->finishedReading = true;
    }
    pthread_mutex_unlock(&r->book->mutex);
    pthread_cond_signal(&r->book->cond);
  }
  return NULL;
}

int main() {
  struct Book books[MAX_BOOKS];
  for (int i = 0; i < MAX_BOOKS; i++) {
    books[i].pages = rand() % 100;
  }

  struct Reader readers[MAX_READERS];
  for (int i = 0; i < MAX_READERS; i++) {
    readers[i].book = &books[rand() % MAX_BOOKS];
  }

  int threadCount = rand() % MAX_READERS + 1;
  pthread_t threads[threadCount];

  for (int i = 0; i < threadCount; i++) {
    pthread_create(&threads[i], NULL, readerThread, &readers[i]);
  }

  for (int i = 0; i < threadCount; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
