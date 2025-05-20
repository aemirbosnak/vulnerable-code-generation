#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *scan_port(int port) {
  // Malformed input vulnerability: buffer overflow
  char buffer[10];
  sprintf(buffer, "Port %d:", port);
  printf("%s\n", buffer);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: ./program port_range\n");
    return 1;
  }

  char *port_range = argv[1];
  int min_port, max_port;

  // Parse port range
  sscanf(port_range, "%d-%d", &min_port, &max_port);

  // Create and start threads
  pthread_t threads[max_port - min_port + 1];
  for (int i = min_port; i <= max_port; i++) {
    pthread_create(&threads[i], NULL, scan_port, (void *)i);
  }

  // Join threads
  for (int i = min_port; i <= max_port; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
