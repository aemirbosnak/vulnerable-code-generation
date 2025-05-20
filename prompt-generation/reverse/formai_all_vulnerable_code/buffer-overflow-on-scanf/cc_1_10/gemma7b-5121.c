//Gemma-7B DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

char passwords[MAX_PASSWORDS][PASSWORD_LENGTH];

void generate_password() {
  char password[PASSWORD_LENGTH];
  int i;

  for (i = 0; i < PASSWORD_LENGTH; i++) {
    password[i] = rand() % 26 + 'a';
  }

  strcpy(passwords[0], password);
}

void store_password() {
  generate_password();

  printf("Enter your new password: ");
  scanf("%s", passwords[0]);

  printf("Your password is: %s\n", passwords[0]);
}

void verify_password() {
  char input_password[PASSWORD_LENGTH];

  printf("Enter your password: ");
  scanf("%s", input_password);

  if (strcmp(input_password, passwords[0]) == 0) {
    printf("Password verified!\n");
  } else {
    printf("Incorrect password.\n");
  }
}

int main() {
  int choice;

  printf("Welcome to the ultraprecise password management system!\n");

  while (1) {
    printf("Please select an option:\n");
    printf("1. Store password\n");
    printf("2. Verify password\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        store_password();
        break;
      case 2:
        verify_password();
        break;
      case 3:
        exit(0);
    }
  }

  return 0;
}