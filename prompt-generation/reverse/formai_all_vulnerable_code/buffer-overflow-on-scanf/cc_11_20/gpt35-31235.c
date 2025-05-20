//FormAI DATASET v1.0 Category: Smart home automation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define LIGHTS 0
#define AC 1
#define DOOR 2

int main()
{
  int room1[3] = {0, 0, 0};
  int room2[3] = {0, 0, 0};

  printf("Welcome to the Smart Home Automation Program\n");

  int input;
  char c;

  do {
    printf("\n\n1. Turn on lights\n");
    printf("2. Turn off lights\n");
    printf("3. Turn on AC\n");
    printf("4. Turn off AC\n");
    printf("5. Unlock door\n");
    printf("6. Lock door\n");
    printf("7. Exit Program\n");

    printf("\nPlease enter your choice: ");
    scanf("%d",&input);
    scanf("%c", &c);

    int room, device;
    switch(input) {
      case 1:
        printf("\nPlease enter the room number (1 or 2): ");
        scanf("%d", &room);
        printf("Turning on lights in room %d...", room);
        room == 1 ? (room1[LIGHTS] = 1) : (room2[LIGHTS] = 1);
        break;
      case 2:
        printf("\nPlease enter the room number (1 or 2): ");
        scanf("%d", &room);
        printf("Turning off lights in room %d...", room);
        room == 1 ? (room1[LIGHTS] = 0) : (room2[LIGHTS] = 0);
        break;
      case 3:
        printf("\nPlease enter the room number (1 or 2): ");
        scanf("%d", &room);
        printf("Turning on AC in room %d...", room);
        room == 1 ? (room1[AC] = 1) : (room2[AC] = 1);
        break;
      case 4:
        printf("\nPlease enter the room number (1 or 2): ");
        scanf("%d", &room);
        printf("Turning off AC in room %d...", room);
        room == 1 ? (room1[AC] = 0) : (room2[AC] = 0);
        break;
      case 5:
        printf("\nUnlocking door...");
        room1[DOOR] = 1;
        break;
      case 6:
        printf("\nLocking door...");
        room1[DOOR] = 0;
        break;
      case 7:
        printf("\nExiting program...");
        break;
      default:
        printf("\nInvalid input! Please choose again.\n");
        continue;
    }

    printf("\n\nCurrent status of the house:\n");
    printf("Room 1: Lights %s, AC %s, Door %s\n", room1[LIGHTS] ? "ON" : "OFF", room1[AC] ? "ON" : "OFF", room1[DOOR] ? "UNLOCKED" : "LOCKED");
    printf("Room 2: Lights %s, AC %s\n", room2[LIGHTS] ? "ON" : "OFF", room2[AC] ? "ON" : "OFF");
  } while (input != 7);

  return 0;
}