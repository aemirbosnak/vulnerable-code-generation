//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a phone book entry
typedef struct {
  char name[32];
  char number[32];
} PhoneBookEntry;

// Function to add a new entry to the phone book
void add_entry(PhoneBookEntry *phone_book, int size) {
  int index;
  printf("Enter the name of the person: ");
  scanf("%s", phone_book[size].name);
  printf("Enter the phone number: ");
  scanf("%s", phone_book[size].number);
}

// Function to search for an entry in the phone book
int search_entry(PhoneBookEntry *phone_book, int size, char *name) {
  for (int i = 0; i < size; i++) {
    if (strcmp(phone_book[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to delete an entry from the phone book
void delete_entry(PhoneBookEntry *phone_book, int size, int index) {
  for (int i = index; i < size - 1; i++) {
    phone_book[i] = phone_book[i + 1];
  }
  size--;
}

// Function to display all entries in the phone book
void display_all_entries(PhoneBookEntry *phone_book, int size) {
  for (int i = 0; i < size; i++) {
    printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
  }
}

// Function to display a specific entry in the phone book
void display_entry(PhoneBookEntry *phone_book, int size, char *name) {
  int index = search_entry(phone_book, size, name);
  if (index != -1) {
    printf("%s: %s\n", phone_book[index].name, phone_book[index].number);
  } else {
    printf("No entry found with that name.\n");
  }
}

// Main function
int main() {
  // Initialize the phone book
  PhoneBookEntry phone_book[10];
  int size = 0;

  // Add some initial entries
  add_entry(phone_book, size++);
  add_entry(phone_book, size++);

  // Search for an entry
  char name[32];
  printf("Enter the name to search for: ");
  scanf("%s", name);
  int index = search_entry(phone_book, size, name);
  if (index != -1) {
    printf("Entry found at index %d\n", index);
  } else {
    printf("No entry found with that name.\n");
  }

  // Delete an entry
  printf("Enter the name of the person to delete: ");
  scanf("%s", name);
  index = search_entry(phone_book, size, name);
  if (index != -1) {
    delete_entry(phone_book, size, index);
    printf("Entry deleted successfully.\n");
  } else {
    printf("No entry found with that name.\n");
  }

  // Display all entries
  printf("Displaying all entries:\n");
  display_all_entries(phone_book, size);

  // Display a specific entry
  printf("Enter the name to search for: ");
  scanf("%s", name);
  display_entry(phone_book, size, name);

  return 0;
}