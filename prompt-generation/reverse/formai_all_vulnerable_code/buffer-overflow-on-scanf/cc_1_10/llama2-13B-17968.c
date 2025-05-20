//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the unit conversion constants
#define PI 3.14159
#define INCHES_TO_METERS 0.0254
#define METERS_TO_INCHES 39.37
#define SPEED_OF_LIGHT 299792458
#define LIGHT_YEARS_TO_KILOMETERS 9.46073e12
#define KILOMETERS_TO_LIGHT_YEARS 0.001157

// Function to convert units of distance
float distance_convert(float distance, char from_unit, char to_unit) {
  float conversion_factor;

  switch (from_unit) {
    case 'i': // inches
      conversion_factor = INCHES_TO_METERS;
      break;
    case 'm': // meters
      conversion_factor = 1;
      break;
    default:
      printf("Invalid unit\n");
      return 0;
  }

  switch (to_unit) {
    case 'i': // inches
      distance *= conversion_factor;
      break;
    case 'm': // meters
      distance /= conversion_factor;
      break;
    default:
      printf("Invalid unit\n");
      return 0;
  }

  return distance;
}

// Function to convert units of speed
float speed_convert(float speed, char from_unit, char to_unit) {
  float conversion_factor;

  switch (from_unit) {
    case 'm/s': // meters per second
      conversion_factor = 1;
      break;
    case 'km/h': // kilometers per hour
      conversion_factor = 0.277778;
      break;
    case 'mph': // miles per hour
      conversion_factor = 0.44704;
      break;
    default:
      printf("Invalid unit\n");
      return 0;
  }

  switch (to_unit) {
    case 'm/s': // meters per second
      speed *= conversion_factor;
      break;
    case 'km/h': // kilometers per hour
      speed /= conversion_factor;
      break;
    case 'mph': // miles per hour
      speed *= conversion_factor / 0.44704;
      break;
    default:
      printf("Invalid unit\n");
      return 0;
  }

  return speed;
}

int main() {
  float distance, speed;
  char from_unit, to_unit;

  printf("Enter a distance in inches: ");
  scanf("%f", &distance);
  printf("Enter a unit of distance (i for inches, m for meters): ");
  scanf(" %c", &from_unit);
  printf("Enter a unit of distance (i for inches, m for meters): ");
  scanf(" %c", &to_unit);

  distance = distance_convert(distance, from_unit, to_unit);
  if (distance == 0) {
    printf("Invalid input\n");
    return 1;
  }

  printf("The distance in meters is: %f\n", distance);

  printf("Enter a speed in meters per second: ");
  scanf("%f", &speed);
  printf("Enter a unit of speed (m/s, km/h, or mph): ");
  scanf(" %c", &from_unit);
  printf("Enter a unit of speed (m/s, km/h, or mph): ");
  scanf(" %c", &to_unit);

  speed = speed_convert(speed, from_unit, to_unit);
  if (speed == 0) {
    printf("Invalid input\n");
    return 1;
  }

  printf("The speed in %c is %f\n", to_unit, speed);

  return 0;
}