//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Structure to store phone book entry
struct PhoneBookEntry {
  char name[50];
  char phoneNumber[15];
};

// Function to add a new entry to the phone book
void addEntry(struct PhoneBookEntry* phoneBook, int index) {
  printf("Enter name: ");
  scanf("%s", phoneBook[index].name);
  printf("Enter phone number: ");
  scanf("%s", phoneBook[index].phoneNumber);
}

// Function to search for an entry in the phone book
void searchEntry(struct PhoneBookEntry* phoneBook, int size, char* name) {
  for (int i = 0; i < size; i++) {
    if (strcmp(phoneBook[i].name, name) == 0) {
      printf("Phone number of %s: %s\n", name, phoneBook[i].phoneNumber);
      return;
    }
  }
  printf("Entry not found.\n");
}

// Function to print all entries in the phone book
void printEntries(struct PhoneBookEntry* phoneBook, int size) {
  for (int i = 0; i < size; i++) {
    printf("%s: %s\n", phoneBook[i].name, phoneBook[i].phoneNumber);
  }
}

int main() {
  // Initialize phone book with 10 entries
  struct PhoneBookEntry phoneBook[10];

  // Add new entries to the phone book
  for (int i = 0; i < 10; i++) {
    addEntry(phoneBook, i);
  }

  // Search for an entry in the phone book
  char name[50];
  printf("Enter name to search: ");
  scanf("%s", name);
  searchEntry(phoneBook, 10, name);

  // Print all entries in the phone book
  printEntries(phoneBook, 10);

  return 0;
}