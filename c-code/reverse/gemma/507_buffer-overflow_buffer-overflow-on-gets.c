#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char name[20];
  char date[20];
  int secret_code;
  char alien_type;
  int alien_strength;
  int probability;

  // Get user input
  printf("Enter your name: ");
  gets(name);

  printf("Enter the date: ");
  gets(date);

  printf("Enter your secret code: ");
  scanf("%d", &secret_code);

  printf("Enter the alien type (A, B, C): ");
  scanf(" %c", &alien_type);

  printf("Enter the alien strength (1-10): ");
  scanf("%d", &alien_strength);

  // Calculate probability based on user input
  if (secret_code % 2 == 0 && alien_type == 'A' && alien_strength >= 8) {
    probability = 90;
  } else if (secret_code % 3 == 0 && alien_type == 'B' && alien_strength <= 5) {
    probability = 70;
  } else if (secret_code % 5 == 0 && alien_type == 'C' && alien_strength > 6) {
    probability = 50;
  } else {
    probability = 30;
  }

  // Display probability
  printf("The probability of an alien invasion is: %d%%", probability);

  return 0;
}
