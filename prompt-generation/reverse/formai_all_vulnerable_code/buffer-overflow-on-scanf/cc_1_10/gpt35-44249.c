//FormAI DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int option;
   float value;
   
   // Intro
   printf("\t\t====================\n");
   printf("\t\t||   UNIT CONVERTER   ||\n");
   printf("\t\t====================\n\n");
   
   while(1) {
      // Display options
      printf("Choose an option:\n");
      printf("1. Celsius to Fahrenheit\n");
      printf("2. Kilometers to Miles\n");
      printf("3. Pounds to Kilograms\n");
      printf("4. Exit\n\n");
      
      // Get user input
      printf("Option: ");
      scanf("%d", &option);
      
      // Process the option
      switch(option) {
         case 1:
            // Celsius to Fahrenheit
            printf("\nCelsius to Fahrenheit\n");
            printf("Enter temperature in Celsius: ");
            scanf("%f", &value);
            printf("%.2f C = %.2f F\n\n", value, value * 1.8 + 32);
            break;
         
         case 2:
            // Kilometers to Miles
            printf("\nKilometers to Miles\n");
            printf("Enter distance in kilometers: ");
            scanf("%f", &value);
            printf("%.2f km = %.2f mi\n\n", value, value * 0.6213712);
            break;
         
         case 3:
            // Pounds to Kilograms
            printf("\nPounds to Kilograms\n");
            printf("Enter weight in pounds: ");
            scanf("%f", &value);
            printf("%.2f lb = %.2f kg\n\n", value, value * 0.4535924);
            break;
         
         case 4:
            // Exit
            printf("\nExiting... Goodbye, Cyber Runner!\n");
            exit(0);
            break;
         
         default:
            // Invalid input
            printf("\nInvalid input. Try again, Cyber Runner.\n\n");
      }
   }
   
   return 0;
}