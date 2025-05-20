#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>

void* scanner(void* arg) {
  FILE* file = fopen("hosts.txt", "r");
  char buffer[1024];
  fscanf(file, "%s", buffer);
  fclose(file);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[100];
  for (int i = 0; i < 100; i++) {
    pthread_create(&threads[i], NULL, scanner, NULL);
  }
  for (int i = 0; i < 100; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
