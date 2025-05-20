//FormAI DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

int main() {
   float unit;
   printf("Welcome to the Ultimate Unit Converter!\n\n");
   printf("What would you like to convert today?\n");
   printf("1. Miles to Kilometers\n");
   printf("2. Pounds to Kilograms\n");
   printf("3. Fahrenheit to Celsius\n");
   printf("4. Feet to Meters\n");
   printf("5. Gallons to Liters\n");
   printf("6. Quit\n\n");
   
   int choice;
   printf("Enter your choice (1-6):\n");
   scanf("%d", &choice);
  
   switch(choice) {
      case 1: 
         printf("\nMiles to Kilometers Converter\n");
         printf("Enter number of Miles: ");
         scanf("%f", &unit);
         printf("%f Miles is %f Kilometers\n", unit, unit*1.609);
         break;
      case 2: 
         printf("\nPounds to Kilograms Converter\n");
         printf("Enter the weight in Pounds: ");
         scanf("%f", &unit);
         printf("%f Pounds is %f Kilograms\n", unit, unit*0.453592);
         break;
      case 3: 
         printf("\nFahrenheit to Celsius Converter\n");
         printf("Enter temperature in Fahrenheit: ");
         scanf("%f", &unit);
         printf("%f Fahrenheit is %f Celsius\n", unit, (unit-32)*0.5556);
         break;
      case 4: 
         printf("\nFeet to Meters Converter\n");
         printf("Enter length in Feet: ");
         scanf("%f", &unit);
         printf("%f Feet is %f Meters\n", unit, unit*0.3048);
         break;
      case 5: 
         printf("\nGallons to Liters Converter\n");
         printf("Enter volume in Gallons: ");
         scanf("%f", &unit);
         printf("%f Gallons is %f Liters\n", unit, unit*3.785);
         break;
      case 6: 
         printf("\nGoodbye! Thanks for using the Ultimate Unit Converter!\n");
         return 0;
      default: 
         printf("\nInvalid Choice. Please select a valid option (1-6):\n");
         break;
   }
}