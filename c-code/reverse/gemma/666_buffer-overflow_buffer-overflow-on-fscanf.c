#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>

void *thread_func(void *arg) {
  FILE *fp = fopen("hosts.txt", "r");
  char buffer[1024];
  fscanf(fp, "%s", buffer);
  fclose(fp);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[100];
  for (int i = 0; i < 100; i++) {
    pthread_create(&threads[i], NULL, thread_func, NULL);
  }
  for (int i = 0; i < 100; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
