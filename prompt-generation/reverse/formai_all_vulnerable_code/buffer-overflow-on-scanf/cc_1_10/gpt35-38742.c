//FormAI DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_ENTRIES 100

// Define the structure for each phone book entry
typedef struct {
  char name[MAX_NAME_LENGTH];
  char phone[MAX_PHONE_LENGTH];
} PhoneEntry;

// Define the phone book as an array of PhoneEntries and a count of the number of entries
PhoneEntry phoneBook[MAX_ENTRIES];
int numEntries = 0;

// Function to add a new entry to the phone book
void addEntry() {
  PhoneEntry entry;
  printf("Enter name: ");
  fgets(entry.name, MAX_NAME_LENGTH, stdin);
  printf("Enter phone number: ");
  fgets(entry.phone, MAX_PHONE_LENGTH, stdin);
  phoneBook[numEntries] = entry;
  numEntries++;
}

// Function to display all entries in the phone book
void displayEntries() {
  if (numEntries == 0) {
    printf("No entries.\n");
  } else {
    printf("Phone Book Entries:\n");
    for (int i = 0; i < numEntries; i++) {
      printf("%s: %s", phoneBook[i].name, phoneBook[i].phone);
    }
  }
}

// Main function to display a menu and allow the user to interact with the phone book
int main() {
  char choice;
  do {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    getchar(); // consume the newline character
    switch (choice) {
      case '1':
        addEntry();
        break;
      case '2':
        displayEntries();
        break;
      case '3':
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  } while (choice != '3');
  return 0;
}