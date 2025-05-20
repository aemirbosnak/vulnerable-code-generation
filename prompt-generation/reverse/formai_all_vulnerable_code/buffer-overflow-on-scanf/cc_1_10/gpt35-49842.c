//FormAI DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
/* C Phone Book Example Program in a Donald Knuth Style */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to store phone book entry */
typedef struct {
  char name[50];
  char phone_number[15];
} phone_book_entry;

/* Function to add an entry to the phone book */
void add_entry(phone_book_entry *book, int *count) {
  printf("\nEnter name: ");
  scanf("%s", book[*count].name);
  printf("Enter phone number: ");
  scanf("%s", book[*count].phone_number);
  (*count)++;
}

/* Function to search for an entry in the phone book */
void search_entry(phone_book_entry *book, int count) {
  char name[50];
  printf("\nEnter name to search for: ");
  scanf("%s", name);
  int found = 0;
  for (int i = 0; i < count; i++) {
    if (strcmp(name, book[i].name) == 0) {
      printf("\n%s's phone number is %s\n", book[i].name, book[i].phone_number);
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("\nEntry not found!\n");
  }
}

/* Function to print all entries in the phone book */
void print_entries(phone_book_entry *book, int count) {
  for (int i = 0; i < count; i++) {
    printf("%s - %s\n", book[i].name, book[i].phone_number);
  }
}

/* Main function */
int main() {
  phone_book_entry *book = (phone_book_entry *) malloc(sizeof(phone_book_entry));
  int count = 0;
  while (1) {
    printf("\nMenu:\n");
    printf("1. Add an entry\n");
    printf("2. Search for an entry\n");
    printf("3. Print all entries\n");
    printf("4. Quit\n");
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_entry(book, &count);
        break;
      case 2:
        search_entry(book, count);
        break;
      case 3:
        print_entries(book, count);
        break;
      case 4:
        free(book);
        printf("\nGoodbye!\n");
        exit(0);
        break;
      default:
        printf("\nInvalid choice!\n");
    }
  }
  return 0;
}