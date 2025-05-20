//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Password strength categories
#define WEAK 0
#define FAIR 1
#define GOOD 2
#define STRONG 3
#define EXCEL 4

// Password scoring system
#define LEN_BONUS 10  // Bonus points for length
#define NUM_BONUS 5   // Bonus points for numbers
#define SYM_BONUS 5   // Bonus points for symbols
#define CASE_BONUS 10  // Bonus points for mixed case

// Weakness descriptions
#define TOO_SHORT "Password is too short"
#define NO_NUMBERS "Password does not contain any numbers"
#define NO_SYMBOLS "Password does not contain any symbols"
#define NO_CASE_MIX "Password does not contain a mix of upper and lower case"

// Strength level descriptions
#define WRK_STR "Password strength: Weak"
#define FR_STR "Password strength: Fair"
#define GD_STR "Password strength: Good"
#define STR_STR "Password strength: Strong"
#define EXC_STR "Password strength: Excellent"

// Get password from user
char *get_password() {
  char *password = malloc(100);
  printf("Enter your password: ");
  scanf("%s", password);
  return password;
}

// Calculate password strength
int calculate_strength(char *password) {
  int strength = 0;
  int len = strlen(password);

  // Length bonus
  if (len >= 8) {
    strength += LEN_BONUS;
  }

  // Number bonus
  int num_count = 0;
  for (int i = 0; i < len; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      num_count++;
      break;
    }
  }
  if (num_count > 0) {
    strength += NUM_BONUS;
  }

  // Symbol bonus
  int sym_count = 0;
  for (int i = 0; i < len; i++) {
    if ((password[i] >= '!' && password[i] <= '/') ||
        (password[i] >= ':' && password[i] <= '@') ||
        (password[i] >= '[' && password[i] <= '`')) {
      sym_count++;
      break;
    }
  }
  if (sym_count > 0) {
    strength += SYM_BONUS;
  }

  // Case bonus
  int upper_count = 0;
  int lower_count = 0;
  for (int i = 0; i < len; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      upper_count++;
    } else if (password[i] >= 'a' && password[i] <= 'z') {
      lower_count++;
    }
  }
  if (upper_count > 0 && lower_count > 0) {
    strength += CASE_BONUS;
  }

  return strength;
}

// Display password strength
void display_strength(int strength) {
  switch (strength) {
    case WEAK:
      printf("%s\n", TOO_SHORT);
      printf("%s\n", WRK_STR);
      break;
    case FAIR:
      printf("%s\n", NO_NUMBERS);
      printf("%s\n", FR_STR);
      break;
    case GOOD:
      printf("%s\n", NO_SYMBOLS);
      printf("%s\n", GD_STR);
      break;
    case STRONG:
      printf("%s\n", NO_CASE_MIX);
      printf("%s\n", STR_STR);
      break;
    case EXCEL:
      printf("%s\n", EXC_STR);
      break;
  }
}

// Main function
int main() {
  char *password = get_password();
  int strength = calculate_strength(password);
  display_strength(strength);
  return 0;
}