//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: realistic
#include <stdio.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 5

int main() {
  int current_floor = 1, direction = 1; //1 for up, -1 for down
  int num_people = 0, people_on[MAX_PEOPLE];
  int floors[MAX_FLOORS] = {0}; //0 for no one waiting, 1 for someone waiting
  int num_floors;

  printf("Enter number of floors in the building (between 2 and %d): ", MAX_FLOORS);
  scanf("%d", &num_floors);
  if (num_floors < 2 || num_floors > MAX_FLOORS) {
    printf("Invalid number of floors.\n");
    return 1;
  }

  printf("Elevator is now on floor %d and moving %s.\n", current_floor, direction == 1 ? "up" : "down");

  while (1) {
    //Check if anyone on current floor wants to get off
    int num_people_off = 0;
    for (int i = 0; i < num_people; i++) {
      if (people_on[i] == current_floor) {
        printf("Person %d has gotten off the elevator on floor %d.\n", i+1, current_floor);
        people_on[i] = 0;
        num_people_off++;
      }
    }
    num_people -= num_people_off;

    //Check if anyone on current floor wants to get on
    if (floors[current_floor-1] == 1) {
      if (num_people == MAX_PEOPLE) {
        printf("Elevator is full. Person on floor %d cannot get in.\n", current_floor);
      } else {
        printf("Person %d has gotten on the elevator on floor %d.\n", num_people+1, current_floor);
        floors[current_floor-1] = 0;
        people_on[num_people] = current_floor;
        num_people++;
      }
    }

    //Check if elevator needs to change direction
    if (current_floor == 1 || current_floor == num_floors) {
      direction *= -1;
      printf("Elevator has reached the %s and is now moving %s.\n", current_floor == 1 ? "bottom" : "top", direction == 1 ? "up" : "down");
    }

    //Move elevator to next floor
    current_floor += direction;

    //Check if elevator has reached destination floor for any passengers
    int dest = current_floor + direction;
    for (int i = 0; i < num_people; i++) {
      if (people_on[i] == dest) {
        printf("Person %d will be getting off the elevator on floor %d.\n", i+1, dest);
      }
    }

    //Check if all floors are empty and no one is in elevator
    int empty = 1;
    for (int i = 0; i < num_floors; i++) {
      if (floors[i] == 1) {
        empty = 0;
        break;
      }
    }
    if (empty && num_people == 0) {
      printf("All floors are empty and no one is in the elevator. Simulation has ended.\n");
      break;
    }
  }

  return 0;
}