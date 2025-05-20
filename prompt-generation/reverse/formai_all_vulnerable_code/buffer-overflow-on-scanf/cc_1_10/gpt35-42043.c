//FormAI DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int choice;
   double value;
   double result;

   printf("Oh, unit converter, thou art the light\nOf my numerical world, oh so bright\n\n");
   printf("What unit conversion dost thou need?\n");
   printf("1. Fahrenheit to Celsius\n");
   printf("2. Pounds to Kilograms\n");
   printf("3. Miles to Kilometers\n");
   printf("4. Inches to Centimeters\n");
   printf("5. Gallons to Liters\n");

   printf("Enter thy choice, my dear customer: ");
   scanf("%d", &choice);

   switch (choice) {
      case 1:
         printf("\nOh Fahrenheit, thy realm of heat,\nWhat value would'st thou like to meet? ");
         scanf("%lf", &value);
         result = (value - 32) * 5 / 9;
         printf("%.2lf Fahrenheit is equal to %.2lf Celsius, my friend.\n\n", value, result);
         break;

      case 2:
         printf("\nOh pounds, thy weight heavy to bear,\nTell me how much, and I will convert with care: ");
         scanf("%lf", &value);
         result = value / 2.20462;
         printf("%.2lf pounds is equal to %.2lf kilograms, my dear.\n\n", value, result);
         break;

      case 3:
         printf("\nOh miles, thy distance long and far,\nI will convert, and thou shalt not be ajar: ");
         scanf("%lf", &value);
         result = value * 1.60934;
         printf("%.2lf miles is equal to %.2lf kilometers, my love.\n\n", value, result);
         break;

      case 4:
         printf("\nOh inches, thy length so small,\nI will convert it for thee, and not let thee fall: ");
         scanf("%lf", &value);
         result = value * 2.54;
         printf("%.2lf inches is equal to %.2lf centimeters, my sweet.\n\n", value, result);
         break;

      case 5:
         printf("\nOh gallons, thy volume bounteous and grand,\nI shall convert for thee, with my all-seeing hand: ");
         scanf("%lf", &value);
         result = value * 3.78541;
         printf("%.2lf gallons is equal to %.2lf liters, my darling.\n\n", value, result);
         break;

      default:
         printf("\nAlas, thou art a fool, for thou hast chosen wrong,\nAn error message shall be thy only song.\n\n");
         break;
   }

   printf("Farewell, dear customer, may the conversion be true,\nAnd may thy journey be easy, and simple too.\n");

   return 0;
}