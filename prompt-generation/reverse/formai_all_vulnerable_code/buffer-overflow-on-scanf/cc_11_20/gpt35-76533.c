//FormAI DATASET v1.0 Category: Smart home automation ; Style: genious
#include <stdio.h>
#include <stdbool.h>

int main() {
   // Initialize variables
   bool light1 = false;
   bool light2 = false;
   bool tv = false;
   bool ac = false;
   int temperature = 25;

   // Main program loop
   while (true) {
      // Display menu
      printf("Smart Home Automation Menu\n\n");
      printf("1. Turn on/off Light 1\n");
      printf("2. Turn on/off Light 2\n");
      printf("3. Turn on/off TV\n");
      printf("4. Turn on/off AC\n");
      printf("5. Set Temperature\n");
      printf("6. Exit\n");

      // Get user input
      printf("Please enter your choice: ");
      int choice;
      scanf("%d", &choice);

      // Process user input
      switch (choice) {
         case 1:
            // Toggle Light 1
            light1 = !light1;
            printf("Light 1 is now %s.\n", light1 ? "on" : "off");
            break;
         case 2:
            // Toggle Light 2
            light2 = !light2;
            printf("Light 2 is now %s.\n", light2 ? "on" : "off");
            break;
         case 3:
            // Toggle TV
            tv = !tv;
            printf("TV is now %s.\n", tv ? "on" : "off");
            break;
         case 4:
            // Toggle AC
            ac = !ac;
            printf("AC is now %s.\n", ac ? "on" : "off");
            break;
         case 5:
            // Set temperature
            printf("Please enter temperature: ");
            scanf("%d", &temperature);
            printf("Temperature set to %d degrees.\n", temperature);
            break;
         case 6:
            // Exit program
            printf("Exiting program.\n");
            return 0;
         default:
            // Invalid input
            printf("Invalid choice. Please try again.\n");
            break;
      }
   }
}