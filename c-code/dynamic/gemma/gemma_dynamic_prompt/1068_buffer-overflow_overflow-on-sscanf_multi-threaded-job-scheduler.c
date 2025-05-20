#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>

void* thread_func(void* arg) {
  char buffer[10];
  scanf("%s", buffer);
  return NULL;
}

int main() {
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, thread_func, NULL);

  char exploit_string[10000];
  sprintf(exploit_string, "A string of %d characters", 10000);
  printf("%s", exploit_string);

  pthread_join(thread_id, NULL);
  return 0;
}
