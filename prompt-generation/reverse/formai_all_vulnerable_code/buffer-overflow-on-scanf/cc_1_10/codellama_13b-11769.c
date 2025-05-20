//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: high level of detail
// phone_book.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store phone book entries
typedef struct {
  char name[30];
  char number[15];
} Entry;

// Function to add a new entry to the phone book
void add_entry(Entry *phone_book, int *size) {
  // Ask for user input
  printf("Enter the name: ");
  scanf("%s", phone_book[*size].name);
  printf("Enter the number: ");
  scanf("%s", phone_book[*size].number);
  *size += 1;
}

// Function to search for an entry in the phone book
int search_entry(Entry *phone_book, int size, char *name) {
  // Loop through the phone book to find the entry
  for (int i = 0; i < size; i++) {
    if (strcmp(phone_book[i].name, name) == 0) {
      return i;
    }
  }
  // If the entry is not found, return -1
  return -1;
}

// Function to display all entries in the phone book
void display_all(Entry *phone_book, int size) {
  // Loop through the phone book and display each entry
  for (int i = 0; i < size; i++) {
    printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
  }
}

// Main function
int main() {
  // Initialize the phone book
  Entry phone_book[100];
  int size = 0;

  // Add some entries to the phone book
  add_entry(phone_book, &size);
  add_entry(phone_book, &size);
  add_entry(phone_book, &size);

  // Search for an entry in the phone book
  char name[30];
  printf("Enter the name to search for: ");
  scanf("%s", name);
  int index = search_entry(phone_book, size, name);
  if (index != -1) {
    printf("Found %s at index %d\n", name, index);
  } else {
    printf("Entry not found\n");
  }

  // Display all entries in the phone book
  display_all(phone_book, size);

  return 0;
}