//FormAI DATASET v1.0 Category: Smart home light control ; Style: mathematical
/* Smart Home Light Control Program
   Author: Chatbot
   Date: 2021-11-01
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define constants for the house and lightbulbs */
#define NUM_OF_ROOMS 3
#define NUM_OF_LIGHTS 5

/* Define struct for each lightbulb in a room */
struct lightbulb {
   int brightness;
   bool status;
};

/* Define struct for each room and its lightbulbs */
struct room {
   char name[20];
   struct lightbulb lights[NUM_OF_LIGHTS];
};

/* Define function prototypes */
void initializeRooms(struct room []);
void controlLights(struct room []);
void printRooms(struct room []);

/* Main function */
int main() {

   /* Declare array of rooms */
   struct room house[NUM_OF_ROOMS];
   
   /* Initialize the rooms and their lightbulbs */
   initializeRooms(house);

   /* Control the lights in each room */
   controlLights(house);

   /* Print the current status of the rooms and their lightbulbs */
   printRooms(house);

   return 0;
}

/* Function to initialize the rooms and their lightbulbs */
void initializeRooms(struct room house[]) {
   
   /* Initialize living room */
   strcpy(house[0].name, "Living Room");
   house[0].lights[0].brightness = 80;
   house[0].lights[0].status = true;
   house[0].lights[1].brightness = 50;
   house[0].lights[1].status = true;
   house[0].lights[2].brightness = 100;
   house[0].lights[2].status = false;
   house[0].lights[3].brightness = 30;
   house[0].lights[3].status = false;
   house[0].lights[4].brightness = 70;
   house[0].lights[4].status = false;

   /* Initialize bedroom */
   strcpy(house[1].name, "Bedroom");
   house[1].lights[0].brightness = 100;
   house[1].lights[0].status = true;
   house[1].lights[1].brightness = 75;
   house[1].lights[1].status = true;
   house[1].lights[2].brightness = 30;
   house[1].lights[2].status = false;
   house[1].lights[3].brightness = 50;
   house[1].lights[3].status = false;
   house[1].lights[4].brightness = 40;
   house[1].lights[4].status = false;

   /* Initialize kitchen */
   strcpy(house[2].name, "Kitchen");
   house[2].lights[0].brightness = 100;
   house[2].lights[0].status = true;
   house[2].lights[1].brightness = 70;
   house[2].lights[1].status = true;
   house[2].lights[2].brightness = 50;
   house[2].lights[2].status = false;
   house[2].lights[3].brightness = 80;
   house[2].lights[3].status = false;
   house[2].lights[4].brightness = 30;
   house[2].lights[4].status = false;

}

/* Function to control the lights in each room */
void controlLights(struct room house[]) {

   /* Variables for user input and loop control */
   int roomIndex, lightIndex, brightChoice, statusChoice;
   bool quit = false;
   char userInput;

   while (!quit) {
      /* Prompt user for room and light to adjust */
      printf("\nEnter the room number (1-3) and light number (1-5) to adjust (or type 'q' to quit):\n");
      userInput = getchar();

      /* Handle quit command */
      if (userInput == 'q') {
         quit = true;
         break;
      }

      /* Convert user input from char to int */
      roomIndex = userInput - '0';
      lightIndex = getchar() - '0';

      /* Clear the input buffer */
      fflush(stdin);

      /* Prompt user for brightness and status */
      printf("Enter the desired brightness (0-100): ");
      scanf("%d", &brightChoice);
      printf("Enter the desired status (0=off, 1=on): ");
      scanf("%d", &statusChoice);

      /* Update the specified lightbulb */
      house[roomIndex - 1].lights[lightIndex - 1].brightness = brightChoice;
      house[roomIndex - 1].lights[lightIndex - 1].status = (statusChoice == 1);
   }

}

/* Function to print the current state of the house */
void printRooms(struct room house[]) {

   /* Loop through the rooms and their lightbulbs and print their current status */
   printf("\nCurrent State of the House:\n\n");
   for (int i = 0; i < NUM_OF_ROOMS; i++) {
      printf("%s\n", house[i].name);
      for (int j = 0; j < NUM_OF_LIGHTS; j++) {
         printf("\tLight %d: Brightness=%d%%, Status=%s\n", j+1, house[i].lights[j].brightness, house[i].lights[j].status ? "on" : "off");
      }
      printf("\n");
   }

}