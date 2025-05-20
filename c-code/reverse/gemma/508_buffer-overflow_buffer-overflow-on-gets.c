#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char name[20];
  gets(name);

  char date[20];
  gets(date);

  int secret_code = rand() % 1000;

  int alien_type = 0;
  printf("Select alien type:\n1. Small\n2. Medium\n3. Large\n");
  scanf("%d", &alien_type);

  int alien_strength = 0;
  printf("Select alien strength:\n1. Weak\n2. Moderate\n3. Strong\n");
  scanf("%d", &alien_strength);

  int invasion_probability = 0;
  switch (alien_type) {
    case 1:
      invasion_probability = 20 + alien_strength * 5;
      break;
    case 2:
      invasion_probability = 30 + alien_strength * 7;
      break;
    case 3:
      invasion_probability = 40 + alien_strength * 9;
      break;
  }

  printf("Your name: %s\n", name);
  printf("Date: %s\n", date);
  printf("Secret code: %d\n", secret_code);
  printf("Invasion probability: %d%%", invasion_probability);

  return 0;
}
