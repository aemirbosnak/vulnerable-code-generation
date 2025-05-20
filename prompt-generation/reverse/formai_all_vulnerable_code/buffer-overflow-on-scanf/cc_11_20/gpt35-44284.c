//FormAI DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
   char livingRoom = 'O';
   char kitchen = 'O';
   char bedroom = 'O';
   char bathroom = 'O';
   char garage = 'O';

   printf("Welcome to your smart home!\n");

   while (1) {
      printf("Enter the room you would like to toggle (Living Room, Kitchen, Bedroom, Bathroom, Garage): ");
      char room[20];
      scanf("%s", room);
      
      if (strcmp(room, "Living Room") == 0) {
         if (livingRoom == 'O') {
            livingRoom = 'X';
         } else {
            livingRoom = 'O';
         }
      } else if (strcmp(room, "Kitchen") == 0) {
         if (kitchen == 'O') {
            kitchen = 'X';
         } else {
            kitchen = 'O';
         }
      } else if (strcmp(room, "Bedroom") == 0) {
         if (bedroom == 'O') {
            bedroom = 'X';
         } else {
            bedroom = 'O';
         }
      } else if (strcmp(room, "Bathroom") == 0) {
         if (bathroom == 'O') {
            bathroom = 'X';
         } else {
            bathroom = 'O';
         }
      } else if (strcmp(room, "Garage") == 0) {
         if (garage == 'O') {
            garage = 'X';
         } else {
            garage = 'O';
         }
      } else {
         printf("Invalid room name.\n");
      }

      printf("Living Room: %c\n", livingRoom);
      printf("Kitchen: %c\n", kitchen);
      printf("Bedroom: %c\n", bedroom);
      printf("Bathroom: %c\n", bathroom);
      printf("Garage: %c\n", garage);

      printf("--------------------\n");
   }

   return 0;
}