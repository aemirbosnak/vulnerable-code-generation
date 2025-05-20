//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store phone book entry
struct phone_book_entry {
  char name[30];
  char phone_number[15];
};

// Function to add a new entry to the phone book
void add_entry(struct phone_book_entry* phone_book, int size) {
  char name[30];
  char phone_number[15];

  printf("Enter the name: ");
  scanf("%s", name);

  printf("Enter the phone number: ");
  scanf("%s", phone_number);

  // Add the new entry to the phone book
  strcpy(phone_book[size].name, name);
  strcpy(phone_book[size].phone_number, phone_number);

  size++;
}

// Function to search for an entry in the phone book
void search_entry(struct phone_book_entry* phone_book, int size) {
  char name[30];

  printf("Enter the name to search for: ");
  scanf("%s", name);

  // Search for the entry in the phone book
  for (int i = 0; i < size; i++) {
    if (strcmp(phone_book[i].name, name) == 0) {
      printf("Phone number: %s\n", phone_book[i].phone_number);
      return;
    }
  }

  printf("Entry not found.\n");
}

int main() {
  struct phone_book_entry phone_book[100];
  int size = 0;

  // Add some entries to the phone book
  add_entry(phone_book, size);
  add_entry(phone_book, size);
  add_entry(phone_book, size);

  // Search for an entry in the phone book
  search_entry(phone_book, size);

  return 0;
}