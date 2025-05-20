//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: automated
// C Phone Book Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 10

typedef struct {
  char name[MAX_NAME_LENGTH];
  char phone[MAX_PHONE_LENGTH];
} Entry;

void print_menu(void) {
  printf("---------------------------------\n");
  printf("1. Add new entry\n");
  printf("2. Search for entry\n");
  printf("3. Print all entries\n");
  printf("4. Exit\n");
  printf("---------------------------------\n");
}

void add_entry(Entry entries[], int *num_entries) {
  int index = *num_entries;
  printf("Enter name: ");
  scanf("%s", entries[index].name);
  printf("Enter phone: ");
  scanf("%s", entries[index].phone);
  (*num_entries)++;
}

void search_entry(Entry entries[], int num_entries) {
  char name[MAX_NAME_LENGTH];
  printf("Enter name to search: ");
  scanf("%s", name);
  for (int i = 0; i < num_entries; i++) {
    if (strcmp(entries[i].name, name) == 0) {
      printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
      return;
    }
  }
  printf("Entry not found.\n");
}

void print_entries(Entry entries[], int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
  }
}

int main(void) {
  Entry entries[MAX_ENTRIES];
  int num_entries = 0;
  int choice = 0;

  while (choice != 4) {
    print_menu();
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_entry(entries, &num_entries);
        break;
      case 2:
        search_entry(entries, num_entries);
        break;
      case 3:
        print_entries(entries, num_entries);
        break;
      case 4:
        break;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}