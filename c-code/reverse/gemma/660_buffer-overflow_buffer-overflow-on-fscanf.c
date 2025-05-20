#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>
#include <netdb.h>

#define MAX_HOSTS 100

typedef struct HostPort {
  char hostname[MAX_HOSTS];
  int port;
} HostPort;

void *scan_hosts(void *hp) {
  HostPort *h = (HostPort *)hp;
  char buffer[MAX_HOSTS];
  FILE *fp = fopen("hosts.txt", "r");
  fscanf(fp, "%s", buffer);
  strcpy(h->hostname, buffer);
  h->port = 8080;
  return NULL;
}

int main() {
  pthread_t threads[MAX_HOSTS];
  HostPort hp[MAX_HOSTS];

  for (int i = 0; i < MAX_HOSTS; i++) {
    hp[i].hostname[0] = '\0';
    pthread_create(&threads[i], NULL, scan_hosts, (void *)&hp[i]);
  }

  for (int i = 0; i < MAX_HOSTS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
