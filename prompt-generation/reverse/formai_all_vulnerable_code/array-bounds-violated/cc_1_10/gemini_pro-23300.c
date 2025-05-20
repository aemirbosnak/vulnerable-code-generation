//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Home appliance control codes
#define TURN_ON 1
#define TURN_OFF 0

// Home appliance types
#define LIGHT 1
#define FAN 2
#define AC 3

// Home appliance names
char *appliance_names[] = {"Light", "Fan", "AC"};

// Home appliance states
int appliance_states[3] = {0, 0, 0};

// Function to print the home appliance control menu
void print_menu() {
  printf("\nRetro Smart Home Automation\n");
  printf("--------------------------\n");
  printf("1. Turn on a device\n");
  printf("2. Turn off a device\n");
  printf("3. Exit\n");
  printf("--------------------------\n");
  printf("Enter your choice: ");
}

// Function to turn on a home appliance
void turn_on_appliance(int appliance_type) {
  if (appliance_states[appliance_type - 1] == TURN_ON) {
    printf("The %s is already on.\n", appliance_names[appliance_type - 1]);
  } else {
    appliance_states[appliance_type - 1] = TURN_ON;
    printf("The %s has been turned on.\n", appliance_names[appliance_type - 1]);
  }
}

// Function to turn off a home appliance
void turn_off_appliance(int appliance_type) {
  if (appliance_states[appliance_type - 1] == TURN_OFF) {
    printf("The %s is already off.\n", appliance_names[appliance_type - 1]);
  } else {
    appliance_states[appliance_type - 1] = TURN_OFF;
    printf("The %s has been turned off.\n", appliance_names[appliance_type - 1]);
  }
}

// Main function
int main() {
  int choice, appliance_type;

  while (1) {
    print_menu();
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the appliance you want to turn on (1 - Light, 2 - Fan, 3 - AC): ");
      scanf("%d", &appliance_type);
      turn_on_appliance(appliance_type);
      break;
    case 2:
      printf("Enter the appliance you want to turn off (1 - Light, 2 - Fan, 3 - AC): ");
      scanf("%d", &appliance_type);
      turn_off_appliance(appliance_type);
      break;
    case 3:
      exit(0);
    default:
      printf("Invalid choice.\n");
    }
  }

  return 0;
}