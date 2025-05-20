//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONES 10

struct drone {
   int id;
   int x;
   int y;
   int battery;
};

int main() {
   struct drone drones[MAX_DRONES];
   int num_drones = 0;
   char input;
   int i, j, id, x, y, battery;

   while (1) {
      // print the menu options
      printf("Menu:\n");
      printf("1. Add drone\n");
      printf("2. Remove drone\n");
      printf("3. Move drone\n");
      printf("4. Show all drones\n");
      printf("5. Exit\n");
      printf("Enter selection: ");

      // get the user's selection
      scanf(" %c", &input);

      switch (input) {
         // add a new drone
         case '1':
            if (num_drones < MAX_DRONES) {
               printf("Enter ID: ");
               scanf("%d", &id);
               printf("Enter starting X position: ");
               scanf("%d", &x);
               printf("Enter starting Y position: ");
               scanf("%d", &y);
               printf("Enter starting battery level: ");
               scanf("%d", &battery);

               drones[num_drones].id = id;
               drones[num_drones].x = x;
               drones[num_drones].y = y;
               drones[num_drones].battery = battery;

               num_drones++;
               printf("Drone added successfully.\n");
            } else {
               printf("Maximum number of drones reached!\n");
            }
            break;

         // remove a drone
         case '2':
            printf("Enter ID of drone to remove: ");
            scanf("%d", &id);

            // find the drone with the matching ID
            for (i = 0; i < num_drones; i++) {
               if (drones[i].id == id) {
                  // remove the drone by shifting all drones after it back one position
                  for (j = i; j < num_drones - 1; j++) {
                     drones[j] = drones[j+1];
                  }

                  num_drones--;
                  printf("Drone removed successfully.\n");
                  break;
               }
            }

            // if the ID wasn't found, display an error message
            if (i == num_drones) {
               printf("Drone not found!\n");
            }
            break;

         // move a drone
         case '3':
            printf("Enter ID of drone to move: ");
            scanf("%d", &id);

            // find the drone with the matching ID
            for (i = 0; i < num_drones; i++) {
               if (drones[i].id == id) {
                  // get the new coordinates and battery level for the drone
                  printf("Enter new X position: ");
                  scanf("%d", &x);
                  printf("Enter new Y position: ");
                  scanf("%d", &y);
                  printf("Enter new battery level: ");
                  scanf("%d", &battery);

                  // update the drone's information
                  drones[i].x = x;
                  drones[i].y = y;
                  drones[i].battery = battery;

                  printf("Drone moved successfully.\n");
                  break;
               }
            }

            // if the ID wasn't found, display an error message
            if (i == num_drones) {
               printf("Drone not found!\n");
            }
            break;

         // show all drones
         case '4':
            if (num_drones == 0) {
               printf("No drones found!\n");
            } else {
               printf("ID  X   Y   Battery\n");
               printf("====================\n");

               for (i = 0; i < num_drones; i++) {
                  printf("%d   %d   %d   %d\n", drones[i].id, drones[i].x, drones[i].y, drones[i].battery);
               }
            }
            break;

         // exit the program
         case '5':
            printf("Exiting program...\n");
            exit(0);
            break;

         // invalid input
         default:
            printf("Invalid selection!\n");
            break;
      }

      // print a blank line
      printf("\n");
   }

   return 0;
}