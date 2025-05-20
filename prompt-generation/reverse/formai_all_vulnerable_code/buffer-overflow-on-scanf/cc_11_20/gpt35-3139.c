//FormAI DATASET v1.0 Category: Smart home automation ; Style: minimalist
#include <stdio.h>

int main() {
  int living_room_light_status = 0;
  int bedroom_light_status = 0;
  int bathroom_light_status = 0;
  int kitchen_light_status = 0;

  printf("Welcome to Smart Home Automation\n");

  while(1) {
    printf("\n");
    printf("Enter 1 to turn on the living room light\n");
    printf("Enter 2 to turn off the living room light\n");
    printf("Enter 3 to turn on the bedroom light\n");
    printf("Enter 4 to turn off the bedroom light\n");
    printf("Enter 5 to turn on the bathroom light\n");
    printf("Enter 6 to turn off the bathroom light\n");
    printf("Enter 7 to turn on the kitchen light\n");
    printf("Enter 8 to turn off the kitchen light\n");
    printf("Enter 0 to exit\n");

    int input;
    scanf("%d", &input);

    switch(input) {
      case 1:
        if(living_room_light_status == 0) {
          printf("Living room light is now on\n");
          living_room_light_status = 1;
        } else {
          printf("Living room light is already on\n");
        }
        break;
      case 2:
        if(living_room_light_status == 1) {
          printf("Living room light is now off\n");
          living_room_light_status = 0;
        } else {
          printf("Living room light is already off\n");
        }
        break;
      case 3:
        if(bedroom_light_status == 0) {
          printf("Bedroom light is now on\n");
          bedroom_light_status = 1;
        } else {
          printf("Bedroom light is already on\n");
        }
        break;
      case 4:
        if(bedroom_light_status == 1) {
          printf("Bedroom light is now off\n");
          bedroom_light_status = 0;
        } else {
          printf("Bedroom light is already off\n");
        }
        break;
      case 5:
        if(bathroom_light_status == 0) {
          printf("Bathroom light is now on\n");
          bathroom_light_status = 1;
        } else {
          printf("Bathroom light is already on\n");
        }
        break;
      case 6:
        if(bathroom_light_status == 1) {
          printf("Bathroom light is now off\n");
          bathroom_light_status = 0;
        } else {
          printf("Bathroom light is already off\n");
        }
        break;
      case 7:
        if(kitchen_light_status == 0) {
          printf("Kitchen light is now on\n");
          kitchen_light_status = 1;
        } else {
          printf("Kitchen light is already on\n");
        }
        break;
      case 8:
        if(kitchen_light_status == 1) {
          printf("Kitchen light is now off\n");
          kitchen_light_status = 0;
        } else {
          printf("Kitchen light is already off\n");
        }
        break;
      case 0:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid input\n");
        break;
    }
  }
}