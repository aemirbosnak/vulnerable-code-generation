//FormAI DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>
#include <stdbool.h>

void printMenu(); // function to print the main menu
void lengthConverter(); // function to convert lengths
void weightConverter(); // function to convert weights
void temperatureConverter(); // function to convert temperatures
void volumeConverter(); // function to convert volumes

int main() {
  int choice; // variable to store user's choice

  // loop until user chooses to exit
  while (true) {
    printMenu();

    // take user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        lengthConverter();
        break;
      case 2:
        weightConverter();
        break;
      case 3:
        temperatureConverter();
        break;
      case 4:
        volumeConverter();
        break;
      case 0:
        printf("Thank you for using the shape-shifting unit converter!\n");
        return 0;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}

// function to print the main menu
void printMenu() {
  printf("======= Shape-Shifting Unit Converter =======\n");
  printf("1. Length converter\n");
  printf("2. Weight converter\n");
  printf("3. Temperature converter\n");
  printf("4. Volume converter\n");
  printf("0. Exit\n");
}

// function to convert lengths
void lengthConverter() {
  float value;
  int choice;

  // loop until user chooses to go back to main menu
  while (true) {
    printf("======= Length Converter =======\n");
    printf("1. Inches to centimeters\n");
    printf("2. Feet to meters\n");
    printf("3. Miles to kilometers\n");
    printf("4. Centimeters to inches\n");
    printf("5. Meters to feet\n");
    printf("6. Kilometers to miles\n");
    printf("0. Back to main menu\n");

    // take user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter value in inches: ");
        scanf("%f", &value);
        printf("%.2f inches = %.2f centimeters\n", value, value * 2.54);
        break;
      case 2:
        printf("Enter value in feet: ");
        scanf("%f", &value);
        printf("%.2f feet = %.2f meters\n", value, value * 0.3048);
        break;
      case 3:
        printf("Enter value in miles: ");
        scanf("%f", &value);
        printf("%.2f miles = %.2f kilometers\n", value, value * 1.60934);
        break;
      case 4:
        printf("Enter value in centimeters: ");
        scanf("%f", &value);
        printf("%.2f centimeters = %.2f inches\n", value, value / 2.54);
        break;
      case 5:
        printf("Enter value in meters: ");
        scanf("%f", &value);
        printf("%.2f meters = %.2f feet\n", value, value / 0.3048);
        break;
      case 6:
        printf("Enter value in kilometers: ");
        scanf("%f", &value);
        printf("%.2f kilometers = %.2f miles\n", value, value / 1.60934);
        break;
      case 0:
        return;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}

// function to convert weights
void weightConverter() {
  float value;
  int choice;

  // loop until user chooses to go back to main menu
  while (true) {
    printf("======= Weight Converter =======\n");
    printf("1. Pounds to kilograms\n");
    printf("2. Ounces to grams\n");
    printf("3. Kilograms to pounds\n");
    printf("4. Grams to ounces\n");
    printf("0. Back to main menu\n");

    // take user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter value in pounds: ");
        scanf("%f", &value);
        printf("%.2f pounds = %.2f kilograms\n", value, value * 0.453592);
        break;
      case 2:
        printf("Enter value in ounces: ");
        scanf("%f", &value);
        printf("%.2f ounces = %.2f grams\n", value, value * 28.3495);
        break;
      case 3:
        printf("Enter value in kilograms: ");
        scanf("%f", &value);
        printf("%.2f kilograms = %.2f pounds\n", value, value / 0.453592);
        break;
      case 4:
        printf("Enter value in grams: ");
        scanf("%f", &value);
        printf("%.2f grams = %.2f ounces\n", value, value / 28.3495);
        break;
      case 0:
        return;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}

// function to convert temperatures
void temperatureConverter() {
  float value;
  int choice;

  // loop until user chooses to go back to main menu
  while (true) {
    printf("======= Temperature Converter =======\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("0. Back to main menu\n");

    // take user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter temperature in Celsius: ");
        scanf("%f", &value);
        printf("%.2f Celsius = %.2f Fahrenheit\n", value, value * 9/5 + 32);
        break;
      case 2:
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &value);
        printf("%.2f Fahrenheit = %.2f Celsius\n", value, (value - 32) * 5/9);
        break;
      case 0:
        return;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}

// function to convert volumes
void volumeConverter() {
  float value;
  int choice;

  // loop until user chooses to go back to main menu
  while (true) {
    printf("======= Volume Converter =======\n");
    printf("1. Liters to gallons\n");
    printf("2. Milliliters to fluid ounces\n");
    printf("3. Gallons to liters\n");
    printf("4. Fluid ounces to milliliters\n");
    printf("0. Back to main menu\n");

    // take user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter value in liters: ");
        scanf("%f", &value);
        printf("%.2f liters = %.2f gallons\n", value, value * 0.264172);
        break;
      case 2:
        printf("Enter value in milliliters: ");
        scanf("%f", &value);
        printf("%.2f milliliters = %.2f fluid ounces\n", value, value * 0.033814);
        break;
      case 3:
        printf("Enter value in gallons: ");
        scanf("%f", &value);
        printf("%.2f gallons = %.2f liters\n", value, value / 0.264172);
        break;
      case 4:
        printf("Enter value in fluid ounces: ");
        scanf("%f", &value);
        printf("%.2f fluid ounces = %.2f milliliters\n", value, value / 0.033814);
        break;
      case 0:
        return;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}