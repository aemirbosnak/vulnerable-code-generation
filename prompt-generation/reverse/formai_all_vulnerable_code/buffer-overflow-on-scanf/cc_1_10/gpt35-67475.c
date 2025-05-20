//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: sophisticated
#include <stdio.h>

// Define various drone movements
#define FORWARD "FW"
#define BACKWARD "BW"
#define LEFT "LT"
#define RIGHT "RT"
#define UP "UP"
#define DOWN "DN"

// Define the maximum number of movement commands a user can input
#define MAX_COMMANDS 100

// Define the length of the movement commands
#define MOVEMENT_LENGTH 2

int main() {
   char commands[MAX_COMMANDS][MOVEMENT_LENGTH];
   int num_commands = 0;

   // Prompt user for movement commands until they input "STOP"
   printf("Welcome to the drone remote control program.\n");
   printf("Enter your movement commands (e.g. FW for forward) and type STOP when finished.\n");
   while (1) {  // Continue prompting until a break statement is executed
      printf("Enter command: ");
      scanf("%s", commands[num_commands]);
      if (strcmp(commands[num_commands], "STOP") == 0) {
         break;  // Escape the loop 
      } 
      num_commands++;
   }

   // Execute each movement command in the order they were inputted
   printf("Executing movement commands...\n");
   for (int i = 0; i < num_commands; i++) {
      if (strcmp(commands[i], FORWARD) == 0) {
         printf("Moving forward.\n");
      } else if (strcmp(commands[i], BACKWARD) == 0) {
         printf("Moving backward.\n");
      } else if (strcmp(commands[i], LEFT) == 0) {
         printf("Moving left.\n");
      } else if (strcmp(commands[i], RIGHT) == 0) {
         printf("Moving right.\n");
      } else if (strcmp(commands[i], UP) == 0) {
         printf("Moving up.\n");
      } else if (strcmp(commands[i], DOWN) == 0) {
         printf("Moving down.\n");
      } else {
         printf("Invalid command: %s\n", commands[i]);
      }
   }

   // Exit the program
   printf("Drone has completed all movement commands. Exiting program.\n");
   return 0;
}