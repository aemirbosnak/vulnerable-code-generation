//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 5

// Elevator states
#define IDLE 0
#define MOVING 1
#define WAITING 2

// Elevator directions
#define UP 1
#define DOWN -1

// Thread data structure
typedef struct {
  int id;
  int state;
  int direction;
  int current_floor;
  int destination_floor;
} elevator_t;

// Elevator array
elevator_t elevators[NUM_ELEVATORS];

// Floor request queue
int floor_requests[NUM_FLOORS];

// Mutex for floor request queue
pthread_mutex_t floor_requests_mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable for floor request queue
pthread_cond_t floor_requests_cond = PTHREAD_COND_INITIALIZER;

// Elevator thread function
void *elevator_thread(void *arg) {
  elevator_t *elevator = (elevator_t *)arg;

  while (1) {
    // Check if there are any floor requests
    pthread_mutex_lock(&floor_requests_mutex);
    while (floor_requests[elevator->current_floor] == 0) {
      pthread_cond_wait(&floor_requests_cond, &floor_requests_mutex);
    }
    pthread_mutex_unlock(&floor_requests_mutex);

    // Get the floor request
    elevator->destination_floor = floor_requests[elevator->current_floor];
    floor_requests[elevator->current_floor] = 0;

    // Set the elevator state to MOVING
    elevator->state = MOVING;

    // Move the elevator to the destination floor
    while (elevator->current_floor != elevator->destination_floor) {
      if (elevator->current_floor < elevator->destination_floor) {
        elevator->current_floor++;
      } else {
        elevator->current_floor--;
      }
      sleep(1);
    }

    // Set the elevator state to WAITING
    elevator->state = WAITING;

    // Open the elevator doors
    sleep(1);

    // Close the elevator doors
    sleep(1);

    // Set the elevator state to IDLE
    elevator->state = IDLE;
  }

  return NULL;
}

// Main function
int main() {
  // Initialize the elevators
  for (int i = 0; i < NUM_ELEVATORS; i++) {
    elevators[i].id = i;
    elevators[i].state = IDLE;
    elevators[i].direction = UP;
    elevators[i].current_floor = 0;
    elevators[i].destination_floor = 0;

    // Create the elevator thread
    pthread_t tid;
    pthread_create(&tid, NULL, elevator_thread, &elevators[i]);
  }

  // Main loop
  while (1) {
    // Get the floor request
    int floor_request;
    printf("Enter the floor request (0-9): ");
    scanf("%d", &floor_request);

    // Add the floor request to the queue
    pthread_mutex_lock(&floor_requests_mutex);
    floor_requests[floor_request] = 1;
    pthread_cond_signal(&floor_requests_cond);
    pthread_mutex_unlock(&floor_requests_mutex);
  }

  return 0;
}