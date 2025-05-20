//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>

#define MAX_FLOORS 20 // maximum number of floors in the building
#define MIN_FLOORS 5 // minimum number of floors required in the building
#define MAX_ELEVATORS 5 // maximum number of elevators in the building
#define MIN_ELEVATORS 1 // minimum number of elevators required in the building

// Structure for elevator
typedef struct {
  int floor; // current floor of elevator
  int direction; // 0 for going down, 1 for going up, -1 for not moving
  int stops[MAX_FLOORS]; // array to store the floors where the elevator will stop
  int num_stops; // number of stops
} Elevator;

// Function to initialize an elevator
void init_elevator(Elevator* e) {
  e->floor = 1;
  e->direction = -1;
  for(int i = 0; i < MAX_FLOORS; i++) {
    e->stops[i] = 0;
  }
  e->num_stops = 0;
}

// Function to add a stop to an elevator
void add_stop(Elevator* e, int floor) {
  e->stops[e->num_stops] = floor;
  e->num_stops++;
}

// Function to move an elevator to the next floor in the direction it is heading
void move_elevator(Elevator* e) {
  if(e->direction == 1) { // going up
    e->floor++;
  }
  else if(e->direction == 0) { // going down
    e->floor--;
  }
  // if elevator is not moving, do nothing
}

int main() {
  int num_floors, num_elevators;
  
  // get number of floors from user
  printf("Enter the number of floors (minimum %d, maximum %d) in the building: ", MIN_FLOORS, MAX_FLOORS);
  scanf("%d", &num_floors);
  while(num_floors < MIN_FLOORS || num_floors > MAX_FLOORS) {
    printf("Invalid input. Enter the number of floors (minimum %d, maximum %d) in the building: ", MIN_FLOORS, MAX_FLOORS);
    scanf("%d", &num_floors);
  }
  
  // get number of elevators from user
  printf("Enter the number of elevators (minimum %d, maximum %d) in the building: ", MIN_ELEVATORS, MAX_ELEVATORS);
  scanf("%d", &num_elevators);
  while(num_elevators < MIN_ELEVATORS || num_elevators > MAX_ELEVATORS) {
    printf("Invalid input. Enter the number of elevators (minimum %d, maximum %d) in the building: ", MIN_ELEVATORS, MAX_ELEVATORS);
    scanf("%d", &num_elevators);
  }
  
  // initialize the elevators
  Elevator elevators[MAX_ELEVATORS];
  for(int i = 0; i < num_elevators; i++) {
    init_elevator(&elevators[i]);
  }
  
  int num_people;
  printf("Enter the number of people in the building: ");
  scanf("%d", &num_people);
  
  // simulate elevator usage by people
  int current_floor, destination_floor;
  for(int i = 0; i < num_people; i++) {
    printf("Person %d: ", i+1);
    printf("Enter the current floor (between 1 and %d): ", num_floors);
    scanf("%d", &current_floor);
    while(current_floor < 1 || current_floor > num_floors) {
      printf("Invalid input. Enter the current floor (between 1 and %d): ", num_floors);
      scanf("%d", &current_floor);
    }
    
    printf("Enter the destination floor (between 1 and %d): ", num_floors);
    scanf("%d", &destination_floor);
    while(destination_floor < 1 || destination_floor > num_floors) {
      printf("Invalid input. Enter the destination floor (between 1 and %d): ", num_floors);
      scanf("%d", &destination_floor);
    }
    
    // add the desired floor to the stops of the closest elevator
    int closest_elevator = 0;
    int min_distance = num_floors + 1;
    for(int j = 0; j < num_elevators; j++) {
      int distance = abs(current_floor - elevators[j].floor);
      if(distance < min_distance) {
        closest_elevator = j;
        min_distance = distance;
      }
    }
    add_stop(&elevators[closest_elevator], destination_floor);
  }
  
  // move the elevators until all stops have been visited
  int all_stops_visited = 0;
  while(!all_stops_visited) {
    all_stops_visited = 1;
    for(int i = 0; i < num_elevators; i++) {
      Elevator* e = &elevators[i];
      if(e->num_stops > 0) {
        all_stops_visited = 0;
        if(e->floor == e->stops[0]) {
          e->num_stops--;
          for(int j = 0; j < e->num_stops; j++) {
            e->stops[j] = e->stops[j+1];
          }
          e->direction = -1;
        }
        else {
          if(e->floor < e->stops[0]) {
            e->direction = 1;
          }
          else {
            e->direction = 0;
          }
          move_elevator(e);
        }
      }
    }
  }
  
  printf("All stops have been visited!\n");
  
  return 0;
}