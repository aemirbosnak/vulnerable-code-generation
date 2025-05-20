#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

void *scan_port(int port) {
  int sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd == -1) {
    perror("Error opening socket");
    exit(1);
  }
  close(sockfd);
  return NULL;
}

int main(int argc, char *argv[]) {
  int min_port, max_port;
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <min_port> <max_port>\n", argv[0]);
    exit(1);
  }
  sscanf(argv[1], "%d", &min_port);
  sscanf(argv[2], "%d", &max_port);

  pthread_t threads[max_port - min_port + 1];
  for (int i = min_port; i <= max_port; i++) {
    pthread_create(&threads[i - min_port], NULL, scan_port, (void *)i);
  }
  for (int i = 0; i < max_port - min_port + 1; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
