//FormAI DATASET v1.0 Category: Smart home automation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a device is turned on or off
bool is_device_on(bool status) {
  if(status == true) {
    return true;
  } else {
    return false;
  }
}

int main() {
  // Initial device statuses
  bool oven_status = false;
  bool air_conditioner_status = false;
  bool lights_status = false;
  
  // Welcome message
  printf("Welcome to Smart Home Automation\n");
  printf("--------------------------------\n\n");
  
  // User input options
  int user_choice;
  
  do {
    // Displaying the options
    printf("Please choose an option:\n\n");
    printf("1. Turn Oven On/OFF\n");
    printf("2. Turn Air Conditioner On/OFF\n");
    printf("3. Turn Lights On/OFF\n");
    printf("4. Exit\n\n");
    
    // Reading user's choice
    scanf("%d", &user_choice);
    
    // Handling user's choice
    switch(user_choice) {
      case 1:
        // Turn Oven On/OFF
        if(oven_status == true) {
          printf("Oven is turned OFF.\n\n");
          oven_status = false;
        } else {
          printf("Oven is turned ON.\n\n");
          oven_status = true;
        }
        break;
      case 2:
        // Turn Air Conditioner On/OFF
        if(air_conditioner_status == true) {
          printf("Air Conditioner is turned OFF.\n\n");
          air_conditioner_status = false;
        } else {
          printf("Air Conditioner is turned ON.\n\n");
          air_conditioner_status = true;
        }
        break;
      case 3:
        // Turn Lights On/OFF
        if(lights_status == true) {
          printf("Lights are turned OFF.\n\n");
          lights_status = false;
        } else {
          printf("Lights are turned ON.\n\n");
          lights_status = true;
        }
        break;
      case 4:
        // Exit
        printf("Thank you for using Smart Home Automation. Have a nice day!\n\n");
        break;
      default:
        // Invalid input
        printf("Invalid input. Please choose a valid option.\n\n");
    }
    
    // Checking the status of all the devices
    printf("Current status of all the devices:\n");
    printf("-----------------------------------\n");
    printf("Oven is %s.\n", is_device_on(oven_status) ? "ON" : "OFF");
    printf("Air Conditioner is %s.\n", is_device_on(air_conditioner_status) ? "ON" : "OFF");
    printf("Lights are %s.\n\n\n", is_device_on(lights_status) ? "ON" : "OFF");
  } while(user_choice != 4);

  return 0;
}