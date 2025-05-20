//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Elevator Simulation

#define NUM_FLOORS 10
#define MAX_CAPACITY 5
#define TIME_INTERVAL 1

typedef struct {
  int floor;
  int direction;
} Request;

typedef struct {
  int current_floor;
  int capacity;
  int num_requests;
  Request* requests;
} Elevator;

Elevator* create_elevator(int floor, int capacity) {
  Elevator* elevator = (Elevator*)malloc(sizeof(Elevator));
  elevator->current_floor = floor;
  elevator->capacity = capacity;
  elevator->num_requests = 0;
  elevator->requests = (Request*)malloc(sizeof(Request) * capacity);
  return elevator;
}

void add_request(Elevator* elevator, int floor, int direction) {
  if (elevator->num_requests < elevator->capacity) {
    elevator->requests[elevator->num_requests].floor = floor;
    elevator->requests[elevator->num_requests].direction = direction;
    elevator->num_requests++;
  }
}

void move_elevator(Elevator* elevator, int time) {
  if (elevator->num_requests > 0) {
    int next_floor = elevator->requests[0].floor;
    int direction = elevator->requests[0].direction;
    if (direction == 1) {
      elevator->current_floor += time;
    } else {
      elevator->current_floor -= time;
    }
    elevator->num_requests--;
    for (int i = 0; i < elevator->num_requests; i++) {
      elevator->requests[i] = elevator->requests[i + 1];
    }
  }
}

void simulate_elevator(Elevator* elevator) {
  srand(time(NULL));
  while (elevator->current_floor != NUM_FLOORS) {
    add_request(elevator, rand() % NUM_FLOORS, rand() % 2 ? 1 : -1);
    move_elevator(elevator, TIME_INTERVAL);
  }
}

int main() {
  Elevator* elevator = create_elevator(0, MAX_CAPACITY);
  simulate_elevator(elevator);
  free(elevator);
  return 0;
}