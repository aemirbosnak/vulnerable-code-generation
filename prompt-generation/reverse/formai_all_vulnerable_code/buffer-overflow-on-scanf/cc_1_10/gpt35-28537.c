//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

#define MAX_FLOOR 10
#define MIN_FLOOR 1

void move_elevator(int from, int to);
void show_floor(int floor);
void show_direction(char direction);
void prompt_for_destination();

int main() {
  int current_floor = 1;
  int destination = MIN_FLOOR;
  
  printf("Welcome to the Elevator Simulator!\n");
  printf("You are currently on floor %d.\n\n", current_floor);
  
  while(1) {
    prompt_for_destination();
    move_elevator(current_floor, destination);
    current_floor = destination;
    printf("You have arrived at floor %d.\n\n", current_floor);
  }
  
  return 0;
}

void move_elevator(int from, int to) {
  if(from < to) {
    show_direction('U');
    for(int f=from+1; f<=to; f++) {
      show_floor(f);
    }
    printf("\n");
  } else {
    show_direction('D');
    for(int f=from-1; f>=to; f--) {
      show_floor(f);
    }
    printf("\n");
  }
}

void show_floor(int floor) {
  printf("%d ", floor);
}

void show_direction(char direction) {
  printf("%c ", direction);
}

void prompt_for_destination() {
  int destination = 0;
  
  while(destination < MIN_FLOOR || destination > MAX_FLOOR) {
    printf("Please enter your destination floor (%d-%d): ", MIN_FLOOR, MAX_FLOOR);
    scanf("%d", &destination);
    if(destination < MIN_FLOOR || destination > MAX_FLOOR) {
      printf("Invalid floor number.\n");
    }
  }
}