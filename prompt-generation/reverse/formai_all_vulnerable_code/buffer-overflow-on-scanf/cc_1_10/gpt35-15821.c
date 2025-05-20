//FormAI DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PasswordEntry {
  char service_name[50];
  char username[50];
  char password[50];
};

// Function to print a PasswordEntry struct
void print_entry(struct PasswordEntry entry) {
  printf("\nService Name: %s\n", entry.service_name);
  printf("Username: %s\n", entry.username);
  printf("Password: %s\n", entry.password);
}

// Function to save a new password entry to a file
void save_entry(struct PasswordEntry entry) {
  FILE *file;
  file = fopen("passwords.txt", "a");
  if (file == NULL) {
    printf("Error: Unable to open file for writing\n");
    return;
  }
  fprintf(file, "%s,%s,%s\n", entry.service_name, entry.username, entry.password);
  printf("Password entry saved successfully!\n");
  fclose(file);
}

// Function to read all password entries from a file
void read_entries() {
  FILE *file;
  file = fopen("passwords.txt", "r");
  if (file == NULL) {
    printf("Error: Unable to open file for reading\n");
    return;
  }
  printf("\n---- Password Entries ----\n");
  struct PasswordEntry entry;
  char line[150];
  while (fgets(line, 150, file)) {
    sscanf(line, "%[^,],%[^,],%s", entry.service_name, entry.username, entry.password);
    print_entry(entry);
  }
  printf("------------------------\n");
  fclose(file);
}

// Function to search for a password entry by service name
void search_entry(char *service_name) {
  FILE *file;
  file = fopen("passwords.txt", "r");
  if (file == NULL) {
    printf("Error: Unable to open file for reading\n");
    return;
  }
  struct PasswordEntry entry;
  char line[150];
  while (fgets(line, 150, file)) {
    sscanf(line, "%[^,],%[^,],%s", entry.service_name, entry.username, entry.password);
    if (strcmp(entry.service_name, service_name) == 0) {
      print_entry(entry);
      fclose(file);
      return;
    }
  }
  printf("No password entry found for %s\n", service_name);
  fclose(file);
}

int main() {
  int option = 0;
  while (option != 4) {
    printf("\nPassword Manager 1.0\n\n");
    printf("1 - Add a password entry\n");
    printf("2 - List all password entries\n");
    printf("3 - Search for a password entry\n");
    printf("4 - Quit\n\n");
    printf("Enter an option: ");
    scanf("%d", &option);
    switch(option) {
      case 1: {
        struct PasswordEntry new_entry;
        printf("\nEnter Service Name: ");
        scanf("%s", new_entry.service_name);
        printf("Enter Username: ");
        scanf("%s", new_entry.username);
        printf("Enter Password: ");
        scanf("%s", new_entry.password);
        save_entry(new_entry);
        break;
      }
      case 2: {
        read_entries();
        break;
      }
      case 3: {
        char service_name[50];
        printf("\nEnter Service Name: ");
        scanf("%s", service_name);
        search_entry(service_name);
        break;
      }
      case 4: {
        printf("\nExiting Password Manager 1.0...\n");
        break;
      }
      default: {
        printf("\nInvalid option. Please try again.\n");
        break;
      }
    }
  }
  return 0;
}