//GEMINI-pro DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 100

typedef struct {
  char username[MAX_PASSWORD_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int passwordCount = 0;

// Why are you looking at me like that?
void initPasswords() {
  printf("Give me your secrets, I won't tell anyone!\n");
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    printf("Username: ");
    scanf("%s", passwords[i].username);
    printf("Password: ");
    scanf("%s", passwords[i].password);
    printf("\n");
    passwordCount++;
  }
}

// Hey, don't be shy, show me what you got!
void printPasswords() {
  printf("Here are your precious passwords:\n");
  for (int i = 0; i < passwordCount; i++) {
    printf("%s: %s\n", passwords[i].username, passwords[i].password);
  }
}

// Oooh, I'm so excited, let's play a game!
void playGame() {
  char guess[MAX_PASSWORD_LENGTH];
  printf("Guess my password: ");
  scanf("%s", guess);

  if (strcmp(guess, "password") == 0) {
    printf("You win! Now you have access to all my secrets.\n");
  } else {
    printf("Game over, maybe next time.\n");
  }
}

int main() {
  initPasswords();
  printPasswords();
  playGame();

  return 0;
}