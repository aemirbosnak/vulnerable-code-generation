//FormAI DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>

int main() {
   float input_value, output_value;
   int input_unit, output_unit;

   printf("Welcome to the Unit Converter!\n");
   printf("Please select the input unit:\n");
   printf("1. Length (meter)\n");
   printf("2. Weight (kilogram)\n");
   printf("3. Temperature (Celsius)\n");
   scanf("%d", &input_unit);

   printf("Please select the output unit:\n");
   printf("1. Length (meter)\n");
   printf("2. Weight (kilogram)\n");
   printf("3. Temperature (Celsius)\n");
   scanf("%d", &output_unit);

   printf("Please enter the input value:\n");
   scanf("%f", &input_value);

   // Length conversion
   if (input_unit == 1 && output_unit == 1) {
      output_value = input_value;
   } else if (input_unit == 1 && output_unit == 2) {
      output_value = input_value * 0.001;
   } else if (input_unit == 1 && output_unit == 3) {
      output_value = input_value * 39.3701;
   }

   // Weight conversion
   if (input_unit == 2 && output_unit == 1) {
      output_value = input_value * 1000;
   } else if (input_unit == 2 && output_unit == 2) {
      output_value = input_value;
   } else if (input_unit == 2 && output_unit == 3) {
      printf("Sorry, weight to temperature conversion is not available.\n");
      return 0;
   }

   // Temperature conversion
   if (input_unit == 3 && output_unit == 1) {
      output_value = input_value * 0.0254;
   } else if (input_unit == 3 && output_unit == 2) {
      printf("Sorry, temperature to weight conversion is not available.\n");
      return 0;
   } else if (input_unit == 3 && output_unit == 3) {
      output_value = input_value;
   }

   printf("%.2f", output_value);
   return 0;
}