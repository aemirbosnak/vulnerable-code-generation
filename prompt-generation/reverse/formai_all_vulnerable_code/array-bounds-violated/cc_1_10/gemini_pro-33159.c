//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A mystical realm where characters dance in a symphony of bytes

typedef struct {
  char *name;    // Name of the character
  int health;    // Health points
  int attack;   // Attack power
  int defense;  // Defense power
} Character;

// An ancient scroll of characters
Character characters[] = {
  { "Warrior", 100, 20, 15 },
  { "Mage", 80, 15, 10 },
  { "Rogue", 90, 18, 12 },
  { "Healer", 70, 10, 15 }
};

// A wise old sage who sanitizes the realm
int sanitize(char *input) {
  int i, j;
  for (i = 0; input[i] != '\0'; i++) {
    for (j = 0; j < strlen("!@#$%^&*()"); j++) {
      if (input[i] == "!@#$%^&*()"[j]) {
        return 0;
      }
    }
  }
  return 1;
}

// A grand tournament where characters battle
void tournament() {
  char input[256];
  int choice;

  printf("Welcome to the Grand Tournament!\n");
  printf("Choose your character:\n");
  for (int i = 0; i < 4; i++) {
    printf("%d. %s\n", i + 1, characters[i].name);
  }

  while (1) {
    printf("> ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';  // Remove newline character

    if (!sanitize(input)) {
      printf("Invalid input. Please enter a number between 1 and 4.\n");
      continue;
    }

    choice = atoi(input) - 1;

    if (choice < 0 || choice > 3) {
      printf("Invalid choice. Please enter a number between 1 and 4.\n");
      continue;
    }

    printf("You have chosen %s.\n", characters[choice].name);
    break;
  }

  // The battle begins!
  Character enemy = characters[rand() % 4];
  while (characters[choice].health > 0 && enemy.health > 0) {
    printf("%s attacks %s for %d damage.\n", characters[choice].name, enemy.name, characters[choice].attack);
    enemy.health -= characters[choice].attack;
    printf("%s attacks %s for %d damage.\n", enemy.name, characters[choice].name, enemy.attack);
    characters[choice].health -= enemy.attack;
  }

  if (characters[choice].health <= 0) {
    printf("%s has been defeated!\n", characters[choice].name);
  } else {
    printf("%s has won the Grand Tournament!\n", characters[choice].name);
  }
}

int main() {
  tournament();
  return 0;
}