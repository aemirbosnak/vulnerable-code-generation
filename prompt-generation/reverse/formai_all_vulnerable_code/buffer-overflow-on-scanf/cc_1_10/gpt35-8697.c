//FormAI DATASET v1.0 Category: Smart home automation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Function to check if the lights are on or off
int checkLights(int light1, int light2, int light3) {
   if (light1 == 0 && light2 == 0 && light3 == 0) {
      return 0;
   } else {
      return 1;
   }
}

// Function to check if the doors are open or closed
int checkDoors(int door1, int door2) {
   if (door1 == 0 && door2 == 0) {
      return 0;
   } else {
      return 1;
   }
}

int main() {
   int light1 = 0;
   int light2 = 0;
   int light3 = 0;
   int door1 = 0;
   int door2 = 0;
   int temp = 0;

   // Option menu for the user to choose from
   printf("Select an option:\n");
   printf("1. Turn on lights\n");
   printf("2. Turn off lights\n");
   printf("3. Open doors\n");
   printf("4. Close doors\n");
   printf("5. Set temperature\n");
   printf("6. Exit\n");
   int option = 0;
   scanf("%d", &option);

   while (option != 6) {
      // Option 1: Turn on lights
      if (option == 1) {
         printf("Which room's light do you want to turn on?\n");
         printf("1. Living room\n");
         printf("2. Bedroom\n");
         printf("3. Kitchen\n");
         int room = 0;
         scanf("%d", &room);
         if (room == 1) {
            light1 = 1;
         } else if (room == 2) {
            light2 = 1;
         } else if (room == 3) {
            light3 = 1;
         } else {
            printf("Invalid room number\n");
         }
      }

      // Option 2: Turn off lights
      else if (option == 2) {
         printf("Which room's light do you want to turn off?\n");
         printf("1. Living room\n");
         printf("2. Bedroom\n");
         printf("3. Kitchen\n");
         int room = 0;
         scanf("%d", &room);
         if (room == 1) {
            light1 = 0;
         } else if (room == 2) {
            light2 = 0;
         } else if (room == 3) {
            light3 = 0;
         } else {
            printf("Invalid room number\n");
         }
      }

      // Option 3: Open doors
      else if (option == 3) {
         printf("Which door do you want to open?\n");
         printf("1. Front door\n");
         printf("2. Back door\n");
         int door = 0;
         scanf("%d", &door);
         if (door == 1) {
            door1 = 1;
         } else if (door == 2) {
            door2 = 1;
         } else {
            printf("Invalid door number\n");
         }
      }

      // Option 4: Close doors
      else if (option == 4) {
         printf("Which door do you want to close?\n");
         printf("1. Front door\n");
         printf("2. Back door\n");
         int door = 0;
         scanf("%d", &door);
         if (door == 1) {
            door1 = 0;
         } else if (door == 2) {
            door2 = 0;
         } else {
            printf("Invalid door number\n");
         }
      }

      // Option 5: Set temperature
      else if (option == 5) {
         printf("Enter the temperature you want to set (in Celsius):\n");
         scanf("%d", &temp);
         printf("Temperature set to %dC\n", temp);
      }

      // Invalid option
      else {
         printf("Invalid option selected\n");
      }

      // Display current status of lights and doors
      printf("Current status:\n");
      printf("Lights: ");
      if (checkLights(light1, light2, light3) == 0) {
         printf("Off\n");
      } else {
         printf("On\n");
      }
      printf("Doors: ");
      if (checkDoors(door1, door2) == 0) {
         printf("Closed\n");
      } else {
         printf("Open\n");
      }
      printf("Current temperature: %dC\n", temp);

      // Display the option menu again
      printf("Select an option:\n");
      printf("1. Turn on lights\n");
      printf("2. Turn off lights\n");
      printf("3. Open doors\n");
      printf("4. Close doors\n");
      printf("5. Set temperature\n");
      printf("6. Exit\n");
      scanf("%d", &option);
   }

   printf("Goodbye!\n");

   return 0;
}