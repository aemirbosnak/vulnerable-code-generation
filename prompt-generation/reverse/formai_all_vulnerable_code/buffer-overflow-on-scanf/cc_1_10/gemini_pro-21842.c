//GEMINI-pro DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct password_entry {
  char website[MAX_PASSWORD_LENGTH];
  char username[MAX_PASSWORD_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
} password_entry;

int num_passwords = 0;
password_entry passwords[MAX_PASSWORDS];

void add_password(char *website, char *username, char *password) {
  if (num_passwords >= MAX_PASSWORDS) {
    printf("Error: Password database is full.\n");
    return;
  }

  strcpy(passwords[num_passwords].website, website);
  strcpy(passwords[num_passwords].username, username);
  strcpy(passwords[num_passwords].password, password);

  num_passwords++;
}

void list_passwords() {
  for (int i = 0; i < num_passwords; i++) {
    printf("%d. %s\n", i + 1, passwords[i].website);
  }
}

void search_password(char *website) {
  for (int i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i].website, website) == 0) {
      printf("Website: %s\n", passwords[i].website);
      printf("Username: %s\n", passwords[i].username);
      printf("Password: %s\n", passwords[i].password);
      return;
    }
  }

  printf("Error: Website not found.\n");
}

void delete_password(int index) {
  if (index < 0 || index >= num_passwords) {
    printf("Error: Invalid index.\n");
    return;
  }

  for (int i = index; i < num_passwords - 1; i++) {
    passwords[i] = passwords[i + 1];
  }

  num_passwords--;
}

int main() {
  int choice;
  char website[MAX_PASSWORD_LENGTH];
  char username[MAX_PASSWORD_LENGTH];
  char password[MAX_PASSWORD_LENGTH];
  int index;

  while (1) {
    printf("\nPassword Management System\n");
    printf("1. Add password\n");
    printf("2. List passwords\n");
    printf("3. Search password\n");
    printf("4. Delete password\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter website: ");
        scanf(" %[^\n]s", website);
        printf("Enter username: ");
        scanf(" %[^\n]s", username);
        printf("Enter password: ");
        scanf(" %[^\n]s", password);
        add_password(website, username, password);
        break;
      case 2:
        list_passwords();
        break;
      case 3:
        printf("Enter website: ");
        scanf(" %[^\n]s", website);
        search_password(website);
        break;
      case 4:
        printf("Enter index of password to delete: ");
        scanf("%d", &index);
        delete_password(index);
        break;
      case 5:
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}