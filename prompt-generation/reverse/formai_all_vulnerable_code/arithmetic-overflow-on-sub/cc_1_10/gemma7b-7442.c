//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PESS_PER_FLOOR 5

typedef struct Passenger {
  int floor_destination;
  struct Passenger* next;
} Passenger;

Passenger* create_passenger(int floor_destination) {
  Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
  new_passenger->floor_destination = floor_destination;
  new_passenger->next = NULL;
  return new_passenger;
}

void add_passenger(Passenger* head, int floor_destination) {
  Passenger* new_passenger = create_passenger(floor_destination);
  if (head == NULL) {
    head = new_passenger;
  } else {
    new_passenger->next = head;
    head = new_passenger;
  }
}

void simulate_elevator(Passenger* head) {
  int current_floor = 1;
  time_t start_time = time(NULL);
  while (head) {
    if (current_floor == head->floor_destination) {
      printf("Passenger: %d reached floor %d.\n", head->floor_destination);
      free(head);
      head = head->next;
    } else if (current_floor < head->floor_destination) {
      current_floor++;
    } else if (current_floor > head->floor_destination) {
      current_floor--;
    }
  }
  time_t end_time = time(NULL);
  printf("Time taken: %ld seconds.\n", end_time - start_time);
}

int main() {
  Passenger* head = NULL;
  add_passenger(head, 3);
  add_passenger(head, 5);
  add_passenger(head, 2);
  add_passenger(head, 4);
  simulate_elevator(head);

  return 0;
}