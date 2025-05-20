//FormAI DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>

int main() {
   float value;
   char unit_from, unit_to;
   float converted_value;

   printf("Enter the value to be converted: ");
   scanf("%f", &value);

   printf("Enter the unit to convert from [C, F, K]: ");
   scanf(" %c", &unit_from);

   printf("Enter the unit to convert to [C, F, K]: ");
   scanf(" %c", &unit_to);

   if (unit_from == 'C') {
      if (unit_to == 'F') {
         converted_value = (value * 9 / 5) + 32;
         printf("%.2fC is equal to %.2fF\n", value, converted_value);
      } else if (unit_to == 'K') {
         converted_value = value + 273.15;
         printf("%.2fC is equal to %.2fK\n", value, converted_value);
      } else {
         printf("Invalid unit to convert to\n");
      }
   } else if (unit_from == 'F') {
      if (unit_to == 'C') {
         converted_value = (value - 32) * 5 / 9;
         printf("%.2fF is equal to %.2fC\n", value, converted_value);
      } else if (unit_to == 'K') {
         converted_value = (value + 459.67) * 5 / 9;
         printf("%.2fF is equal to %.2fK\n", value, converted_value);
      } else {
         printf("Invalid unit to convert to\n");
      }
   } else if (unit_from == 'K') {
      if (unit_to == 'C') {
         converted_value = value - 273.15;
         printf("%.2fK is equal to %.2fC\n", value, converted_value);
      } else if (unit_to == 'F') {
         converted_value = (value * 9 / 5) - 459.67;
         printf("%.2fK is equal to %.2fF\n", value, converted_value);
      } else {
         printf("Invalid unit to convert to\n");
      }
   } else {
      printf("Invalid unit to convert from\n");
   }

   return 0;
}