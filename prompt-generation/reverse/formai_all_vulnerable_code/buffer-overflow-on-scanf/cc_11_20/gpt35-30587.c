//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>

int main() {
  int current_floor = 1; // starting floor at 1
  int target_floor;
  int direction; // 1 for up, -1 for down
  int floors[10] = {0}; // array to track which floors have been visited
  char response;
  
  printf("Welcome to the elevator simulation!\n");
  
  while(1) { // infinite loop until program is exited
    printf("You are currently on floor %d\n", current_floor);
    printf("Which floor would you like to go to? (1-10): ");
    scanf("%d", &target_floor);

    // validate target floor input
    if(target_floor > 10 || target_floor < 1) {
      printf("Invalid floor selection. Please choose a floor between 1 and 10.\n");
      continue;
    }
    
    // determine direction
    direction = target_floor > current_floor ? 1 : -1;
    
    // simulate elevator movement
    while(current_floor != target_floor) {
      current_floor += direction;
      floors[current_floor - 1] = 1; // mark floor as visited
      
      if(direction == 1) {
        printf("Going up...\n");
      } else {
        printf("Going down...\n");
      }
      
      printf("Now on floor %d\n", current_floor);
    }
    
    printf("You have arrived at your destination!\n");
    
    // ask if user wants to exit or continue riding elevator
    printf("Would you like to:\n");
    printf("(a) Exit elevator\n");
    printf("(b) Continue riding elevator\n");
    scanf(" %c", &response);
    
    if(response == 'a') {
      printf("Thank you for riding the elevator simulation. Goodbye!\n");
      break;
    } else if(response == 'b') {
      printf("Which floor would you like to go to next?: ");
    } else {
      printf("Invalid response. Please type 'a' or 'b'\n");
    }
  }
  
  // print visited floors at end of program
  printf("Floors visited during this simulation:\n");
  for(int i = 0; i < 10; i++) {
    if(floors[i] == 1) {
      printf("%d ", i+1);
    }
  }

  return 0;
}