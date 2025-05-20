//FormAI DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>

int main() {
   int choice;
   float temp, celsius, fahrenheit, kelvin;

   printf("Enter the temperature in Celsius: ");
   scanf("%f", &celsius);
   printf("\n");

   printf("Choose the temperature unit to convert:\n");
   printf("1. Fahrenheit\n2. Kelvin\n");
   scanf("%d", &choice);

   switch(choice) {
      case 1:
         fahrenheit = (celsius * 9/5) + 32;
         printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
         break;
      case 2:
         kelvin = celsius + 273.15;
         printf("%.2f Celsius is %.2f Kelvin\n", celsius, kelvin);
         break;
      default:
         printf("Invalid choice!\n");
         break;
   }

   printf("\nEnter the temperature in Fahrenheit: ");
   scanf("%f", &fahrenheit);
   printf("\n");

   printf("Choose the temperature unit to convert:\n");
   printf("1. Celsius\n2. Kelvin\n");
   scanf("%d", &choice);

   switch(choice) {
      case 1:
         celsius = (fahrenheit - 32) * 5/9;
         printf("%.2f Fahrenheit is %.2f Celsius\n", fahrenheit, celsius);
         break;
      case 2:
         celsius = (fahrenheit - 32) * 5/9;
         kelvin = celsius + 273.15;
         printf("%.2f Fahrenheit is %.2f Kelvin\n", fahrenheit, kelvin);
         break;
      default:
         printf("Invalid choice!\n");
         break;
   }

   printf("\nEnter the temperature in Kelvin: ");
   scanf("%f", &kelvin);
   printf("\n");

   printf("Choose the temperature unit to convert:\n");
   printf("1. Celsius\n2. Fahrenheit\n");
   scanf("%d", &choice);

   switch(choice) {
      case 1:
         celsius = kelvin - 273.15;
         printf("%.2f Kelvin is %.2f Celsius\n", kelvin, celsius);
         break;
      case 2:
         celsius = kelvin - 273.15;
         fahrenheit = (celsius * 9/5) + 32;
         printf("%.2f Kelvin is %.2f Fahrenheit\n", kelvin, fahrenheit);
         break;
      default:
         printf("Invalid choice!\n");
         break;
   }

   return 0;
}