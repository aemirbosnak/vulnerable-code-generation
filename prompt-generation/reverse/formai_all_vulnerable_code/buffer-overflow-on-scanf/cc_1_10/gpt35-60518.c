//FormAI DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>

int main() {
   float meters, feet, inches, centimeters;

   int menu_choice;

   printf("Please select conversion option:\n");
   printf("1. Feet to Meters\n");
   printf("2. Inches to Centimeters\n");
   printf("3. Meters to Feet\n");
   printf("4. Centimeters to Inches\n");
   
   scanf("%d", &menu_choice);

   switch(menu_choice) {
      case 1: // feet to meters
         printf("Enter length in feet: ");
         scanf("%f", &feet);

         meters = feet / 3.281;

         printf("%.3f feet is %.3f meters\n", feet, meters);
         break;

      case 2: // inches to centimeters
         printf("Enter length in inches: ");
         scanf("%f", &inches);

         centimeters = inches * 2.54;

         printf("%.3f inches is %.3f centimeters\n", inches, centimeters);
         break;

      case 3: // meters to feet
         printf("Enter length in meters: ");
         scanf("%f", &meters);

         feet = meters * 3.281;

         printf("%.3f meters is %.3f feet\n", meters, feet);
         break;

      case 4: // centimeters to inches
         printf("Enter length in centimeters: ");
         scanf("%f", &centimeters);

         inches = centimeters / 2.54;

         printf("%.3f centimeters is %.3f inches\n", centimeters, inches);
         break;

      default:
         printf("Invalid input. Please enter a number between 1 and 4\n");
         break;
   }

   return 0;
}