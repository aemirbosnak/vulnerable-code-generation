//FormAI DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <string.h>

int main() {
  char fromUnit[10], toUnit[10]; //Unit string variables
  float inputValue, outputValue; //Values to convert
  //Conversion factors - length units (meter to ...)
  float meterToCentimeter = 100, meterToInch = 39.37, meterToFoot = 3.281;
  //Conversion factors - weight units (kilogram to ...)
  float kgToPound = 2.205, kgToOunce = 35.274, kgToGram = 1000;

  //User input
  printf("Enter the value to convert: ");
  scanf("%f", &inputValue);
  printf("Enter the unit to convert from: ");
  scanf("%s", &fromUnit);
  printf("Enter the unit to convert to: ");
  scanf("%s", &toUnit);

  //Length unit conversions
  if (strcmp(fromUnit, "meter") == 0) {
    if (strcmp(toUnit, "centimeter") == 0) {
      outputValue = inputValue * meterToCentimeter;
    }
    else if (strcmp(toUnit, "inch") == 0) {
      outputValue = inputValue * meterToInch;
    }
    else if (strcmp(toUnit, "foot") == 0) {
      outputValue = inputValue * meterToFoot;
    }
  }
  else if (strcmp(fromUnit, "centimeter") == 0) {
    if (strcmp(toUnit, "meter") == 0) {
      outputValue = inputValue / meterToCentimeter;
    }
    else if (strcmp(toUnit, "inch") == 0) {
      outputValue = inputValue / meterToCentimeter * meterToInch;
    }
    else if (strcmp(toUnit, "foot") == 0) {
      outputValue = inputValue / meterToCentimeter / meterToFoot;
    }
  }
  else if (strcmp(fromUnit, "inch") == 0) {
    if (strcmp(toUnit, "meter") == 0) {
      outputValue = inputValue / meterToInch;
    }
    else if (strcmp(toUnit, "centimeter") == 0) {
      outputValue = inputValue * meterToCentimeter / meterToInch;
    }
    else if (strcmp(toUnit, "foot") == 0) {
      outputValue = inputValue / 12;
    }
  }
  else if (strcmp(fromUnit, "foot") == 0) {
    if (strcmp(toUnit, "meter") == 0) {
      outputValue = inputValue / meterToFoot;
    }
    else if (strcmp(toUnit, "centimeter") == 0) {
      outputValue = inputValue * meterToCentimeter / meterToFoot;
    }
    else if (strcmp(toUnit, "inch") == 0) {
      outputValue = inputValue * 12;
    }
  }
  //Weight unit conversions
  else if (strcmp(fromUnit, "kilogram") == 0) {
    if (strcmp(toUnit, "pound") == 0) {
      outputValue = inputValue * kgToPound;
    }
    else if (strcmp(toUnit, "ounce") == 0) {
      outputValue = inputValue * kgToOunce;
    }
    else if (strcmp(toUnit, "gram") == 0) {
      outputValue = inputValue * kgToGram;
    }
  }
  else if (strcmp(fromUnit, "pound") == 0) {
    if (strcmp(toUnit, "kilogram") == 0) {
      outputValue = inputValue / kgToPound;
    }
    else if (strcmp(toUnit, "ounce") == 0) {
      outputValue = inputValue * 16;
    }
    else if (strcmp(toUnit, "gram") == 0) {
      outputValue = inputValue / kgToPound * kgToGram;
    }
  }
  else if (strcmp(fromUnit, "ounce") == 0) {
    if (strcmp(toUnit, "kilogram") == 0) {
      outputValue = inputValue / kgToOunce;
    }
    else if (strcmp(toUnit, "pound") == 0) {
      outputValue = inputValue / 16;
    }
    else if (strcmp(toUnit, "gram") == 0) {
      outputValue = inputValue / kgToOunce * kgToGram;
    }
  }
  else if (strcmp(fromUnit, "gram") == 0) {
    if (strcmp(toUnit, "kilogram") == 0) {
      outputValue = inputValue / kgToGram;
    }
    else if (strcmp(toUnit, "pound") == 0) {
      outputValue = inputValue / kgToGram * kgToPound;
    }
    else if (strcmp(toUnit, "ounce") == 0) {
      outputValue = inputValue / kgToGram * kgToOunce;
    }
  }
  else {
    //Invalid input
    printf("Sorry, that conversion is not supported.\n");
    return 0; //Exit program
  }

  //Print result
  printf("%.2f %s = %.2f %s\n", inputValue, fromUnit, outputValue, toUnit);
  return 0; //Exit program
}