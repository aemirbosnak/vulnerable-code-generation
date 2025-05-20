//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: brave
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MIN_PASS_SIZE 8  // A fortress must be strong to withstand siege
#define MAX_PASS_SIZE 256 // Yet, it must not be overly vast to become unwieldy

// Declare our trusty sentinels to guard against the weakest intrusions
int isLowerCase(char c);
int isUpperCase(char c);
int isDigit(char c);
int isSymbol(char c);

int main() {
  // Prepare to analyze the strength of the password, valiant traveler
  char password[MAX_PASS_SIZE];

  // Prompt the user to reveal their password, but conceal it from prying eyes
  printf("Enter your password, fearless guardian:\n");
  scanf("%s", password);

  // Now, let us scrutinize the password, seeking vulnerabilities
  int passwordStrength = 0;  // The stronghold's initial resilience
  int passwordSize = strlen(password);  // The stronghold's expanse

  // Ensure the stronghold is of sufficient size to withstand attack
  if (passwordSize < MIN_PASS_SIZE) {
    printf("Your password is too feeble, valiant warrior! It must have at least %d characters.\n", MIN_PASS_SIZE);
    return 1;  // Signal a retreat
  }

  // Examine each character, seeking evidence of strength or weakness
  for (int i = 0; i < passwordSize; i++) {
    // Is the character a valiant defender of the lower realms?
    if (isLowerCase(password[i])) {
      passwordStrength++;
    }

    // Or perhaps a formidable guardian of the upper realms?
    if (isUpperCase(password[i])) {
      passwordStrength++;
    }

    // Behold, a fierce warrior from the realm of numbers!
    if (isDigit(password[i])) {
      passwordStrength++;
    }

    // Ah, a mystical symbol from the unknown depths!
    if (isSymbol(password[i])) {
      passwordStrength += 2;  // Symbols are particularly potent defenders
    }
  }

  // Now, the moment of truth has arrived! Let us reveal the strength of the stronghold
  if (passwordStrength < 10) {
    printf("Your password is weak, brave warrior! Strengthen it to withstand the onslaught.\n");
  } else if (passwordStrength < 15) {
    printf("Your password is moderately strong, valiant guardian. Consider reinforcing it further.\n");
  } else {
    printf("Your password is a formidable fortress, valiant champion! It shall stand tall against all foes.\n");
  }

  return 0;  // The quest is complete, and victory is ours!
}

// Detect lowercase characters, the foot soldiers of the password
int isLowerCase(char c) {
  return (c >= 'a' && c <= 'z');
}

// Discover uppercase characters, the valiant knights of the password
int isUpperCase(char c) {
  return (c >= 'A' && c <= 'Z');
}

// Uncover digits, the powerful archers of the password
int isDigit(char c) {
  return (c >= '0' && c <= '9');
}

// Identify symbols, the enigmatic wizards of the password
int isSymbol(char c) {
  return (!isalnum(c) && !isspace(c));  // Symbols are the mysterious outcasts
}