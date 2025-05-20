//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: brave
/*
 * Brave Phone Book
 *
 * A simple phone book program that allows users to store and search for names and numbers.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 256
#define MAX_NUMBER_LENGTH 32
#define MAX_PHONEBOOK_SIZE 100

typedef struct {
  char name[MAX_NAME_LENGTH];
  char number[MAX_NUMBER_LENGTH];
} phone_book_entry_t;

void print_phone_book(phone_book_entry_t phone_book[], int size);
void add_phone_book_entry(phone_book_entry_t phone_book[], int *size);
void search_phone_book(phone_book_entry_t phone_book[], int size);

int main() {
  phone_book_entry_t phone_book[MAX_PHONEBOOK_SIZE];
  int size = 0;

  // Main menu
  while (1) {
    printf("Phone Book Menu\n");
    printf("1. Add a new entry\n");
    printf("2. Search for an entry\n");
    printf("3. Print the phone book\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      add_phone_book_entry(phone_book, &size);
      break;
    case 2:
      search_phone_book(phone_book, size);
      break;
    case 3:
      print_phone_book(phone_book, size);
      break;
    case 4:
      return 0;
    default:
      printf("Invalid choice\n");
      break;
    }
  }

  return 0;
}

void print_phone_book(phone_book_entry_t phone_book[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
  }
}

void add_phone_book_entry(phone_book_entry_t phone_book[], int *size) {
  if (*size >= MAX_PHONEBOOK_SIZE) {
    printf("Phone book is full\n");
    return;
  }

  printf("Enter the name: ");
  scanf("%s", phone_book[*size].name);

  printf("Enter the number: ");
  scanf("%s", phone_book[*size].number);

  (*size)++;
}

void search_phone_book(phone_book_entry_t phone_book[], int size) {
  printf("Enter the name to search for: ");
  char name[MAX_NAME_LENGTH];
  scanf("%s", name);

  for (int i = 0; i < size; i++) {
    if (strcmp(name, phone_book[i].name) == 0) {
      printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
      return;
    }
  }

  printf("Name not found\n");
}