//FormAI DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_ENTRIES 100

struct PhoneBookEntry {
  char name[MAX_NAME_LENGTH];
  char phonenumber[MAX_PHONE_NUMBER_LENGTH];
};

typedef struct PhoneBookEntry PhoneBookEntry;

PhoneBookEntry phonebook[MAX_ENTRIES];
int num_entries = 0;

void addEntry() {
  printf("Enter a name: ");
  fgets(phonebook[num_entries].name, MAX_NAME_LENGTH, stdin);
  phonebook[num_entries].name[strcspn(phonebook[num_entries].name, "\n")] = '\0';

  printf("Enter a phone number: ");
  fgets(phonebook[num_entries].phonenumber, MAX_PHONE_NUMBER_LENGTH, stdin);
  phonebook[num_entries].phonenumber[strcspn(phonebook[num_entries].phonenumber, "\n")] = '\0';

  num_entries++;
  printf("Entry added successfully!\n");
}

void listEntries() {
  if (num_entries == 0) {
    printf("There are no entries in the phonebook.\n");
    return;
  }

  printf("Name\t\tPhone Number\n");
  printf("-------------------------------------\n");

  for (int i = 0; i < num_entries; i++) {
    printf("%s\t\t%s\n", phonebook[i].name, phonebook[i].phonenumber);
  }
}

void searchEntry() {
  if (num_entries == 0) {
    printf("There are no entries in the phonebook.\n");
    return;
  }

  char query[MAX_NAME_LENGTH];
  printf("Enter a name to search for: ");
  fgets(query, MAX_NAME_LENGTH, stdin);
  query[strcspn(query, "\n")] = '\0';

  for (int i = 0; i < num_entries; i++) {
    if (strcmp(phonebook[i].name, query) == 0) {
      printf("%s's phone number is %s.\n", phonebook[i].name, phonebook[i].phonenumber);
      return;
    }
  }

  printf("Entry not found.\n");
}

int main() {
  int choice;

  do {
    printf("\nPHONEBOOK MENU\n");
    printf("1. Add entry\n");
    printf("2. List entries\n");
    printf("3. Search entry\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // clear stdin

    switch (choice) {
      case 1:
        addEntry();
        break;
      case 2:
        listEntries();
        break;
      case 3:
        searchEntry();
        break;
      case 4:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 4);

  return 0;
}