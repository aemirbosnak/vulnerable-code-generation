#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char name[20];
  char date[20];
  char alien_type[20];
  int strength;
  int top_secret_code;
  int alien_invasion_chance;

  printf("Enter your name: ");
  scanf("%s", name);

  printf("Enter the date: ");
  scanf("%s", date);

  printf("Enter the alien type: ");
  scanf("%s", alien_type);

  printf("Enter the alien strength: ");
  scanf("%d", &strength);

  printf("Enter the top-secret code: ");
  scanf("%d", &top_secret_code);

  srand(time(NULL));
  alien_invasion_chance = rand() % 100 + 1;

  if (strength >= 5 && top_secret_code == 12) {
    alien_invasion_chance = alien_invasion_chance * 2;
  }

  printf("Your probability of alien invasion is: %.2f%%", alien_invasion_chance);

  return 0;
}
