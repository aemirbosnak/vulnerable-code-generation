//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int current_floor = 1; // initialize current floor to 1
  int direction = 1; // initialize direction to up
  int num_floors = 10; // set the number of floors to 10
  int num_people = 0; // initialize number of people to 0

  printf("Welcome to the Love Elevator!\n");
  printf("Press 'p' to add a person to the elevator and 'q' to quit.\n");

  while(1) { // infinite loop until user quits
    char input; // variable to hold user input
    
    printf("The elevator is currently on floor %d.\n", current_floor);

    if (num_people == 1) {
      printf("There is 1 person in the elevator.\n");
    } else {
      printf("There are %d people in the elevator.\n", num_people);
    }

    if (direction == 1) {
      printf("The elevator is going up.\n");
    } else {
      printf("The elevator is going down.\n");
    }

    printf("> "); // prompt for user input
    scanf(" %c", &input); // read user input

    if (input == 'q') { // quit program if user inputs 'q'
      break;
    } else if (input == 'p' && num_people < 10) { // add person to elevator if user inputs 'p' and there is room in the elevator
      num_people++;
      printf("Added 1 person to the elevator.\n");
    } else if (input == 'p' && num_people >= 10) { // error message if elevator is full
      printf("Error: The elevator is full.\n");
    } else { // error message if user inputs anything other than 'p' or 'q'
      printf("Error: Invalid input.\n");
    }

    if (current_floor == num_floors) { // if elevator is on top floor, change direction to down
      direction = -1;
    } else if (current_floor == 1) { // if elevator is on bottom floor, change direction to up
      direction = 1;
    }

    current_floor += direction; // move elevator to next floor

    printf("\n"); // print blank line for formatting
  }

  printf("Thank you for riding the Love Elevator!\n");
  printf("You may exit the elevator now.\n");

  return 0;
}