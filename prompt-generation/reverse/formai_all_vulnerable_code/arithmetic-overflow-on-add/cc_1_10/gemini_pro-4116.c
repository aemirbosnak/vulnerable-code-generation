//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 4
#define MAX_LOOT 1000

struct scavenger_info {
  pthread_t tid;
  int loot;
};

void *scavenge(void *arg) {
  struct scavenger_info *info = (struct scavenger_info *)arg;
  int i;

  // Scavenge for loot
  for (i = 0; i < 10; i++) {
    info->loot += rand() % 100;
    sleep(1);
  }

  return NULL;
}

int main() {
  srand(time(NULL));

  struct scavenger_info scavengers[NUM_THREADS];
  int total_loot = 0;
  int i;

  // Create scavenger threads
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_create(&scavengers[i].tid, NULL, scavenge, &scavengers[i]);
  }

  // Join scavenger threads
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(scavengers[i].tid, NULL);
    total_loot += scavengers[i].loot;
  }

  // Report total loot
  printf("Total loot scavenged: %d\n", total_loot);

  return 0;
}