//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>

#define NUM_TERMINALS 3
#define MAX_CAPACITY 100
#define MAX_BAGGAGE_SIZE 50

int globalBaggageCount = 0;
pthread_mutex_t baggageMutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
  int terminalId;
  int currentBaggageCount;
  int maxCapacity;
} Terminal;

typedef struct {
  int terminalId;
  int baggageSize;
} Baggage;

void* generateBaggage(void* arg) {
  Baggage* baggage = (Baggage*) arg;

  while(true) {
    pthread_mutex_lock(&baggageMutex);

    if(globalBaggageCount < MAX_CAPACITY) {
      globalBaggageCount += baggage->baggageSize;
      printf("Baggage generated at Terminal %d: %d\n", baggage->terminalId, baggage->baggageSize);
      printf("Total Baggage Count: %d\n\n", globalBaggageCount);

      pthread_mutex_unlock(&baggageMutex);
      sleep(rand() % 5 + 1);
    } else {
      pthread_mutex_unlock(&baggageMutex);
      sleep(rand() % 3 + 1);
    }
  }

  return NULL;
}

void* handleBaggage(void* arg) {
  Terminal* terminal = (Terminal*) arg;

  while(true) {
    pthread_mutex_lock(&baggageMutex);

    if(globalBaggageCount > 0 && terminal->currentBaggageCount < terminal->maxCapacity) {
      int baggageSize = rand() % MAX_BAGGAGE_SIZE + 1;

      if(globalBaggageCount >= baggageSize) {
        globalBaggageCount -= baggageSize;
        terminal->currentBaggageCount += baggageSize;
        printf("Baggage handled at Terminal %d: %d\n", terminal->terminalId, baggageSize);
        printf("Terminal %d Baggage Count: %d\n", terminal->terminalId, terminal->currentBaggageCount);
        printf("Total Baggage Count: %d\n\n", globalBaggageCount);
      }
      pthread_mutex_unlock(&baggageMutex);
      sleep(rand() % 5 + 1);
    } else {
      pthread_mutex_unlock(&baggageMutex);
      sleep(rand() % 3 + 1);
    }
  }

  return NULL;
}

int main() {
  srand(time(NULL));

  Terminal terminals[NUM_TERMINALS];
  pthread_t tids[NUM_TERMINALS + 1];
  Baggage baggage;

  for(int i = 0; i < NUM_TERMINALS; i++) {
    terminals[i].terminalId = i + 1;
    terminals[i].currentBaggageCount = 0;
    terminals[i].maxCapacity = rand() % 20 + 1;

    pthread_create(&tids[i], NULL, handleBaggage, (void*) &terminals[i]);
    printf("Terminal %d capacity: %d\n", terminals[i].terminalId, terminals[i].maxCapacity);
  }

  pthread_create(&tids[NUM_TERMINALS], NULL, generateBaggage, (void*) &baggage);
  pthread_join(tids[NUM_TERMINALS], NULL);

  for(int i = 0; i < NUM_TERMINALS; i++) {
    pthread_join(tids[i], NULL);
  }

  return 0;
}