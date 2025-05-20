//FormAI DATASET v1.0 Category: Smart home automation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
  int lightsOn = 0;
  int ACOn = 0;
  int doorLocked = 1; // locked by default
  
  printf("Welcome to your smart home!\n");
  
  while(1) { // infinite loop for continuous operation
    printf("\nWhat would you like to do?\n");
    printf("1. Turn the lights on/off\n");
    printf("2. Turn the AC on/off\n");
    printf("3. Lock/unlock the door\n");
    printf("4. Quit\n");
    
    int userChoice;
    scanf("%d", &userChoice);
    
    if(userChoice == 1) {
        if(lightsOn == 0) {
            printf("Turning the lights on\n");
            lightsOn = 1;
        }
        else {
            printf("Turning the lights off\n");
            lightsOn = 0;
        }
    }
    else if(userChoice == 2) {
        if(ACOn == 0) {
            printf("Turning the AC on\n");
            ACOn = 1;
        }
        else {
            printf("Turning the AC off\n");
            ACOn = 0;
        }
    }
    else if(userChoice == 3) {
        if(doorLocked == 0) {
            printf("Locking the door\n");
            doorLocked = 1;
        }
        else {
            printf("Unlocking the door\n");
            doorLocked = 0;
        }
    }
    else if(userChoice == 4) {
        printf("Thank you for using your smart home\n");
        exit(0); // exit program with status 0
    }
    else {
        printf("Invalid choice, please try again\n");
    }
  }
  
  return 0;
}