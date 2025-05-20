//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_FLOORS 5
#define NUM_ELEVATORS 2

typedef struct {
  int floor;
  int direction;
  sem_t mutex;
  sem_t empty;
  sem_t full;
} Elevator;

Elevator elevators[NUM_ELEVATORS];

void *elevator_thread(void *arg) {
  Elevator *elevator = (Elevator *)arg;

  while (1) {
    sem_wait(&elevator->empty);
    sem_wait(&elevator->mutex);

    // Pick up passengers
    // ...

    sem_post(&elevator->mutex);
    sem_post(&elevator->full);

    // Move elevator
    // ...

    sem_wait(&elevator->mutex);

    // Drop off passengers
    // ...

    sem_post(&elevator->mutex);
    sem_post(&elevator->empty);
  }

  return NULL;
}

void init_elevators() {
  for (int i = 0; i < NUM_ELEVATORS; i++) {
    elevators[i].floor = 0;
    elevators[i].direction = 1;
    sem_init(&elevators[i].mutex, 0, 1);
    sem_init(&elevators[i].empty, 0, 1);
    sem_init(&elevators[i].full, 0, 0);
  }
}

void request_elevator(int floor, int direction) {
  Elevator *elevator = NULL;

  // Find an elevator that is moving in the desired direction and is closest to the requested floor
  for (int i = 0; i < NUM_ELEVATORS; i++) {
    if (elevators[i].direction == direction && elevators[i].floor <= floor) {
      if (elevator == NULL || elevators[i].floor > elevator->floor) {
        elevator = &elevators[i];
      }
    }
  }

  if (elevator == NULL) {
    // No elevator is moving in the desired direction, so find an idle elevator
    for (int i = 0; i < NUM_ELEVATORS; i++) {
      if (elevators[i].direction == 0) {
        elevator = &elevators[i];
        break;
      }
    }
  }

  if (elevator == NULL) {
    // No elevator is available, so wait for one to become available
    sem_wait(&elevators[0].empty);
    elevator = &elevators[0];
  }

  sem_wait(&elevator->mutex);

  // Add the passenger to the elevator's queue
  // ...

  sem_post(&elevator->mutex);
  sem_post(&elevator->full);
}

int main() {
  init_elevators();

  // Create elevator threads
  pthread_t elevator_threads[NUM_ELEVATORS];
  for (int i = 0; i < NUM_ELEVATORS; i++) {
    pthread_create(&elevator_threads[i], NULL, elevator_thread, &elevators[i]);
  }

  // Main loop
  while (1) {
    // Get passenger input
    int floor, direction;
    printf("Enter floor and direction (e.g. 2 1): ");
    scanf("%d %d", &floor, &direction);

    // Request elevator
    request_elevator(floor, direction);
  }

  return 0;
}