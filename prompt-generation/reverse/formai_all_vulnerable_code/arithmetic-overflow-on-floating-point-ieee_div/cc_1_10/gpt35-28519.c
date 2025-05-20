//FormAI DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>

int main() {
  // Display welcome message
  printf("Welcome to the peaceful unit converter.\n");

  // Declare variables
  double meters, feet, pounds, kilograms, gallons, liters;
  int choice;

  // Display menu options
  printf("\nPlease select an option:\n");
  printf("1. Meter to Feet\n");
  printf("2. Feet to Meter\n");
  printf("3. Pound to Kilogram\n");
  printf("4. Kilogram to Pound\n");
  printf("5. Gallon to Liter\n");
  printf("6. Liter to Gallon\n");
  
  // Get user choice
  scanf("%d", &choice);

  // Perform conversion based on user choice
  switch (choice) {
    case 1:
      printf("Enter meters: ");
      scanf("%lf", &meters);
      feet = meters/0.3048; //Conversion factor from meters to feet
      printf("%.2lf meters = %.2lf feet\n", meters, feet);
      break;

    case 2:
      printf("Enter feet: ");
      scanf("%lf", &feet);
      meters = feet*0.3048; //Conversion factor from feet to meters
      printf("%.2lf feet = %.2lf meters\n", feet, meters);
      break;

    case 3:
      printf("Enter pounds: ");
      scanf("%lf", &pounds);
      kilograms = pounds/2.2046; //Conversion factor from pounds to kilograms
      printf("%.2lf pounds = %.2lf kilograms\n", pounds, kilograms);
      break;

    case 4:
      printf("Enter kilograms: ");
      scanf("%lf", &kilograms);
      pounds = kilograms*2.2046; //Conversion factor from kilograms to pounds
      printf("%.2lf kilograms = %.2lf pounds\n", kilograms, pounds);
      break;

    case 5:
      printf("Enter gallons: ");
      scanf("%lf", &gallons);
      liters = gallons*3.7854; //Conversion factor from gallons to liters
      printf("%.2lf gallons = %.2lf liters\n", gallons, liters);
      break;

    case 6:
      printf("Enter liters: ");
      scanf("%lf", &liters);
      gallons = liters/3.7854; //Conversion factor from liters to gallons
      printf("%.2lf liters = %.2lf gallons\n", liters, gallons);
      break;

    default:
      printf("Invalid choice. Please try again.\n");
  }

  // Display exit message
  printf("Thank you for using the peaceful unit converter.\n");
  return 0;
}