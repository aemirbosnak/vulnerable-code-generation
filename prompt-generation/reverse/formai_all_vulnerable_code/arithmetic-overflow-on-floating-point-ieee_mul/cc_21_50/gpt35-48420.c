//FormAI DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include<stdio.h>

int main() {

   float input;
   int unitChoice, conversionChoice;
   float output, kg, cm, m, ft, lb;
   
   printf("Please enter the value to be converted: ");
   scanf("%f", &input);
   
   printf("\nPlease select the current unit for conversion: \n");
   printf("1. Kilograms\n2. Centimeters\n3. Meters\n4. Feet\n5. Pounds\n\n");
   scanf("%d", &unitChoice);
   
   printf("\nPlease select the unit to convert to: \n");
   printf("1. Kilograms\n2. Centimeters\n3. Meters\n4. Feet\n5. Pounds\n\n");
   scanf("%d", &conversionChoice);
   
   if(unitChoice == 1) {
      kg = input;
      cm = input * 100000;
      m = input * 1000;
      ft = input * 3.28084;
      lb = input * 2.20462;
   } 
   else if(unitChoice == 2) {
      cm = input;
      kg = input / 100000;
      m = input / 100;
      ft = input / 30.48;
      lb = (input / 100000) * 2.20462;
   } 
   else if(unitChoice == 3) {
      m = input;
      kg = input * 1000;
      cm = input * 100;
      ft = input * 3.28084;
      lb = input * 2.20462;
   } 
   else if(unitChoice == 4) {
      ft = input;
      kg = input / 3.28084;
      cm = input * 30.48;
      m = input / 3.28084;
      lb = (input / 3.28084) * 2.20462;
   } 
   else if(unitChoice == 5) {
      lb = input;
      kg = input / 2.20462;
      cm = (input / 2.20462) * 100000;
      m = (input / 2.20462) * 1000;
      ft = input * 3.28084;
   }
   
   if(conversionChoice == 1) {
      output = kg;
   } 
   else if(conversionChoice == 2) {
      output = cm;
   } 
   else if(conversionChoice == 3) {
      output = m;
   } 
   else if(conversionChoice == 4) {
      output = ft;
   } 
   else if(conversionChoice == 5) {
      output = lb;
   }
   
   printf("\n%.2f ", input);
   
   if(unitChoice == 1)
      printf("kg");
   else if(unitChoice == 2)
      printf("cm");
   else if(unitChoice == 3)
      printf("m");
   else if(unitChoice == 4)
      printf("ft");
   else if(unitChoice == 5)
      printf("lb");
   
   printf(" is equivalent to ");
   
   printf("\n%.2f ", output);
   
   if(conversionChoice == 1)
      printf("kg");
   else if(conversionChoice == 2)
      printf("cm");
   else if(conversionChoice == 3)
      printf("m");
   else if(conversionChoice == 4)
      printf("ft");
   else if(conversionChoice == 5)
      printf("lb");

   return 0;
}