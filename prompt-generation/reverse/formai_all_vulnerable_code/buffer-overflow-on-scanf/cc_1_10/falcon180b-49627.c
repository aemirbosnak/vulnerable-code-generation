//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15

// Struct for a phonebook entry
typedef struct {
  char name[MAX_NAME_LEN];
  char number[MAX_NUMBER_LEN];
} PhonebookEntry;

// Function to add an entry to the phonebook
void add_entry(PhonebookEntry* entries, int* num_entries) {
  printf("Enter name: ");
  scanf("%s", entries[*num_entries].name);
  printf("Enter number: ");
  scanf("%s", entries[*num_entries].number);
  (*num_entries)++;
}

// Function to search for an entry in the phonebook
int search_entry(PhonebookEntry* entries, int num_entries, char* name) {
  for (int i = 0; i < num_entries; i++) {
    if (strcmp(entries[i].name, name) == 0) {
      printf("%s: %s\n", entries[i].name, entries[i].number);
      return i;
    }
  }
  return -1;
}

// Function to delete an entry from the phonebook
void delete_entry(PhonebookEntry* entries, int* num_entries, int index) {
  for (int i = index; i < (*num_entries) - 1; i++) {
    strcpy(entries[i].name, entries[i+1].name);
    strcpy(entries[i].number, entries[i+1].number);
  }
  (*num_entries)--;
}

// Function to display all entries in the phonebook
void display_entries(PhonebookEntry* entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    printf("%s: %s\n", entries[i].name, entries[i].number);
  }
}

int main() {
  PhonebookEntry entries[MAX_ENTRIES];
  int num_entries = 0;

  // Initialize phonebook with sample entries
  add_entry(entries, &num_entries);
  add_entry(entries, &num_entries);
  add_entry(entries, &num_entries);

  // Display all entries
  printf("Phonebook:\n");
  display_entries(entries, num_entries);

  // Search for an entry
  char name[MAX_NAME_LEN];
  int index = search_entry(entries, num_entries, name);
  if (index!= -1) {
    printf("\n%s found at index %d:\n", name, index);
  } else {
    printf("\n%s not found.\n", name);
  }

  // Delete an entry
  int entry_index = 1; // Index of the entry to delete
  delete_entry(entries, &num_entries, entry_index);

  // Display updated phonebook
  printf("\nPhonebook after deletion:\n");
  display_entries(entries, num_entries);

  return 0;
}