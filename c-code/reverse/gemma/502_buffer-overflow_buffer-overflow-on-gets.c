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
  int invasion_probability;

  // Get user input
  printf("Enter your name: ");
  gets(name);

  printf("Enter the date: ");
  gets(date);

  printf("Enter your secret code: ");
  scanf("%d", &secret_code);

  printf("Enter the alien type (A/B/C): ");
  scanf(" %c", &alien_type);

  printf("Enter the alien strength (1-10): ");
  scanf("%d", &alien_strength);

  // Calculate invasion probability
  invasion_probability = 0;
  if (secret_code % 3 == 0) {
    invasion_probability++;
  }
  if (alien_type == 'A') {
    invasion_probability++;
  }
  if (alien_strength >= 8) {
    invasion_probability++;
  }

  // Display invasion probability
  printf("Your invasion probability is: %d%%", invasion_probability * 10);

  return 0;
}
