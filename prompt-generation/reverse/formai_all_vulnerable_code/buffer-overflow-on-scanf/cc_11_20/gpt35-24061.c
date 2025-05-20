//FormAI DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>

int main() {

   float input_value, output_value;
   int input_unit, output_unit;
   
   // Display unit options
   printf("Select input unit: (1)meter (2)centimeter (3)millimeter\n");
   scanf("%d", &input_unit);
   printf("Select output unit: (1)kilometer (2)meter (3)centimeter (4)millimeter\n");
   scanf("%d", &output_unit);
   
   // Get input value
   printf("Enter value to convert: ");
   scanf("%f", &input_value);
   
   // Convert input value to meters
   switch(input_unit) {
      case 1: // meter
         output_value = input_value;
         break;
      case 2: // centimeter
         output_value = input_value / 100;
         break;
      case 3: // millimeter
         output_value = input_value / 1000;
         break;
      default:
         printf("Invalid input unit.\n");
         return 0;
   }
   
   // Convert meters to output value
   switch(output_unit) {
      case 1: // kilometer
         output_value /= 1000;
         break;
      case 2: // meter
         // already in meters
         break;
      case 3: // centimeter
         output_value *= 100;
         break;
      case 4: // millimeter
         output_value *= 1000;
         break;
      default:
         printf("Invalid output unit.\n");
         return 0;
   }
   
   // Display result
   printf("%f ", input_value);
   switch(input_unit) {
      case 1:
         printf("meter ");
         break;
      case 2:
         printf("centimeter ");
         break;
      case 3:
         printf("millimeter ");
         break;
   }
   printf("is equal to %f ", output_value);
   switch(output_unit) {
      case 1:
         printf("kilometer\n");
         break;
      case 2:
         printf("meter\n");
         break;
      case 3:
         printf("centimeter\n");
         break;
      case 4:
         printf("millimeter\n");
         break;
   }
   
   return 0;
}