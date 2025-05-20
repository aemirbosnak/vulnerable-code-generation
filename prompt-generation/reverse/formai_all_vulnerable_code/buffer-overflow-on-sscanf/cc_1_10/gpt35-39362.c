//FormAI DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <string.h>

// struct to hold information about each light
struct Light {
   char name[20];
   int status;
};

// function to turn on/off a light
void toggleLight(struct Light* light) {
   if (light->status == 0) {
      light->status = 1;
      printf("%s is now on.\n", light->name);
   } else {
      light->status = 0;
      printf("%s is now off.\n", light->name);
   }
}

int main() {

   // create an array of Light structs
   struct Light lights[3] = {
      {"Living Room", 0},
      {"Bedroom", 0},
      {"Kitchen", 0}
   };

   // print welcome message
   printf("Welcome to the Smart Home Light Control System!\n\n");

   // loop until the user decides to quit
   while (1) {
      // display menu options
      printf("What would you like to do?\n");
      printf("1. View all lights\n");
      printf("2. Toggle a light\n");
      printf("3. Quit\n");

      // get user input
      char input[10];
      int choice;
      fgets(input, 10, stdin);
      sscanf(input, "%d", &choice);

      // perform action based on user input
      switch (choice) {
         case 1:
            // display status of all lights
            printf("\nLight Status:\n");
            for (int i = 0; i < 3; i++) {
               printf("%s: %s\n", lights[i].name, lights[i].status == 1 ? "On" : "Off");
            }
            printf("\n");
            break;
         case 2:
            // prompt user for which light to toggle
            printf("\nWhich light would you like to toggle?\n");
            for (int i = 0; i < 3; i++) {
               printf("%d. %s\n", i+1, lights[i].name);
            }
            fgets(input, 10, stdin);
            int lightChoice;
            sscanf(input, "%d", &lightChoice);

            // toggle the selected light
            toggleLight(&lights[lightChoice-1]);

            break;
         case 3:
            // quit program
            printf("\nGoodbye!\n");
            return 0;
         default:
            // handle invalid input
            printf("\nInvalid input. Please select a valid option.\n\n");
            break;
      }
   }
}