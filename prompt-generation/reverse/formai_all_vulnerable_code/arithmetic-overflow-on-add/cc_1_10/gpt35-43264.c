//FormAI DATASET v1.0 Category: Password management ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 256

bool validatePassword(char *password);
void encrypt(char *password, int key);
void decrypt(char *password, int key);

int main(void) {
  char password[MAX_LENGTH] = "";
  int key;

  printf("Enter a password to store securely: ");
  fgets(password, MAX_LENGTH, stdin);

  if (!validatePassword(password)) {
    printf("Invalid password format. Password must contain at least one uppercase letter, one lowercase letter, one digit, and a special character.\n");
    return 1;
  }

  printf("Enter an encryption key: ");
  scanf("%d", &key);

  encrypt(password, key);
  printf("Your encrypted password is: %s\n", password);

  decrypt(password, key);
  printf("Your decrypted password is: %s\n", password);

  return 0;
}

bool validatePassword(char *password) {
  int length = strlen(password);
  bool has_uppercase = false;
  bool has_lowercase = false;
  bool has_digit = false;
  bool has_special = false;

  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = true;
    } else if (password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = true;
    } else if (password[i] >= '0' && password[i] <= '9') {
      has_digit = true;
    } else {
      has_special = true;
    }
  }

  return has_uppercase && has_lowercase && has_digit && has_special;
}

void encrypt(char *password, int key) {
  int length = strlen(password);

  for (int i = 0; i < length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      password[i] = ((password[i] - 'A' + key) % 26) + 'A';
    } else if (password[i] >= 'a' && password[i] <= 'z') {
      password[i] = ((password[i] - 'a' + key) % 26) + 'a';
    } else if (password[i] >= '0' && password[i] <= '9') {
      password[i] = ((password[i] - '0' + key) % 10) + '0';
    } else {
      password[i] += key;
    }
  }
}

void decrypt(char *password, int key) {
  encrypt(password, 26 - key);
}