//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBookEntry {
  char name[100];
  char phone[100];
  struct PhoneBookEntry *next;
};

struct PhoneBook {
  struct PhoneBookEntry *head;
};

void print_phone_book(struct PhoneBook *phone_book) {
  struct PhoneBookEntry *current = phone_book->head;
  while (current != NULL) {
    printf("%s: %s\n", current->name, current->phone);
    current = current->next;
  }
}

void add_phone_book_entry(struct PhoneBook *phone_book, char *name, char *phone) {
  struct PhoneBookEntry *new_entry = malloc(sizeof(struct PhoneBookEntry));
  strcpy(new_entry->name, name);
  strcpy(new_entry->phone, phone);
  new_entry->next = phone_book->head;
  phone_book->head = new_entry;
}

void delete_phone_book_entry(struct PhoneBook *phone_book, char *name) {
  struct PhoneBookEntry *current = phone_book->head;
  struct PhoneBookEntry *previous = NULL;
  while (current != NULL) {
    if (strcmp(current->name, name) == 0) {
      if (previous == NULL) {
        phone_book->head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      break;
    }
    previous = current;
    current = current->next;
  }
}

int main() {
  struct PhoneBook phone_book = { NULL };
  add_phone_book_entry(&phone_book, "John Doe", "555-1234");
  add_phone_book_entry(&phone_book, "Jane Doe", "555-5678");
  add_phone_book_entry(&phone_book, "John Smith", "555-9012");
  print_phone_book(&phone_book);
  delete_phone_book_entry(&phone_book, "Jane Doe");
  print_phone_book(&phone_book);
  return 0;
}