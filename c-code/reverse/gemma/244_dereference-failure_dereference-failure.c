#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>

void handleClient(void *arg) {
  char *clientMsg = (char *)arg;
  int len = strlen(clientMsg);
  if (len > 10) {
    printf("Error: message too long\n");
  } else {
    printf("Client message: %s\n", clientMsg);
  }
  pthread_exit(NULL);
}

int main() {
  pthread_t thread;
  pthread_create(&thread, NULL, handleClient, "Hello, world!");
  pthread_join(thread, NULL);
  return 0;
}
