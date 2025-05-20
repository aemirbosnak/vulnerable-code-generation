#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

#define MAX_PAGES 10

int pages[MAX_PAGES] = {0};

pthread_t threads[MAX_PAGES];

void* reader(void* arg) {
  int page_index = (int)arg;
  pages[page_index]++;
  sleep(rand() % 5);
  pages[page_index]--;
  pthread_exit(NULL);
}

int main() {
  for (int i = 0; i < MAX_PAGES; i++) {
    pthread_create(&threads[i], NULL, reader, (void*)i);
  }

  for (int i = 0; i < MAX_PAGES; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
