//FormAI DATASET v1.0 Category: Smart home automation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Declare global variables
bool livingRoomLight = false;
bool bedroomLight = false;
bool kitchenLight = false;
bool bathroomLight = false;

// Function for randomly turning lights on or off
void randomLightSwitch() {
  srand(time(NULL)); // Initialize random seed
  int randomNumber = rand() % 2; // Generate random number between 0 and 1
  
  if (randomNumber == 0) {
    livingRoomLight = !livingRoomLight; // Toggle living room light
  } else {
    bedroomLight = !bedroomLight; // Toggle bedroom light
    kitchenLight = !kitchenLight; // Toggle kitchen light
    bathroomLight = !bathroomLight; // Toggle bathroom light
  }
}

int main() {
  printf("Welcome to Smart Home Automation!\n");
  
  while (true) {
    printf("\n********** MENU **********\n");
    printf("1. Turn Living Room Light On/Off\n");
    printf("2. Turn Bedroom Light On/Off\n");
    printf("3. Turn Kitchen Light On/Off\n");
    printf("4. Turn Bathroom Light On/Off\n");
    printf("5. Randomly Turn Lights On/Off\n");
    printf("6. Exit\n\n");
    
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        livingRoomLight = !livingRoomLight; // Toggle living room light
        printf("Living Room Light is %s\n", 
              livingRoomLight ? "On" : "Off");
        break;
      case 2:
        bedroomLight = !bedroomLight; // Toggle bedroom light
        printf("Bedroom Light is %s\n", 
              bedroomLight ? "On" : "Off");
        break;
      case 3:
        kitchenLight = !kitchenLight; // Toggle kitchen light
        printf("Kitchen Light is %s\n", 
              kitchenLight ? "On" : "Off");
        break;
      case 4:
        bathroomLight = !bathroomLight; // Toggle bathroom light
        printf("Bathroom Light is %s\n", 
              bathroomLight ? "On" : "Off");
        break;
      case 5:
        randomLightSwitch(); // Randomly turn lights on or off
        printf("Living Room Light is %s\n", 
              livingRoomLight ? "On" : "Off");
        printf("Bedroom Light is %s\n", 
              bedroomLight ? "On" : "Off");
        printf("Kitchen Light is %s\n", 
              kitchenLight ? "On" : "Off");
        printf("Bathroom Light is %s\n", 
              bathroomLight ? "On" : "Off");
        break;
      case 6:
        printf("Goodbye!\n");
        exit(0); // Exit program
      default:
        printf("Invalid choice!\n");
    }
  }
  
  return 0;
}