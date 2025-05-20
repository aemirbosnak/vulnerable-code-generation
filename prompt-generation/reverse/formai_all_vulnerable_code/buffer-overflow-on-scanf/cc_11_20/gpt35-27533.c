//FormAI DATASET v1.0 Category: Smart home light control ; Style: curious
#include <stdio.h>

int main() {
   int room1 = 0, room2 = 0, room3 = 0;
   char command;

   printf("Welcome to Smart Home Light Control!\n");

   while (1) {
      printf("\nWhich room's light do you want to control? (Room 1, 2, or 3)\nEnter 'Q' to quit\n");

      scanf(" %c", &command);

      if (command == '1') {
         printf("Room 1 lights are currently %d. Press '0' for off or '1' for on\n", room1);
         scanf(" %c", &command);

         if (command == '0') {
            room1 = 0;
            printf("Room 1 lights turned off\n");
         } else if (command == '1') {
            room1 = 1;
            printf("Room 1 lights turned on\n");
         } else {
            printf("Invalid input\n");
         }
      } else if (command == '2') {
         printf("Room 2 lights are currently %d. Press '0' for off or '1' for on\n", room2);
         scanf(" %c", &command);

         if (command == '0') {
            room2 = 0;
            printf("Room 2 lights turned off\n");
         } else if (command == '1') {
            room2 = 1;
            printf("Room 2 lights turned on\n");
         } else {
            printf("Invalid input\n");
         }
      } else if (command == '3') {
         printf("Room 3 lights are currently %d. Press '0' for off or '1' for on\n", room3);
         scanf(" %c", &command);

         if (command == '0') {
            room3 = 0;
            printf("Room 3 lights turned off\n");
         } else if (command == '1') {
            room3 = 1;
            printf("Room 3 lights turned on\n");
         } else {
            printf("Invalid input\n");
         }
      } else if (command == 'Q') {
         printf("\nThank you for using Smart Home Light Control!\n");
         break;
      } else {
         printf("Invalid input\n");
      }
   }
   return 0;
}