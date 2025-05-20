//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdint.h>

struct match {
  uint64_t matches;
  uint64_t scans;
};

static struct match matches[256];

static void *scan(void *arg) {
  uint64_t *count = (uint64_t *) arg;
  uint64_t i;

  struct timeval tv;
  gettimeofday(&tv, NULL);
  srand(tv.tv_sec + tv.tv_usec);

  for (i = *count; i < *count + 1000000; i++) {
    matches[rand() % 256].scans++;
  }

  *count += 1000000;

  return NULL;
}

int main(int argc, char **argv) {
  pthread_t threads[10];
  uint64_t counts[10];
  int i, j;
  uint64_t matches_count, scans_count;

  for (i = 0; i < 10; i++) {
    counts[i] = 1000000 * i;
    pthread_create(&threads[i], NULL, scan, &counts[i]);
  }

  for (i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  matches_count = 0;
  scans_count   = 0;
  for (i = 0; i < 256; i++) {
    matches_count += matches[i].matches;
    scans_count   += matches[i].scans;
  }

  printf("Matches: %lu\n", matches_count);
  printf("Scans:   %lu\n", scans_count);

  return 0;
}