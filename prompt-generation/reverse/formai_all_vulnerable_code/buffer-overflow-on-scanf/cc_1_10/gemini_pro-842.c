//GEMINI-pro DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
int num_passwords = 0;

void add_password(char *password) {
  if (num_passwords >= MAX_PASSWORDS) {
    printf("Error: Password list is full.\n");
    return;
  }

  strcpy(passwords[num_passwords], password);
  num_passwords++;
}

int find_password(char *password) {
  for (int i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i], password) == 0) {
      return i;
    }
  }

  return -1;
}

void remove_password(char *password) {
  int index = find_password(password);

  if (index == -1) {
    printf("Error: Password not found.\n");
    return;
  }

  for (int i = index; i < num_passwords - 1; i++) {
    strcpy(passwords[i], passwords[i + 1]);
  }

  num_passwords--;
}

void print_passwords() {
  for (int i = 0; i < num_passwords; i++) {
    printf("%s\n", passwords[i]);
  }
}

int main() {
  char input[MAX_PASSWORD_LENGTH];
  int choice;

  while (1) {
    printf("\nPassword Manager\n");
    printf("1. Add password\n");
    printf("2. Find password\n");
    printf("3. Remove password\n");
    printf("4. Print passwords\n");
    printf("5. Quit\n");
    printf("\nEnter your choice: ");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter password to add: ");
        scanf("%s", input);
        add_password(input);
        break;
      case 2:
        printf("Enter password to find: ");
        scanf("%s", input);
        int index = find_password(input);
        if (index == -1) {
          printf("Password not found.\n");
        } else {
          printf("Password found at index %d.\n", index);
        }
        break;
      case 3:
        printf("Enter password to remove: ");
        scanf("%s", input);
        remove_password(input);
        break;
      case 4:
        print_passwords();
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}