//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define some conversion constants
#define PI 3.14159
#define INF 1e99
#define EPS 1e-9

// Define some conversion functions
double deg2rad(double degrees) {
  return degrees * PI / 180;
}

double rad2deg(double radians) {
  return radians * 180 / PI;
}

double km2m(double kilometers) {
  return kilometers * 1000;
}

double m2km(double meters) {
  return meters / 1000;
}

double ft2m(double feet) {
  return feet * 0.3048;
}

double m2ft(double meters) {
  return meters / 0.3048;
}

double in2cm(double inches) {
  return inches * 2.54;
}

double cm2in(double centimeters) {
  return centimeters / 2.54;
}

double lb2kg(double pounds) {
  return pounds * 0.453592;
}

double kg2lb(double kilograms) {
  return kilograms / 0.453592;
}

// Define some happy variables
double happy_pi = 3.14159;
double happy_e = 2.71828;
double happy_inf = 1e99;

// Define the main function
int main() {
  // Print a happy message
  printf("Hello, World! Let's convert some stuff!\n");

  // Get some user input
  double degrees, radians, kilometers, meters, feet, inches, centimeters, pounds, kilograms;
  printf("Enter a value (in degrees): ");
  scanf("%lf", &degrees);
  printf("Enter a value (in radians): ");
  scanf("%lf", &radians);
  printf("Enter a value (in kilometers): ");
  scanf("%lf", &kilometers);
  printf("Enter a value (in meters): ");
  scanf("%lf", &meters);
  printf("Enter a value (in feet): ");
  scanf("%lf", &feet);
  printf("Enter a value (in inches): ");
  scanf("%lf", &inches);
  printf("Enter a value (in centimeters): ");
  scanf("%lf", &centimeters);
  printf("Enter a value (in pounds): ");
  scanf("%lf", &pounds);
  printf("Enter a value (in kilograms): ");
  scanf("%lf", &kilograms);

  // Do some conversions
  degrees = deg2rad(degrees);
  radians = rad2deg(radians);
  kilometers = km2m(kilometers);
  meters = m2km(meters);
  feet = ft2m(feet);
  inches = in2cm(inches);
  centimeters = cm2in(centimeters);
  pounds = lb2kg(pounds);
  kilograms = kg2lb(kilograms);

  // Print the results
  printf("Degrees: %f (%f radians)\n", degrees, radians);
  printf("Kilometers: %f meters (%f feet)\n", kilometers, meters);
  printf("Inches: %f centimeters (%f inches)\n", inches, centimeters);
  printf("Pounds: %f kilograms (%f pounds)\n", kilograms, pounds);

  // Print some happy messages
  printf("Happy Pi Day! %f is a happy number.\n", happy_pi);
  printf("Happy E Day! %f is a happy number.\n", happy_e);
  printf("Happy Infinity Day! %f is a happy number.\n", happy_inf);

  return 0;
}