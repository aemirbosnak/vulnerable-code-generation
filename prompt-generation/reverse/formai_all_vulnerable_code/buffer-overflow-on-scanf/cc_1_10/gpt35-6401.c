//FormAI DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 100
#define PASSWORD_LENGTH 12
#define PASSWORD_DB_FILE "passwords.txt"

typedef struct {
  char website[MAX_LINE_LENGTH];
  char username[MAX_LINE_LENGTH];
  char password[PASSWORD_LENGTH];
} PasswordEntry;

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}

void printPasswordEntry(PasswordEntry entry) {
  printf("Website: %s\n", entry.website);
  printf("Username: %s\n", entry.username);
  printf("Password: %s\n", entry.password);
}

bool savePasswordEntryToFile(PasswordEntry entry) {
  FILE* fp = fopen(PASSWORD_DB_FILE, "a");
  if (fp == NULL) {
    return false;
  }

  fprintf(fp, "%s;%s;%s\n", entry.website, entry.username, entry.password);
  fclose(fp);
  return true;
}

void displayPasswordEntries() {
  FILE* fp = fopen(PASSWORD_DB_FILE, "r");
  if (fp == NULL) {
    printf("No passwords saved yet.\n");
    return;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    char* website = strtok(line, ";");
    char* username = strtok(NULL, ";");
    char* password = strtok(NULL, ";");

    PasswordEntry entry = {0};
    strcpy(entry.website, website);
    strcpy(entry.username, username);
    strcpy(entry.password, password);

    printPasswordEntry(entry);
  }

  fclose(fp);
}

void addNewPasswordEntry() {
  PasswordEntry entry = {0};
  printf("Enter website: ");
  fgets(entry.website, MAX_LINE_LENGTH, stdin);
  printf("Enter username: ");
  fgets(entry.username, MAX_LINE_LENGTH, stdin);

  char password1[PASSWORD_LENGTH] = {0};
  char password2[PASSWORD_LENGTH] = {0};
  do {
    printf("Enter password (at least 8 characters): ");
    fgets(password1, PASSWORD_LENGTH, stdin);
    printf("Enter password again: ");
    fgets(password2, PASSWORD_LENGTH, stdin);

    if (strcmp(password1, password2) != 0) {
      printf("Passwords do not match. Please try again.\n");
    }
  } while (strcmp(password1, password2) != 0);

  strncpy(entry.password, password1, strlen(password1) - 1);
  bool result = savePasswordEntryToFile(entry);
  if (result) {
    printf("Password saved successfully!\n");
  } else {
    printf("Failed to save password.\n");
  }
}

void printMenu() {
  printf("=====================\n");
  printf("PASSWORD MANAGER MENU:\n");
  printf("=====================\n");
  printf("1. Display existing passwords.\n");
  printf("2. Add a new password.\n");
  printf("3. Quit.\n");
}

int main() {
  char choice = '\0';

  while (choice != '3') {
    printMenu();
    printf("Enter your choice: ");
    scanf("%c", &choice);
    clearBuffer();

    switch (choice) {
      case '1':
        displayPasswordEntries();
        break;
      case '2':
        addNewPasswordEntry();
        break;
      case '3':
        printf("Goodbye.\n");
        break;
      default:
        printf("Invalid choice. Try again.\n");
        break;
    }
  }

  return 0;
}