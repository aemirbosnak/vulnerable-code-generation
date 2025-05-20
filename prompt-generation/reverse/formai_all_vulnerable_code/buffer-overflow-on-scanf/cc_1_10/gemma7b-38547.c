//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_FLOORS 5
#define MAX_PASSENGERS 10

typedef struct Passenger {
  char name[20];
  int floor;
  int destination;
} Passenger;

void simulate_elevator(Passenger *passengers) {
  int current_floor = 0;
  int destination_floor;
  int num_passengers = 0;

  while (num_passengers < MAX_PASSENGERS) {
    printf("Enter your name: ");
    scanf("%s", passengers[num_passengers].name);

    printf("Enter your current floor: ");
    scanf("%d", &passengers[num_passengers].floor);

    printf("Enter your destination floor: ");
    scanf("%d", &passengers[num_passengers].destination);

    num_passengers++;
  }

  for (int i = 0; i < num_passengers; i++) {
    destination_floor = passengers[i].destination;

    if (current_floor != destination_floor) {
      current_floor = destination_floor;
      printf("The elevator is moving to floor %d.\n", current_floor);
    } else {
      printf("The elevator has reached floor %d.\n", current_floor);
    }
  }
}

int main() {
  Passenger passengers[MAX_PASSENGERS];

  simulate_elevator(passengers);

  return 0;
}