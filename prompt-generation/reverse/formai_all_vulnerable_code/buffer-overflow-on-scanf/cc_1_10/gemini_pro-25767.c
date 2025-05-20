//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct phonebook_entry {
  char name[50];
  char number[15];
} phonebook_entry;

void add_entry(phonebook_entry *phonebook, int *size) {
  printf("Name: ");
  scanf(" %[^\n]s", phonebook->name);
  printf("Number: ");
  scanf(" %[^\n]s", phonebook->number);
  (*size)++;
}

void print_entry(phonebook_entry entry) {
  printf("%s: %s\n", entry.name, entry.number);
}

void search_entry(phonebook_entry *phonebook, int size) {
  char name[50];
  printf("Enter name to search: ");
  scanf(" %[^\n]s", name);
  int found = 0;
  for (int i = 0; i < size; i++) {
    if (strcmp(phonebook[i].name, name) == 0) {
      print_entry(phonebook[i]);
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Entry not found.\n");
  }
}

void delete_entry(phonebook_entry *phonebook, int *size) {
  char name[50];
  printf("Enter name to delete: ");
  scanf(" %[^\n]s", name);
  int found = 0;
  for (int i = 0; i < *size; i++) {
    if (strcmp(phonebook[i].name, name) == 0) {
      for (int j = i; j < *size - 1; j++) {
        phonebook[j] = phonebook[j + 1];
      }
      (*size)--;
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Entry not found.\n");
  }
}

int main() {
  phonebook_entry phonebook[100];
  int size = 0;
  int choice;
  do {
    printf("1. Add Entry\n2. Print Entry\n3. Search Entry\n4. Delete Entry\n5. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_entry(phonebook, &size);
        break;
      case 2:
        for (int i = 0; i < size; i++) {
          print_entry(phonebook[i]);
        }
        break;
      case 3:
        search_entry(phonebook, size);
        break;
      case 4:
        delete_entry(phonebook, &size);
        break;
      case 5:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 5);
  return 0;
}