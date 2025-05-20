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
  char alien_type[20];
  int alien_strength;

  printf("Please provide your name: ");
  gets(name);

  printf("Please provide the date: ");
  gets(date);

  printf("Please provide your secret code: ");
  scanf("%d", &secret_code);

  printf("Please select the alien type: ");
  gets(alien_type);

  printf("Please select the alien strength: ");
  scanf("%d", &alien_strength);

  int probability = calculate_invasion_probability(name, date, secret_code, alien_type, alien_strength);

  printf("Hello, %s. The probability of an alien invasion on %s is %d%.", name, date, probability);

  return 0;
}

int calculate_invasion_probability(char *name, char *date, int secret_code, char *alien_type, int alien_strength) {
  // Calculate the probability of an alien invasion based on user-supplied data
  // This function is not included in this code snippet
  return 0;
}
