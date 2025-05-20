//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: secure
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  char password[256];
  char strength[20] = "Weak";

  printf("Enter password: ");
  scanf("%s", password);

  if (strlen(password) >= 8) {
    strength[0] = 'M';
  }
  if (hasUppercase(password)) {
    strength[1] = 'H';
  }
  if (hasNumber(password)) {
    strength[2] = 'G';
  }
  if (hasSymbol(password)) {
    strength[3] = 'F';
  }

  printf("Password strength: %s\n", strength);

  return 0;
}

int hasUppercase(char *password) {
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      return 1;
    }
  }
  return 0;
}

int hasNumber(char *password) {
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      return 1;
    }
  }
  return 0;
}

int hasSymbol(char *password) {
  for (int i = 0; password[i] != '\0'; i++) {
    if (password[i] >= '!' && password[i] <= '~') {
      return 1;
    }
  }
  return 0;
}