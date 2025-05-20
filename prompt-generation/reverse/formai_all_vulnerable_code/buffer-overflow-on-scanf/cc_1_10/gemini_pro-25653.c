//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Convert temperature from Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

// Convert temperature from Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

// Convert length from meters to feet
double meters_to_feet(double meters) {
  return meters * 3.28084;
}

// Convert length from feet to meters
double feet_to_meters(double feet) {
  return feet / 3.28084;
}

// Convert weight from kilograms to pounds
double kilograms_to_pounds(double kilograms) {
  return kilograms * 2.20462;
}

// Convert weight from pounds to kilograms
double pounds_to_kilograms(double pounds) {
  return pounds / 2.20462;
}

// Convert volume from liters to gallons
double liters_to_gallons(double liters) {
  return liters * 0.264172;
}

// Convert volume from gallons to liters
double gallons_to_liters(double gallons) {
  return gallons / 0.264172;
}

int main() {
  // Get the user's input
  printf("What do you want to convert? (temperature, length, weight, volume)\n");
  char conversion_type[32];
  scanf("%s", conversion_type);

  printf("What is the value you want to convert?\n");
  double value;
  scanf("%lf", &value);

  // Convert the value based on the user's input
  double result;
  if (strcmp(conversion_type, "temperature") == 0) {
    printf("Is the value in Celsius or Fahrenheit? (celsius/fahrenheit)\n");
    char temperature_type[32];
    scanf("%s", temperature_type);

    if (strcmp(temperature_type, "celsius") == 0) {
      result = celsius_to_fahrenheit(value);
      printf("The converted value is %lf degrees Fahrenheit.\n", result);
    } else if (strcmp(temperature_type, "fahrenheit") == 0) {
      result = fahrenheit_to_celsius(value);
      printf("The converted value is %lf degrees Celsius.\n", result);
    } else {
      printf("Invalid temperature type.\n");
    }
  } else if (strcmp(conversion_type, "length") == 0) {
    printf("Is the value in meters or feet? (meters/feet)\n");
    char length_type[32];
    scanf("%s", length_type);

    if (strcmp(length_type, "meters") == 0) {
      result = meters_to_feet(value);
      printf("The converted value is %lf feet.\n", result);
    } else if (strcmp(length_type, "feet") == 0) {
      result = feet_to_meters(value);
      printf("The converted value is %lf meters.\n", result);
    } else {
      printf("Invalid length type.\n");
    }
  } else if (strcmp(conversion_type, "weight") == 0) {
    printf("Is the value in kilograms or pounds? (kilograms/pounds)\n");
    char weight_type[32];
    scanf("%s", weight_type);

    if (strcmp(weight_type, "kilograms") == 0) {
      result = kilograms_to_pounds(value);
      printf("The converted value is %lf pounds.\n", result);
    } else if (strcmp(weight_type, "pounds") == 0) {
      result = pounds_to_kilograms(value);
      printf("The converted value is %lf kilograms.\n", result);
    } else {
      printf("Invalid weight type.\n");
    }
  } else if (strcmp(conversion_type, "volume") == 0) {
    printf("Is the value in liters or gallons? (liters/gallons)\n");
    char volume_type[32];
    scanf("%s", volume_type);

    if (strcmp(volume_type, "liters") == 0) {
      result = liters_to_gallons(value);
      printf("The converted value is %lf gallons.\n", result);
    } else if (strcmp(volume_type, "gallons") == 0) {
      result = gallons_to_liters(value);
      printf("The converted value is %lf liters.\n", result);
    } else {
      printf("Invalid volume type.\n");
    }
  } else {
    printf("Invalid conversion type.\n");
  }

  return 0;
}