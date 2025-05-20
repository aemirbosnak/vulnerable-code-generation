//FormAI DATASET v1.0 Category: Smart home automation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  bool living_room_lights = false;
  bool kitchen_lights = false;
  bool bedroom_lights = false;
  bool garage_lights = false;
  
  printf("Welcome to the Smart Home automation puzzle!\n");
  printf("There are four rooms in this house: the living room, kitchen, bedroom, and garage.\n");
  printf("Each room has a corresponding set of lights that can be turned on or off.\n");
  printf("Your goal is to write a program that can control these lights based on user input.\n");

  while (true) {
    printf("\nWhat would you like to do?\n");
    printf("1) Turn on the living room lights\n");
    printf("2) Turn off the living room lights\n");
    printf("3) Turn on the kitchen lights\n");
    printf("4) Turn off the kitchen lights\n");
    printf("5) Turn on the bedroom lights\n");
    printf("6) Turn off the bedroom lights\n");
    printf("7) Turn on the garage lights\n");
    printf("8) Turn off the garage lights\n");
    printf("9) Quit\n\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (living_room_lights) {
          printf("Living room lights are already on!\n");
        } else {
          printf("Turning on living room lights...\n");
          living_room_lights = true;
        }
        break;
      case 2:
        if (living_room_lights) {
          printf("Turning off living room lights...\n");
          living_room_lights = false;
        } else {
          printf("Living room lights are already off!\n");
        }
        break;
      case 3:
        if (kitchen_lights) {
          printf("Kitchen lights are already on!\n");
        } else {
          printf("Turning on kitchen lights...\n");
          kitchen_lights = true;
        }
        break;
      case 4:
        if (kitchen_lights) {
          printf("Turning off kitchen lights...\n");
          kitchen_lights = false;
        } else {
          printf("Kitchen lights are already off!\n");
        }
        break;
      case 5:
        if (bedroom_lights) {
          printf("Bedroom lights are already on!\n");
        } else {
          printf("Turning on bedroom lights...\n");
          bedroom_lights = true;
        }
        break;
      case 6:
        if (bedroom_lights) {
          printf("Turning off bedroom lights...\n");
          bedroom_lights = false;
        } else {
          printf("Bedroom lights are already off!\n");
        }
        break;
      case 7:
        if (garage_lights) {
          printf("Garage lights are already on!\n");
        } else {
          printf("Turning on garage lights...\n");
          garage_lights = true;
        }
        break;
      case 8:
        if (garage_lights) {
          printf("Turning off garage lights...\n");
          garage_lights = false;
        } else {
          printf("Garage lights are already off!\n");
        }
        break;
      case 9:
        printf("Goodbye!\n");
        exit(0);
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }
  return 0;
}