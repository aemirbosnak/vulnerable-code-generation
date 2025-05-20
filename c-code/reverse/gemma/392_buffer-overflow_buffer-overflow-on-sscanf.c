#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>

void *scanner(int port) {
  char buf[1024];
  sprintf(buf, "Scanning port %d...", port);
  printf("%s\n", buf);
  return NULL;
}

int main() {
  pthread_t threads[1024];
  char *arg = "1-1024";
  char *port_range = arg;
  int min_port, max_port;
  sscanf(port_range, "%d-%d", &min_port, &max_port);

  if (min_port > max_port) {
    return 1;
  }

  for (int i = min_port; i <= max_port; i++) {
    pthread_create(&threads[i], NULL, scanner, (void *)i);
  }

  for (int i = 0; i < max_port - min_port + 1; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
