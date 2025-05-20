//FormAI DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBookEntry {
  char firstName[50];
  char lastName[50];
  char phoneNumber[20];
};

void addEntry() {
  // Allocate memory for a new entry
  struct PhoneBookEntry* newEntry = (struct PhoneBookEntry*) malloc(sizeof(struct PhoneBookEntry));

  // Prompt user for input
  printf("Enter first name: ");
  scanf("%s", newEntry->firstName);

  printf("Enter last name: ");
  scanf("%s", newEntry->lastName);

  printf("Enter phone number: ");
  scanf("%s", newEntry->phoneNumber);

  // Save entry to file
  FILE* fp = fopen("phonebook.dat", "ab");
  fwrite(newEntry, sizeof(struct PhoneBookEntry), 1, fp);
  fclose(fp);

  printf("Entry added successfully!\n");

  free(newEntry);
}

void search() {
  char searchKey[50];
  printf("Enter search term: ");
  scanf("%s", searchKey);

  // Open file
  FILE* fp = fopen("phonebook.dat", "rb");
  if (fp == NULL) {
    printf("Error: could not open file.\n");
    return;
  }

  int found = 0;

  // Loop through all entries in file
  while (!feof(fp)) {
    struct PhoneBookEntry* entry = (struct PhoneBookEntry*) malloc(sizeof(struct PhoneBookEntry));
    fread(entry, sizeof(struct PhoneBookEntry), 1, fp);

    if (strcmp(entry->firstName, searchKey) == 0 ||
        strcmp(entry->lastName, searchKey) == 0 ||
        strcmp(entry->phoneNumber, searchKey) == 0) {
      printf("%s %s - %s\n", entry->firstName, entry->lastName, entry->phoneNumber);
      found = 1;
    }

    free(entry);
  }

  // Close file
  fclose(fp);

  if (!found) {
    printf("No entries found.\n");
  }
}

int main() {
  int choice;

  do {
    printf("Phone Book\n");
    printf("----------------\n");
    printf("1. Add entry\n");
    printf("2. Search\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addEntry();
        break;
      case 2:
        search();
        break;
      case 3:
        printf("Goodbye.\n");
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }

    printf("\n");
  } while (choice != 3);

  return 0;
}