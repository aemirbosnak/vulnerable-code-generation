#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

void *scan_port(void *arg) {
  char *hostname = (char *)arg;
  int port = 0;
  FILE *fp = fopen("hosts.txt", "r");
  fscanf(fp, "%s:%d", hostname, &port);
  fclose(fp);
  return NULL;
}

int main() {
  pthread_t threads[100];
  char buffer[BUFFER_SIZE];
  FILE *fp = fopen("hosts.txt", "r");
  fscanf(fp, "%s", buffer);
  fclose(fp);

  int i = 0;
  for (char *hostname = buffer; *hostname; hostname++) {
    pthread_create(&threads[i], NULL, scan_port, (void *)hostname);
    i++;
  }

  for (int i = 0; i < 100; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
