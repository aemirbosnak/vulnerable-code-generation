//FormAI DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 20

struct password_entry {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
};

void print_passwords(struct password_entry passwords[], int count);
void add_password(struct password_entry passwords[], int count);
void delete_password(struct password_entry passwords[], int count);

int main() {
  struct password_entry passwords[1000];
  int count = 0;
  char choice;

  printf("Welcome to your password manager!\n");

  while (1) {
    printf("\nEnter an option:\n");
    printf("  1. List passwords\n");
    printf("  2. Add a password\n");
    printf("  3. Delete a password\n");
    printf("  4. Quit\n");
    printf("> ");

    scanf(" %c", &choice);

    switch (choice) {
      case '1':
        print_passwords(passwords, count);
        break;
      case '2':
        add_password(passwords, count);
        count++;
        break;
      case '3':
        delete_password(passwords, count);
        count--;
        break;
      case '4':
        return 0;
      default:
        printf("Invalid option.\n");
        break;
    }
  }
}

void print_passwords(struct password_entry passwords[], int count) {
  if (count == 0) {
    printf("No passwords stored yet.\n");
    return;
  }

  printf("\nYour stored passwords:\n");
  for (int i = 0; i < count; i++) {
    printf("  %s: %s\n", passwords[i].username, passwords[i].password);
  }
}

void add_password(struct password_entry passwords[], int count) {
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];

  printf("Enter the username: ");
  scanf("%s", username);

  printf("Enter the password: ");
  scanf("%s", password);

  struct password_entry new_entry;
  strcpy(new_entry.username, username);
  strcpy(new_entry.password, password);
  passwords[count] = new_entry;

  printf("Password added successfully!\n");
}

void delete_password(struct password_entry passwords[], int count) {
  char username[MAX_USERNAME_LENGTH];

  if (count == 0) {
    printf("No passwords stored yet.\n");
    return;
  }

  printf("Enter the username to delete: ");
  scanf("%s", username);

  for (int i = 0; i < count; i++) {
    if (strcmp(passwords[i].username, username) == 0) {
      for (int j = i; j < count - 1; j++) {
        passwords[j] = passwords[j+1];
      }

      printf("Password deleted successfully!\n");
      return;
    }
  }

  printf("Username not found!\n");
}