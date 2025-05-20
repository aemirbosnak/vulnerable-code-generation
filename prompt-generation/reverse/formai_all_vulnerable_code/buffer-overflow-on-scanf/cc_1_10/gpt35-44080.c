//FormAI DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_STRING_LEN 100

typedef struct {
  char account_name[MAX_STRING_LEN];
  char username[MAX_STRING_LEN];
  char password[MAX_STRING_LEN];
} Credentials;

int menu();
void add_password(Credentials passwords[], int *num_passwords);
void view_passwords(Credentials passwords[], int num_passwords);
void encrypt(char *string, int shift);
void decrypt(char *string, int shift);

int main() {
  Credentials passwords[MAX_PASSWORDS];
  int num_passwords = 0;
  int choice;

  do {
    choice = menu();

    switch (choice) {
      case 1: add_password(passwords, &num_passwords); break;
      case 2: view_passwords(passwords, num_passwords); break;
      case 3: printf("Exiting program..."); break;
      default: printf("Invalid option, please try again."); break;
    }

    printf("\n");

  } while (choice != 3);

  return 0;
}

int menu() {
  int choice;

  printf("Password Management System\n");
  printf("1. Add a Password\n");
  printf("2. View Passwords\n");
  printf("3. Exit Program\n");
  printf("Enter choice: ");
  scanf("%d", &choice);

  return choice;
}

void add_password(Credentials passwords[], int *num_passwords) {
  Credentials new_credentials;

  printf("Adding a new password\n");

  printf("Account name: ");
  scanf("%s", new_credentials.account_name);

  printf("Username: ");
  scanf("%s", new_credentials.username);

  printf("Password: ");
  scanf("%s", new_credentials.password);

  encrypt(new_credentials.password, 5);

  passwords[*num_passwords] = new_credentials;
  *num_passwords += 1;
}

void view_passwords(Credentials passwords[], int num_passwords) {
  int i;

  printf("Viewing passwords:\n");

  for (i = 0; i < num_passwords; i++) {
    printf("Account name: %s\n", passwords[i].account_name);
    printf("Username: %s\n", passwords[i].username);
    printf("Password: ");
    decrypt(passwords[i].password, 5);
    printf("%s\n", passwords[i].password);
  }
}

void encrypt(char *string, int shift) {
  int i;

  for (i = 0; i < strlen(string); i++) {
    if (string[i] >= 'a' && string[i] <= 'z') {
      string[i] = ((string[i] - 'a') + shift) % 26 + 'a';
    } else if (string[i] >= 'A' && string[i] <= 'Z') {
      string[i] = ((string[i] - 'A') + shift) % 26 + 'A';
    }
  }
}

void decrypt(char *string, int shift) {
  int i;

  for (i = 0; i < strlen(string); i++) {
    if (string[i] >= 'a' && string[i] <= 'z') {
      string[i] = ((string[i] - 'a') - shift + 26) % 26 + 'a';
    } else if (string[i] >= 'A' && string[i] <= 'Z') {
      string[i] = ((string[i] - 'A') - shift + 26) % 26 + 'A';
    }
  }
}