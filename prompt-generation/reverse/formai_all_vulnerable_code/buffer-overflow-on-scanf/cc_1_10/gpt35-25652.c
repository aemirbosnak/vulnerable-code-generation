//FormAI DATASET v1.0 Category: Smart home light control ; Style: enthusiastic
#include <stdio.h>

int main() {
  int livingRoomLights = 0;
  int bedroomLights = 0;

  printf("Welcome to Smart Home Light Controller!\n");

  while (1) {
    printf("Enter the room you want to control the lights:\n");
    printf("1. Living Room\n2. Bedroom\n");
    
    int roomNumber;
    scanf("%d", &roomNumber);
    
    if (roomNumber == 1) {
      printf("Living room lights are currently %s.\n", livingRoomLights ? "on" : "off");
      printf("Enter 1 to turn on the lights, 0 to turn them off:\n");

      int choice;
      scanf("%d", &choice);

      if (choice == 1) {
        livingRoomLights = 1;
        printf("Living room lights turned on.\n");
      } else if (choice == 0) {
        livingRoomLights = 0;
        printf("Living room lights turned off.\n");
      } else {
        printf("Invalid choice, please try again.\n");
      }
      
    } else if (roomNumber == 2) {
      printf("Bedroom lights are currently %s.\n", bedroomLights ? "on" : "off");
      printf("Enter 1 to turn on the lights, 0 to turn them off:\n");

      int choice;
      scanf("%d", &choice);

      if (choice == 1) {
        bedroomLights = 1;
        printf("Bedroom lights turned on.\n");
      } else if (choice == 0) {
        bedroomLights = 0;
        printf("Bedroom lights turned off.\n");
      } else {
        printf("Invalid choice, please try again.\n");
      }
      
    } else {
      printf("Invalid room number, please try again.\n");
    }
  }

  return 0;
}