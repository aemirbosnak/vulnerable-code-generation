//FormAI DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>

struct Light {
  char* name;
  int status;
};

void turnOn(struct Light* light) {
  light->status = 1;
  printf("%s is now turned on.\n", light->name); 
}

void turnOff(struct Light* light) {
  light->status = 0;
  printf("%s is now turned off.\n", light->name); 
}

int main() {
  struct Light livingRoomLight = {"Living Room Light", 0};
  struct Light bedroomLight = {"Bedroom Light", 0};
  
  printf("Welcome to Smart Home Light Control\n");
  
  while (1) {
    printf("\nWhat would you like to do?\n");
    printf("1. Turn on Living Room Light\n");
    printf("2. Turn off Living Room Light\n");
    printf("3. Turn on Bedroom Light\n");
    printf("4. Turn off Bedroom Light\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
      turnOn(&livingRoomLight);
    } else if (choice == 2) {
      turnOff(&livingRoomLight);
    } else if (choice == 3) {
      turnOn(&bedroomLight);
    } else if (choice == 4) {
      turnOff(&bedroomLight);
    } else if (choice == 5) {
      printf("Thank you for using Smart Home Light Control!\n");
      break;
    } else {
      printf("Invalid choice, please try again.\n");
    }
  }
  
  return 0;
}