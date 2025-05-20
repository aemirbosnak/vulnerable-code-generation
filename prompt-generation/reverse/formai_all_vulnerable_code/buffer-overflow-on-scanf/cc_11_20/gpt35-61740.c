//FormAI DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>

int main() {
   float val1, val2;
   char unit1, unit2;
   printf("Welcome to the Unit Converter!\n");
   printf("Enter your value: ");
   scanf("%f", &val1);
   printf("Enter your unit (m, cm, ft, in): ");
   scanf(" %c", &unit1);
   
   if (unit1 == 'm') {
      printf("You entered %f meters.\n", val1);
      printf("What would you like to convert it to? (cm, ft, in): ");
      scanf(" %c", &unit2);
      if (unit2 == 'cm') {
         val2 = val1 * 100;
         printf("%f meters is equal to %f centimeters.\n", val1, val2);
      } else if (unit2 == 'ft') {
         val2 = val1 * 3.28084;
         printf("%f meters is equal to %f feet.\n", val1, val2);
      } else if (unit2 == 'in') {
         val2 = val1 * 39.3701;
         printf("%f meters is equal to %f inches.\n", val1, val2);
      } else {
         printf("Invalid unit!\n");
      }
   } else if (unit1 == 'cm') {
      printf("You entered %f centimeters.\n", val1);
      printf("What would you like to convert it to? (m, ft, in): ");
      scanf(" %c", &unit2);
      if (unit2 == 'm') {
         val2 = val1 * 0.01;
         printf("%f centimeters is equal to %f meters.\n", val1, val2);
      } else if (unit2 == 'ft') {
         val2 = val1 * 0.0328084;
         printf("%f centimeters is equal to %f feet.\n", val1, val2);
      } else if (unit2 == 'in') {
         val2 = val1 * 0.393701;
         printf("%f centimeters is equal to %f inches.\n", val1, val2);
      } else {
         printf("Invalid unit!\n");
      }
   } else if (unit1 == 'ft') {
      printf("You entered %f feet.\n", val1);
      printf("What would you like to convert it to? (m, cm, in): ");
      scanf(" %c", &unit2);
      if (unit2 == 'm') {
         val2 = val1 * 0.3048;
         printf("%f feet is equal to %f meters.\n", val1, val2);
      } else if (unit2 == 'cm') {
         val2 = val1 * 30.48;
         printf("%f feet is equal to %f centimeters.\n", val1, val2);
      } else if (unit2 == 'in') {
         val2 = val1 * 12;
         printf("%f feet is equal to %f inches.\n", val1, val2);
      } else {
         printf("Invalid unit!\n");
      }
   } else if (unit1 == 'in') {
      printf("You entered %f inches.\n", val1);
      printf("What would you like to convert it to? (m, cm, ft): ");
      scanf(" %c", &unit2);
      if (unit2 == 'm') {
         val2 = val1 * 0.0254;
         printf("%f inches is equal to %f meters.\n", val1, val2);
      } else if (unit2 == 'cm') {
         val2 = val1 * 2.54;
         printf("%f inches is equal to %f centimeters.\n", val1, val2);
      } else if (unit2 == 'ft') {
         val2 = val1 * 0.0833333;
         printf("%f inches is equal to %f feet.\n", val1, val2);
      } else {
         printf("Invalid unit!\n");
      }
   } else {
      printf("Invalid unit!\n");
   }

   return 0;
}