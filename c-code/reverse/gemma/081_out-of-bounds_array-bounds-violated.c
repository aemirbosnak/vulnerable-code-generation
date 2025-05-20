#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 10

pthread_t threads[MAX_PAGES];
int pages[MAX_PAGES] = {0};

void* reader(void* page) {
  int my_page = (int)page;
  pages[my_page]++;
  printf("Reader %d is reading page %d\n", my_page, pages[my_page]);
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
