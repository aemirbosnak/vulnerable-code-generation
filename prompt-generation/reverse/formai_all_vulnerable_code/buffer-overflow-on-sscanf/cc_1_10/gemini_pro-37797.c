//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 20
#define MAX_NUMBER_LENGTH 15
#define MAX_PHONE_BOOK_SIZE 100

typedef struct {
  char name[MAX_NAME_LENGTH];
  char number[MAX_NUMBER_LENGTH];
} phone_book_entry;

int compare_phone_book_entries(const void *a, const void *b) {
  const phone_book_entry *entry1 = (const phone_book_entry *)a;
  const phone_book_entry *entry2 = (const phone_book_entry *)b;
  return strcmp(entry1->name, entry2->name);
}

int main(void) {
  phone_book_entry phone_book[MAX_PHONE_BOOK_SIZE];
  int phone_book_size = 0;
  char input[100];
  int choice;
  int i;

  printf("Welcome to the Phone Book!\n");

  while (1) {
    printf("1. Add a new entry\n");
    printf("2. List all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Delete an entry\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");

    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &choice);

    switch (choice) {
      case 1:
        if (phone_book_size == MAX_PHONE_BOOK_SIZE) {
          printf("Phone book is full!\n");
        } else {
          printf("Enter name: ");
          fgets(input, sizeof(input), stdin);
          sscanf(input, "%s", phone_book[phone_book_size].name);

          printf("Enter number: ");
          fgets(input, sizeof(input), stdin);
          sscanf(input, "%s", phone_book[phone_book_size].number);

          phone_book_size++;
        }
        break;

      case 2:
        if (phone_book_size == 0) {
          printf("Phone book is empty!\n");
        } else {
          qsort(phone_book, phone_book_size, sizeof(phone_book_entry), compare_phone_book_entries);

          for (i = 0; i < phone_book_size; i++) {
            printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
          }
        }
        break;

      case 3:
        if (phone_book_size == 0) {
          printf("Phone book is empty!\n");
        } else {
          printf("Enter name to search for: ");
          fgets(input, sizeof(input), stdin);
          sscanf(input, "%s", input);

          for (i = 0; i < phone_book_size; i++) {
            if (strcmp(phone_book[i].name, input) == 0) {
              printf("Found entry: %s: %s\n", phone_book[i].name, phone_book[i].number);
              break;
            }
          }

          if (i == phone_book_size) {
            printf("Entry not found!\n");
          }
        }
        break;

      case 4:
        if (phone_book_size == 0) {
          printf("Phone book is empty!\n");
        } else {
          printf("Enter name to delete: ");
          fgets(input, sizeof(input), stdin);
          sscanf(input, "%s", input);

          for (i = 0; i < phone_book_size; i++) {
            if (strcmp(phone_book[i].name, input) == 0) {
              phone_book[i] = phone_book[phone_book_size - 1];
              phone_book_size--;
              break;
            }
          }

          if (i == phone_book_size) {
            printf("Entry not found!\n");
          } else {
            printf("Entry deleted!\n");
          }
        }
        break;

      case 5:
        exit(0);

      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}