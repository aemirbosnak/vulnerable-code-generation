//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32
#define MIN_UPPERCASE 1
#define MIN_LOWERCASE 1
#define MIN_NUMBERS 1
#define MIN_SYMBOLS 1

int check_length(char *password);
int check_uppercase(char *password);
int check_lowercase(char *password);
int check_numbers(char *password);
int check_symbols(char *password);
int check_consecutive(char *password);
int check_repeats(char *password);
int check_dictionary(char *password);

int main() {
  char password[MAX_LENGTH + 1];
  int score = 0;

  printf("Enter a password: ");
  scanf("%s", password);

  score += check_length(password);
  score += check_uppercase(password);
  score += check_lowercase(password);
  score += check_numbers(password);
  score += check_symbols(password);
  score -= check_consecutive(password);
  score -= check_repeats(password);
  score -= check_dictionary(password);

  printf("Your password score is %d\n", score);

  if (score < 0) {
    printf("Your password is too weak!\n");
  } else if (score < 5) {
    printf("Your password is weak!\n");
  } else if (score < 7) {
    printf("Your password is strong!\n");
  } else {
    printf("Your password is very strong!\n");
  }

  return 0;
}

// Check the length of the password.
int check_length(char *password) {
  int length = strlen(password);

  if (length < MIN_LENGTH) {
    return -1;
  } else if (length > MAX_LENGTH) {
    return -2;
  } else {
    return 1;
  }
}

// Check for uppercase letters.
int check_uppercase(char *password) {
  int count = 0;

  for (int i = 0; i < strlen(password); i++) {
    if (isupper(password[i])) {
      count++;
    }
  }

  if (count < MIN_UPPERCASE) {
    return -1;
  } else {
    return count;
  }
}

// Check for lowercase letters.
int check_lowercase(char *password) {
  int count = 0;

  for (int i = 0; i < strlen(password); i++) {
    if (islower(password[i])) {
      count++;
    }
  }

  if (count < MIN_LOWERCASE) {
    return -1;
  } else {
    return count;
  }
}

// Check for numbers.
int check_numbers(char *password) {
  int count = 0;

  for (int i = 0; i < strlen(password); i++) {
    if (isdigit(password[i])) {
      count++;
    }
  }

  if (count < MIN_NUMBERS) {
    return -1;
  } else {
    return count;
  }
}

// Check for symbols.
int check_symbols(char *password) {
  int count = 0;

  for (int i = 0; i < strlen(password); i++) {
    if (!isalnum(password[i])) {
      count++;
    }
  }

  if (count < MIN_SYMBOLS) {
    return -1;
  } else {
    return count;
  }
}

// Check for consecutive characters.
int check_consecutive(char *password) {
  for (int i = 0; i < strlen(password) - 1; i++) {
    if (password[i] == password[i + 1]) {
      return -1;
    }
  }

  return 0;
}

// Check for repeated characters.
int check_repeats(char *password) {
  for (int i = 0; i < strlen(password) - 3; i++) {
    if (password[i] == password[i + 1] && password[i] == password[i + 2] && password[i] == password[i + 3]) {
      return -1;
    }
  }

  return 0;
}

// Check for common dictionary words.
int check_dictionary(char *password) {
  FILE *fp;
  char line[128];
  const char *filename = "dictionary.txt";

  if ((fp = fopen(filename, "r")) == NULL) {
    printf("Error opening dictionary file!\n");
    return 0;
  }

  while (fgets(line, sizeof(line), fp)) {
    if (strcmp(line, password) == 0) {
      fclose(fp);
      return -1;
    }
  }

  fclose(fp);
  return 0;
}