//Gemma-7B DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 255

typedef struct Password {
  char *name;
  char *password;
  int valid;
} Password;

int main() {
  Password passwords[MAX_PASSWORDS] = {0};
  int i = 0;
  char input[MAX_PASSWORD_LENGTH] = "";

  // Create a new password
  passwords[i].name = "my_new_password";
  passwords[i].password = "StrongPassword12!";
  passwords[i].valid = 1;
  i++;

  // Display all passwords
  for (int j = 0; j < i; j++) {
    if (passwords[j].valid) {
      printf("Name: %s, Password: %s\n", passwords[j].name, passwords[j].password);
    }
  }

  // Get the input password
  printf("Enter a password: ");
  scanf("%s", input);

  // Compare the input password with the stored passwords
  for (int j = 0; j < i; j++) {
    if (passwords[j].valid && strcmp(input, passwords[j].password) == 0) {
      printf("Password found!\n");
      passwords[j].valid = 0;
      break;
    }
  }

  // Display the remaining passwords
  for (int j = 0; j < i; j++) {
    if (passwords[j].valid) {
      printf("Name: %s, Password: %s\n", passwords[j].name, passwords[j].password);
    }
  }

  return 0;
}