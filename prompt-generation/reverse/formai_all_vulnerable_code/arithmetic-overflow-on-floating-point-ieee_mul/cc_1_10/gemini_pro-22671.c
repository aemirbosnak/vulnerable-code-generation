//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Declare the unit conversion functions
double fahrenheit_to_celsius(double fahrenheit);
double celsius_to_fahrenheit(double celsius);
double miles_to_kilometers(double miles);
double kilometers_to_miles(double kilometers);
double pounds_to_kilograms(double pounds);
double kilograms_to_pounds(double kilograms);

// Declare the main function
int main() {
  // Declare the variables
  double fahrenheit, celsius, miles, kilometers, pounds, kilograms;
  char choice;

  // Display the menu
  printf("Unit Converter\n");
  printf("1. Fahrenheit to Celsius\n");
  printf("2. Celsius to Fahrenheit\n");
  printf("3. Miles to Kilometers\n");
  printf("4. Kilometers to Miles\n");
  printf("5. Pounds to Kilograms\n");
  printf("6. Kilograms to Pounds\n");
  printf("Enter your choice: ");

  // Get the user's choice
  scanf("%c", &choice);

  // Convert the units based on the user's choice
  switch (choice) {
    case '1':
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%lf", &fahrenheit);
      celsius = fahrenheit_to_celsius(fahrenheit);
      printf("The temperature in Celsius is: %.2lf\n", celsius);
      break;
    case '2':
      printf("Enter the temperature in Celsius: ");
      scanf("%lf", &celsius);
      fahrenheit = celsius_to_fahrenheit(celsius);
      printf("The temperature in Fahrenheit is: %.2lf\n", fahrenheit);
      break;
    case '3':
      printf("Enter the distance in miles: ");
      scanf("%lf", &miles);
      kilometers = miles_to_kilometers(miles);
      printf("The distance in kilometers is: %.2lf\n", kilometers);
      break;
    case '4':
      printf("Enter the distance in kilometers: ");
      scanf("%lf", &kilometers);
      miles = kilometers_to_miles(kilometers);
      printf("The distance in miles is: %.2lf\n", miles);
      break;
    case '5':
      printf("Enter the weight in pounds: ");
      scanf("%lf", &pounds);
      kilograms = pounds_to_kilograms(pounds);
      printf("The weight in kilograms is: %.2lf\n", kilograms);
      break;
    case '6':
      printf("Enter the weight in kilograms: ");
      scanf("%lf", &kilograms);
      pounds = kilograms_to_pounds(kilograms);
      printf("The weight in pounds is: %.2lf\n", pounds);
      break;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}

// Define the unit conversion functions
double fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

double celsius_to_fahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

double miles_to_kilometers(double miles) {
  return miles * 1.60934;
}

double kilometers_to_miles(double kilometers) {
  return kilometers * 0.621371;
}

double pounds_to_kilograms(double pounds) {
  return pounds * 0.453592;
}

double kilograms_to_pounds(double kilograms) {
  return kilograms * 2.20462;
}