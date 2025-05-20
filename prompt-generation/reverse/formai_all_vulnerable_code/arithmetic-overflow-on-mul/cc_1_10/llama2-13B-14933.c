//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Invasive style variables
int l = 10; // length unit
int t = 20; // temperature unit
int w = 50; // weight unit

// Function prototypes
int length_convert(int val, int from, int to);
int temperature_convert(int val, int from, int to);
int weight_convert(int val, int from, int to);

int main() {
  // Invasive style code
  printf("Welcome to the Unit Converter!\n");
  printf("Please enter a value to convert: ");
  int val = getchar();
  printf("\n");

  // Convert length
  int converted_val = length_convert(val, l, "cm");
  printf("Length (%d %s) is %d %s\n", val, "cm", converted_val, "m");

  // Convert temperature
  converted_val = temperature_convert(val, t, "F");
  printf("Temperature (%d %s) is %d %s\n", val, "F", converted_val, "C");

  // Convert weight
  converted_val = weight_convert(val, w, "kg");
  printf("Weight (%d %s) is %d %s\n", val, "kg", converted_val, "lbs");

  return 0;
}

int length_convert(int val, int from, int to) {
  // Invasive style code
  if (from == l) {
    if (to == "cm") {
      return val * 10;
    } else if (to == "m") {
      return val;
    } else {
      printf("Invalid unit conversion request. Please try again.\n");
      return -1;
    }
  } else if (from == "cm") {
    if (to == l) {
      return val / 10;
    } else if (to == "m") {
      return val * 100;
    } else {
      printf("Invalid unit conversion request. Please try again.\n");
      return -1;
    }
  } else {
    printf("Invalid unit conversion request. Please try again.\n");
    return -1;
  }
}

int temperature_convert(int val, int from, int to) {
  // Invasive style code
  if (from == t) {
    if (to == "F") {
      return val * 9 / 5 + 32;
    } else if (to == "C") {
      return val - 32;
    } else {
      printf("Invalid unit conversion request. Please try again.\n");
      return -1;
    }
  } else if (from == "F") {
    if (to == t) {
      return val * 5 / 9 - 32;
    } else if (to == "C") {
      return val * 5 / 9;
    } else {
      printf("Invalid unit conversion request. Please try again.\n");
      return -1;
    }
  } else {
    printf("Invalid unit conversion request. Please try again.\n");
    return -1;
  }
}

int weight_convert(int val, int from, int to) {
  // Invasive style code
  if (from == w) {
    if (to == "kg") {
      return val * 10;
    } else if (to == "lbs") {
      return val / 2.2;
    } else {
      printf("Invalid unit conversion request. Please try again.\n");
      return -1;
    }
  } else if (from == "kg") {
    if (to == w) {
      return val / 10;
    } else if (to == "lbs") {
      return val * 2.2;
    } else {
      printf("Invalid unit conversion request. Please try again.\n");
      return -1;
    }
  } else {
    printf("Invalid unit conversion request. Please try again.\n");
    return -1;
  }
}