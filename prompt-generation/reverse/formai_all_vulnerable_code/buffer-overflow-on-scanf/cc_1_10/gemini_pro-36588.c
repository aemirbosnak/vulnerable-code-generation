//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: puzzling
#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  int choice;

  printf("\n**Temperature Converter: The Puzzling Edition**\n\n");

  while (1) {
    printf("**MENU**\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Quit\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
        break;

      case 2:
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * 5 / 9;
        printf("Temperature in Celsius: %.2f\n", celsius);
        break;

      case 3:
        printf("Quitting...\n");
        return 0;

      default:
        printf("Invalid choice. Please enter 1, 2, or 3.\n");
    }

    // The Enigma Puzzle
    printf("\n**Enigma Puzzle:**\n");
    int n = 20, sum = 0;
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 1) {
        sum += i;
      } else {
        sum -= i;
      }
    }
    printf("The encrypted value is: %d\n", sum);

    char guess[20];
    printf("To continue, guess the hidden word: ");
    scanf("%s", guess);

    if (strcmp(guess, "Enigma") == 0) {
      printf("Correct! You may continue.\n");
    } else {
      printf("Incorrect. Please try again.\n");
    }

    printf("\n");
  }

  return 0;
}