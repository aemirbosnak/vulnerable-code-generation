//FormAI DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>

int main() {
   int option;
   float value, result;

   printf("Welcome to the Unit Converter!\n");
   printf("1. Celcius to Farenheit\n");
   printf("2. Kilometers to Miles\n");
   printf("3. Meters to Feet\n");
   printf("4. Grams to Ounces\n");
   printf("5. Exit\n");

   while (1) {
      printf("Enter an option: ");
      scanf("%d", &option);

      switch (option) {
         case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &value);
            result = ((value * 9) / 5) + 32;
            printf("%.2f Celsius = %.2f Farenheit\n", value, result);
            break;

         case 2:
            printf("Enter distance in Kilometers: ");
            scanf("%f", &value);
            result = value * 0.621371;
            printf("%.2f Kilometers = %.2f Miles\n", value, result);
            break;

         case 3:
            printf("Enter distance in Meters: ");
            scanf("%f", &value);
            result = value * 3.28084;
            printf("%.2f Meters = %.2f Feet\n", value, result);
            break;

         case 4:
            printf("Enter weight in Grams: ");
            scanf("%f", &value);
            result = value * 0.035274;
            printf("%.2f Grams = %.2f Ounces\n", value, result);
            break;

         case 5:
            printf("Goodbye!\n");
            return 0;

         default:
            printf("Invalid option! Please try again.\n");
      }
   }
}