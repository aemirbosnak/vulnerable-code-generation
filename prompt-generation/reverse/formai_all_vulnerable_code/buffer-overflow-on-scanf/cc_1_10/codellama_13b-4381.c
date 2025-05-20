//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if a character is a letter
int is_letter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// function to check if a character is a number
int is_number(char c) {
  return (c >= '0' && c <= '9');
}

// function to check if a character is a special character
int is_special(char c) {
  return (c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '~');
}

// function to check if a password is strong
int is_strong(char *password) {
  int is_strong = 0;
  int len = strlen(password);
  int has_letter = 0;
  int has_number = 0;
  int has_special = 0;
  for (int i = 0; i < len; i++) {
    if (is_letter(password[i])) {
      has_letter = 1;
    } else if (is_number(password[i])) {
      has_number = 1;
    } else if (is_special(password[i])) {
      has_special = 1;
    }
  }
  if (has_letter && has_number && has_special) {
    is_strong = 1;
  }
  return is_strong;
}

// function to check if a password is weak
int is_weak(char *password) {
  int is_weak = 0;
  int len = strlen(password);
  int has_letter = 0;
  int has_number = 0;
  int has_special = 0;
  for (int i = 0; i < len; i++) {
    if (is_letter(password[i])) {
      has_letter = 1;
    } else if (is_number(password[i])) {
      has_number = 1;
    } else if (is_special(password[i])) {
      has_special = 1;
    }
  }
  if (!has_letter || !has_number || !has_special) {
    is_weak = 1;
  }
  return is_weak;
}

// main function
int main() {
  char password[100];
  printf("Enter password: ");
  scanf("%s", password);
  if (is_strong(password)) {
    printf("Strong password\n");
  } else if (is_weak(password)) {
    printf("Weak password\n");
  } else {
    printf("Invalid password\n");
  }
  return 0;
}