//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Constants for the conversion factors
#define METERS_TO_FEET 3.281
#define FEET_TO_METERS 0.3048
#define KILOMETERS_TO_MILES 0.6214
#define MILES_TO_KILOMETERS 1.609

// Function to convert meters to feet
double meters_to_feet(double meters) {
  return meters * METERS_TO_FEET;
}

// Function to convert feet to meters
double feet_to_meters(double feet) {
  return feet * FEET_TO_METERS;
}

// Function to convert kilometers to miles
double kilometers_to_miles(double kilometers) {
  return kilometers * KILOMETERS_TO_MILES;
}

// Function to convert miles to kilometers
double miles_to_kilometers(double miles) {
  return miles * MILES_TO_KILOMETERS;
}

int main() {
  // Declarations of variables
  double meters, feet, kilometers, miles;
  int choice;
  char again;

  do{
    // Display menu of choices
    printf("My love, welcome to my humble unit converter. How may I assist you today?\n");
    printf("1. Convert meters to feet\n");
    printf("2. Convert feet to meters\n");
    printf("3. Convert kilometers to miles\n");
    printf("4. Convert miles to kilometers\n");
    printf("5. Quit\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the conversion based on the user's choice
    switch (choice) {
      case 1:
        printf("My love, how many meters would you like me to convert to feet?\n");
        scanf("%lf", &meters);
        feet = meters_to_feet(meters);
        printf("My dearest, %lf meters is equal to %lf feet.\n", meters, feet);
        break;
      case 2:
        printf("My love, how many feet would you like me to convert to meters?\n");
        scanf("%lf", &feet);
        meters = feet_to_meters(feet);
        printf("My dearest, %lf feet is equal to %lf meters.\n", feet, meters);
        break;
      case 3:
        printf("My love, how many kilometers would you like me to convert to miles?\n");
        scanf("%lf", &kilometers);
        miles = kilometers_to_miles(kilometers);
        printf("My dearest, %lf kilometers is equal to %lf miles.\n", kilometers, miles);
        break;
      case 4:
        printf("My love, how many miles would you like me to convert to kilometers?\n");
        scanf("%lf", &miles);
        kilometers = miles_to_kilometers(miles);
        printf("My dearest, %lf miles is equal to %lf kilometers.\n", miles, kilometers);
        break;
      case 5:
        printf("My love, it has been a pleasure serving you. Farewell.\n");
        exit(0);
      default:
        printf("Invalid choice. Please choose a valid option.\n");
        break;
    }
    // Ask the user if they want to continue
    printf("My love, would you like to perform another conversion? (Y/N)\n");
    scanf(" %c", &again);
  } while (again == 'Y' || again == 'y');

  return 0;
}