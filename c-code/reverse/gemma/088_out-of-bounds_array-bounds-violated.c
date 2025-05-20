#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

#define NUM_PAGES 10
int current_page[NUM_PAGES] = {0};

pthread_t threads[NUM_PAGES];

void* reader(void* arg) {
  int page_id = (int)arg;
  current_page[page_id] = read_page(page_id);
  return NULL;
}

int main() {
  for (int i = 0; i < NUM_PAGES; i++) {
    pthread_create(&threads[i], NULL, reader, (void*)i);
  }

  for (int i = 0; i < NUM_PAGES; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}

int read_page(int page_id) {
  // Out-of-bounds access vulnerability:
  if (page_id > NUM_PAGES - 1) {
    return -1;
  }

  return current_page[page_id];
}
