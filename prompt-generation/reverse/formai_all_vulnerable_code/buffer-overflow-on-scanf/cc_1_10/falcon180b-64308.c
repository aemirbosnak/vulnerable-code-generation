//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the main function
int main(void) {
   // Initialize variables
   float temperature = 0.0;
   int choice = 0;
   char unit;

   // Print the initial menu
   printf("Welcome to the Temperature Monitor!\n");
   printf("Please select a unit of measurement:\n");
   printf("1. Celsius\n");
   printf("2. Fahrenheit\n");
   printf("3. Kelvin\n");
   scanf("%d", &choice);

   // Convert the user's choice to a unit of measurement
   switch (choice) {
      case 1:
         unit = 'C';
         break;
      case 2:
         unit = 'F';
         break;
      case 3:
         unit = 'K';
         break;
      default:
         printf("Invalid choice. Exiting program.\n");
         return 1;
   }

   // Loop until the user chooses to exit
   while (choice!= 4) {
      // Print the current temperature
      printf("Current temperature: %.2f %c\n", temperature, unit);

      // Print the main menu
      printf("\nPlease select an option:\n");
      printf("1. Enter a new temperature\n");
      printf("2. Convert to a different unit\n");
      printf("3. Exit program\n");
      scanf("%d", &choice);

      // Handle the user's choice
      switch (choice) {
         case 1:
            // Prompt the user for a new temperature
            printf("Enter a new temperature: ");
            scanf("%f", &temperature);
            break;
         case 2:
            // Convert the temperature to a different unit
            printf("Enter the temperature to convert: ");
            scanf("%f", &temperature);
            printf("Enter the unit to convert to (C, F, or K): ");
            scanf(" %c", &unit);
            break;
         case 3:
            // Exit the program
            printf("Exiting program.\n");
            return 0;
         default:
            // Invalid choice
            printf("Invalid choice. Try again.\n");
      }
   }

   // Return 0 to indicate successful program execution
   return 0;
}