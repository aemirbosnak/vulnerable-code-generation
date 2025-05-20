//FormAI DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>

int main() {
   int choice;
   double celsius, fahrenheit, kelvin, meter, kilometer, mile, kilogram, gram, pound;

   printf("Welcome to Unit Converter!\n\n");

   printf("1. Celsius to Fahrenheit\n");
   printf("2. Fahrenheit to Celsius\n");
   printf("3. Celsius to Kelvin\n");
   printf("4. Kelvin to Celsius\n");
   printf("5. Meter to Kilometer\n");
   printf("6. Kilometer to Meter\n");
   printf("7. Mile to Kilometer\n");
   printf("8. Kilometer to Mile\n");
   printf("9. Kilogram to Gram\n");
   printf("10. Gram to Kilogram\n");
   printf("11. Pound to Kilogram\n");
   printf("12. Kilogram to Pound\n\n");

   printf("Enter your choice [1-12]: ");
   scanf("%d", &choice);

   switch (choice) {
      case 1:
         printf("Enter temperature in Celsius: ");
         scanf("%lf", &celsius);

         fahrenheit = (celsius * 9/5) + 32;

         printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", celsius, fahrenheit);
         break;

      case 2:
         printf("Enter temperature in Fahrenheit: ");
         scanf("%lf", &fahrenheit);

         celsius = (fahrenheit - 32) * 5/9;

         printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", fahrenheit, celsius);
         break;

      case 3:
         printf("Enter temperature in Celsius: ");
         scanf("%lf", &celsius);

         kelvin = celsius + 273.15;

         printf("%.2lf Celsius is equal to %.2lf Kelvin.\n", celsius, kelvin);
         break;

      case 4:
         printf("Enter temperature in Kelvin: ");
         scanf("%lf", &kelvin);

         celsius = kelvin - 273.15;

         printf("%.2lf Kelvin is equal to %.2lf Celsius.\n", kelvin, celsius);
         break;

      case 5:
         printf("Enter distance in meters: ");
         scanf("%lf", &meter);

         kilometer = meter / 1000;

         printf("%.2lf Meters is equal to %.2lf Kilometers.\n", meter, kilometer);
         break;

      case 6:
         printf("Enter distance in kilometers: ");
         scanf("%lf", &kilometer);

         meter = kilometer * 1000;

         printf("%.2lf Kilometers is equal to %.2lf Meters.\n", kilometer, meter);
         break;

      case 7:
         printf("Enter distance in miles: ");
         scanf("%lf", &mile);

         kilometer = mile * 1.60934;

         printf("%.2lf Miles is equal to %.2lf Kilometers.\n", mile, kilometer);
         break;

      case 8:
         printf("Enter distance in kilometers: ");
         scanf("%lf", &kilometer);

         mile = kilometer * 0.621371;

         printf("%.2lf Kilometers is equal to %.2lf Miles.\n", kilometer, mile);
         break;

      case 9:
         printf("Enter weight in kilograms: ");
         scanf("%lf", &kilogram);

         gram = kilogram * 1000;

         printf("%.2lf Kilograms is equal to %.2lf Grams.\n", kilogram, gram);
         break;

      case 10:
         printf("Enter weight in grams: ");
         scanf("%lf", &gram);

         kilogram = gram / 1000;

         printf("%.2lf Grams is equal to %.2lf Kilograms.\n", gram, kilogram);
         break;

      case 11:
         printf("Enter weight in pounds: ");
         scanf("%lf", &pound);

         kilogram = pound * 0.453592;

         printf("%.2lf Pounds is equal to %.2lf Kilograms.\n", pound, kilogram);
         break;

      case 12:
         printf("Enter weight in kilograms: ");
         scanf("%lf", &kilogram);

         pound = kilogram / 0.453592;

         printf("%.2lf Kilograms is equal to %.2lf Pounds.\n", kilogram, pound);
         break;

      default:
         printf("Invalid choice!\n");
   }

   return 0;
}