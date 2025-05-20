//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>

int main(void) {
  printf("Welcome, fair traveler, to the Royal Unit Converter.\n");
  printf("We shall convert thy measurements with the utmost precision.\n");

  // Declare variables
  int choice;
  float value, result;

  // Display menu
  printf("Choose thy conversion type:\n");
  printf("1. Length (ells to leagues)\n");
  printf("2. Weight (stones to hundredweights)\n");
  printf("3. Volume (pints to gallons)\n");
  printf("4. Time (hours to days)\n");
  printf("Enter thy choice (1-4): ");
  scanf("%d", &choice);

  // Get the value to be converted
  printf("Enter the value to be converted: ");
  scanf("%f", &value);

  // Perform the conversion
  switch (choice) {
    case 1:
      result = value / 22;
      printf("%f ells is equal to %f leagues.\n", value, result);
      break;
    case 2:
      result = value / 8;
      printf("%f stones is equal to %f hundredweights.\n", value, result);
      break;
    case 3:
      result = value / 8;
      printf("%f pints is equal to %f gallons.\n", value, result);
      break;
    case 4:
      result = value / 24;
      printf("%f hours is equal to %f days.\n", value, result);
      break;
    default:
      printf("Invalid choice. Please enter a number between 1 and 4.\n");
  }

  // Display the result
  printf("The result is: %f\n", result);

  return 0;
}