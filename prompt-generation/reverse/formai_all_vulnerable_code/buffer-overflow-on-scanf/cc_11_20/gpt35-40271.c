//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>

int main() {
  printf("Welcome to our remote control vehicle simulation program!\n");
  
  // Variables to store vehicle status
  int isOn = 0; // 0 means off, 1 means on
  int speed = 0; // 0 to 100
  
  // Main loop
  while(1) {
    // Display current status
    printf("STATUS: ");
    if(isOn) {
      printf("ON, speed: %d\n", speed);
    } else {
      printf("OFF\n");
    }
    
    // Menu
    printf("MENU:\n");
    printf("1. Turn on\n");
    printf("2. Turn off\n");
    printf("3. Increase speed\n");
    printf("4. Decrease speed\n");
    printf("5. Exit\n");
    
    // User input
    printf("Please enter a number from the menu: ");
    int choice;
    scanf("%d", &choice);
    
    // Process choice
    switch(choice) {
      case 1:
        printf("Turning on...\n");
        isOn = 1;
        break;
      case 2:
        printf("Turning off...\n");
        isOn = 0;
        speed = 0;
        break;
      case 3:
        if(!isOn) {
          printf("Vehicle is off, cannot increase speed.\n");
        } else if(speed == 100) {
          printf("Cannot increase speed further.\n");
        } else {
          speed += 10;
          printf("Speed increased to %d.\n", speed);
        }
        break;
      case 4:
        if(!isOn) {
          printf("Vehicle is off, cannot decrease speed.\n");
        } else if(speed == 0) {
          printf("Cannot decrease speed further.\n");
        } else {
          speed -= 10;
          printf("Speed decreased to %d.\n", speed);
        }
        break;
      case 5:
        printf("Exiting program...\n");
        return 0;
      default:
        printf("Invalid choice, please try again.\n");
        break;
    }
  }
}