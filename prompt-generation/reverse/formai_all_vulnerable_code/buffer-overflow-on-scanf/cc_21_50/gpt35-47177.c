//FormAI DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char option[5], fromUnit[15], toUnit[15];
  double value, result;
  
  printf("\nWelcome to the C Unit Converter!\n");
  printf("\nEnter the value you want to convert:\n");
  scanf("%lf", &value);
  
  printf("\nWhat unit would you like to convert from? (e.g. km, cm, lbs, etc.)\n");
  scanf("%s", fromUnit);
  
  printf("\nWhat unit would you like to convert to? (e.g. mi, in, kg, etc.)\n");
  scanf("%s", toUnit);
  
  // Convert all characters to lowercase
  for(int i = 0; i < strlen(fromUnit); i++) {
    fromUnit[i] = tolower(fromUnit[i]);
  }
  for(int i = 0; i < strlen(toUnit); i++) {
    toUnit[i] = tolower(toUnit[i]);
  }
  
  // Determine which conversion formula to use based on the units
  // Length
  if(strcmp(fromUnit, "km") == 0 && strcmp(toUnit, "m") == 0) {
    result = value * 1000;
  } else if(strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "km") == 0) {
    result = value / 1000;
  } else if(strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "cm") == 0) {
    result = value * 100;
  } else if(strcmp(fromUnit, "cm") == 0 && strcmp(toUnit, "m") == 0) {
    result = value / 100;
  } else if(strcmp(fromUnit, "cm") == 0 && strcmp(toUnit, "mm") == 0) {
    result = value * 10;
  } else if(strcmp(fromUnit, "mm") == 0 && strcmp(toUnit, "cm") == 0) {
    result = value / 10;
  }
  
  // Weight
  else if(strcmp(fromUnit, "kg") == 0 && strcmp(toUnit, "g") == 0) {
    result = value * 1000;
  } else if(strcmp(fromUnit, "g") == 0 && strcmp(toUnit, "kg") == 0) {
    result = value / 1000;
  } else if(strcmp(fromUnit, "g") == 0 && strcmp(toUnit, "mg") == 0) {
    result = value * 1000;
  } else if(strcmp(fromUnit, "mg") == 0 && strcmp(toUnit, "g") == 0) {
    result = value / 1000;
  } else {
    printf("\nSorry, units %s and %s cannot be converted.\n", fromUnit, toUnit);
    return 0;
  }
  
  printf("\n%lf %s = %lf %s\n", value, fromUnit, result, toUnit);
  
  return 0;
}