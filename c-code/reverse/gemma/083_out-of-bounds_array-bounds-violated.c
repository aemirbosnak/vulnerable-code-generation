#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 10

pthread_t threads[MAX_PAGES];
int current_page[MAX_PAGES] = {0};

void *reader(void *arg) {
  int page = (int)arg;
  current_page[page]++;
  printf("User %ld is reading page %d\n", pthread_self(), current_page[page]);
  return NULL;
}

int main() {
  for (int i = 0; i < MAX_PAGES; i++) {
    pthread_create(&threads[i], NULL, reader, (void *)i);
  }

  for (int i = 0; i < MAX_PAGES; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
