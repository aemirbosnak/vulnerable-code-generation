//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool has_uppercase(char* password) {
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      return true;
    }
  }
  return false;
}

bool has_lowercase(char* password) {
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      return true;
    }
  }
  return false;
}

bool has_numeric(char* password) {
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      return true;
    }
  }
  return false;
}

bool has_specialchar(char* password) {
  char* special_chars = "!@#$%^&*()_-+=|\\{}[]:;\"'<>,.?/";
  for (int i = 0; i < strlen(password); i++) {
    for (int j = 0; j < strlen(special_chars); j++) {
      if (password[i] == special_chars[j]) {
        return true;
      }
    }
  }
  return false;
}

bool is_strong_password(char* password) {
  if (strlen(password) < 8) {
    return false;
  }
  if (!has_uppercase(password)) {
    return false;
  }
  if (!has_lowercase(password)) {
    return false;
  }
  if (!has_numeric(password)) {
    return false;
  }
  if (!has_specialchar(password)) {
    return false;
  }
  return true;
}

void display_results(char* password, bool is_strong) {
  printf("Your password: %s\n", password);
  if (is_strong) {
    printf("Congratulations! Your password is strong.\n");
  } else {
    printf("Sorry, your password is not strong enough. Please try again.\n");
  }
}

int main() {
  printf("Welcome to the Password Strength Checker\n");
  printf("Please enter your password: ");

  char password[100];
  scanf("%s", password);

  bool is_strong = is_strong_password(password);

  display_results(password, is_strong); 

  return 0;
}