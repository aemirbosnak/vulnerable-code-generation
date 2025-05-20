//FormAI DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>

int main () {
   char fromUnit[15], toUnit[15];
   float value, result;
   
   printf("Welcome to the Cyberpunk Unit Converter!\n");
   printf("Please enter your starting unit: ");
   scanf("%s", fromUnit);
   printf("Please enter the unit you want to convert to: ");
   scanf("%s", toUnit);
   printf("Please enter the value in %s: ", fromUnit);
   scanf("%f", &value);
   
   if(strcmp(fromUnit, "Human Years") == 0) {
      if(strcmp(toUnit, "Cyber Years") == 0) {
         result = value/0.33;
         printf("%.2f %s = %.2f %s", value, fromUnit, result, toUnit);
      } else if(strcmp(toUnit, "Robot Years") == 0) {
         result = value/0.66;
         printf("%.2f %s = %.2f %s", value, fromUnit, result, toUnit);
      } else {
         printf("Sorry, cannot convert to that unit.");
      }
   } else if(strcmp(fromUnit, "Cyber Years") == 0) {
      if(strcmp(toUnit, "Human Years") == 0) {
         result = value*0.33;
         printf("%.2f %s = %.2f %s", value, fromUnit, result, toUnit);
      } else if(strcmp(toUnit, "Robot Years") == 0) {
         result = value/2;
         printf("%.2f %s = %.2f %s", value, fromUnit, result, toUnit);
      } else {
         printf("Sorry, cannot convert to that unit.");
      }
   } else if(strcmp(fromUnit, "Robot Years") == 0) {
      if(strcmp(toUnit, "Human Years") == 0) {
         result = value*0.66;
         printf("%.2f %s = %.2f %s", value, fromUnit, result, toUnit);
      } else if(strcmp(toUnit, "Cyber Years") == 0) {
         result = value*2;
         printf("%.2f %s = %.2f %s", value, fromUnit, result, toUnit);
      } else {
         printf("Sorry, cannot convert to that unit.");
      }
   } else {
      printf("Sorry, cannot convert from that unit.");
   }
   
   return 0;
}