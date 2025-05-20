//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
// Donald Knuth's Phone Book Program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 30
#define MAX_PHONE_LENGTH 15

typedef struct {
  char name[MAX_NAME_LENGTH];
  char phone[MAX_PHONE_LENGTH];
} Entry;

void print_menu() {
  printf("Welcome to the Phone Book Program\n");
  printf("1. Add an entry\n");
  printf("2. Find an entry\n");
  printf("3. Delete an entry\n");
  printf("4. Print the phone book\n");
  printf("5. Quit\n");
}

void add_entry(Entry *phone_book, int *num_entries) {
  printf("Enter the name: ");
  scanf("%s", phone_book[*num_entries].name);
  printf("Enter the phone number: ");
  scanf("%s", phone_book[*num_entries].phone);
  *num_entries += 1;
}

void find_entry(Entry *phone_book, int num_entries) {
  char name[MAX_NAME_LENGTH];
  printf("Enter the name to find: ");
  scanf("%s", name);
  for (int i = 0; i < num_entries; i++) {
    if (strcmp(phone_book[i].name, name) == 0) {
      printf("Found %s's phone number: %s\n", name, phone_book[i].phone);
      return;
    }
  }
  printf("No entry found for %s\n", name);
}

void delete_entry(Entry *phone_book, int *num_entries) {
  char name[MAX_NAME_LENGTH];
  printf("Enter the name to delete: ");
  scanf("%s", name);
  for (int i = 0; i < *num_entries; i++) {
    if (strcmp(phone_book[i].name, name) == 0) {
      for (int j = i; j < *num_entries - 1; j++) {
        phone_book[j] = phone_book[j + 1];
      }
      *num_entries -= 1;
      return;
    }
  }
  printf("No entry found for %s\n", name);
}

void print_phone_book(Entry *phone_book, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    printf("%s: %s\n", phone_book[i].name, phone_book[i].phone);
  }
}

int main() {
  Entry phone_book[MAX_ENTRIES];
  int num_entries = 0;
  int choice;

  while (1) {
    print_menu();
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_entry(phone_book, &num_entries);
        break;
      case 2:
        find_entry(phone_book, num_entries);
        break;
      case 3:
        delete_entry(phone_book, &num_entries);
        break;
      case 4:
        print_phone_book(phone_book, num_entries);
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}