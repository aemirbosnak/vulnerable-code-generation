//FormAI DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>

/* Conversion functions */
float celciusToFahrenheit(float celcius) {
  return (celcius * 9/5) + 32;
}

float fahrenheitToCelcius(float fahrenheit) {
  return (fahrenheit - 32) * 5/9;
}

float kgToPounds(float kg) {
  return kg * 2.20462;
}

float poundsToKg(float pounds) {
  return pounds / 2.20462;
}

float kmToMiles(float km) {
  return km / 1.60934;
}

float milesToKm(float miles) {
  return miles * 1.60934;
}

/* Main function */
int main() {
  int choice, tempChoice, weightChoice, distanceChoice;
  float tempInput, tempOutput, weightInput, weightOutput, distanceInput, distanceOutput;

  printf("Welcome to the C Unit Converter!\n");

  /* Temperature conversion menu */
  printf("\nWhat temperature unit would you like to convert?\n");
  printf("1. Celcius to Fahrenheit\n");
  printf("2. Fahrenheit to Celcius\n");
  printf("Enter your choice: ");
  scanf("%d", &tempChoice);

  /* Taking input from user for Temperature units */
  switch(tempChoice) {
    case 1:
      printf("Enter temperature in Celcius: ");
      scanf("%f", &tempInput);
      tempOutput = celciusToFahrenheit(tempInput);
      printf("%.2fC is equal to %.2fF\n", tempInput, tempOutput);
      break;
    case 2:
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &tempInput);
      tempOutput = fahrenheitToCelcius(tempInput);
      printf("%.2fF is equal to %.2fC\n", tempInput, tempOutput);
      break;
    default:
      printf("Invalid choice\n");
      break;
  }

  /* Weight conversion menu */
  printf("\nWhat weight unit would you like to convert?\n");
  printf("1. Kilograms to Pounds\n");
  printf("2. Pounds to Kilograms\n");
  printf("Enter your choice: ");
  scanf("%d", &weightChoice);

  /* Taking input from user for weight */
  switch(weightChoice) {
    case 1:
      printf("Enter weight in Kilograms: ");
      scanf("%f", &weightInput);
      weightOutput = kgToPounds(weightInput);
      printf("%.2fkg is equal to %.2f pounds\n", weightInput, weightOutput);
      break;
    case 2:
      printf("Enter weight in Pounds: ");
      scanf("%f", &weightInput);
      weightOutput = poundsToKg(weightInput);
      printf("%.2f pounds is equal to %.2fkg\n", weightInput, weightOutput);
      break;
    default:
      printf("Invalid choice\n");
      break;
  }

  /* Distance conversion menu */
  printf("\nWhat distance unit would you like to convert?\n");
  printf("1. Kilometers to Miles\n");
  printf("2. Miles to Kilometers\n");
  printf("Enter your choice: ");
  scanf("%d", &distanceChoice);

  /* Taking input from user for distance */
  switch(distanceChoice) {
    case 1:
      printf("Enter distance in Kilometers: ");
      scanf("%f", &distanceInput);
      distanceOutput = kmToMiles(distanceInput);
      printf("%.2fkm is equal to %.2f miles\n", distanceInput, distanceOutput);
      break;
    case 2:
      printf("Enter distance in Miles: ");
      scanf("%f", &distanceInput);
      distanceOutput = milesToKm(distanceInput);
      printf("%.2f miles is equal to %.2fkm\n", distanceInput, distanceOutput);
      break;
    default:
      printf("Invalid choice\n");
      break;
  }

  printf("\nThank you for using the C Unit Converter!\n");

  return 0;
}