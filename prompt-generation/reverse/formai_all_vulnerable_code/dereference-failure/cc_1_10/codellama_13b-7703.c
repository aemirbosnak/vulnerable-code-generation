//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  struct Contact {
    char name[30];
    char phone[15];
  };

  struct PhoneBook {
    struct Contact *contacts;
    int size;
    int capacity;
  };

  void addContact(struct PhoneBook *phoneBook, struct Contact contact) {
    if (phoneBook->size == phoneBook->capacity) {
      phoneBook->capacity *= 2;
      phoneBook->contacts = realloc(phoneBook->contacts, phoneBook->capacity * sizeof(struct Contact));
    }

    phoneBook->contacts[phoneBook->size++] = contact;
  }

  void removeContact(struct PhoneBook *phoneBook, int index) {
    if (index < 0 || index >= phoneBook->size) {
      return;
    }

    phoneBook->size--;
    memmove(phoneBook->contacts + index, phoneBook->contacts + index + 1, (phoneBook->size - index) * sizeof(struct Contact));
  }

  int findContact(struct PhoneBook *phoneBook, const char *name) {
    for (int i = 0; i < phoneBook->size; i++) {
      if (strcmp(phoneBook->contacts[i].name, name) == 0) {
        return i;
      }
    }

    return -1;
  }

  void printContact(struct Contact contact) {
    printf("%s: %s\n", contact.name, contact.phone);
  }

  int main() {
    struct PhoneBook phoneBook;
    phoneBook.size = 0;
    phoneBook.capacity = 10;
    phoneBook.contacts = malloc(phoneBook.capacity * sizeof(struct Contact));

    addContact(&phoneBook, (struct Contact) {"John", "555-1234"});
    addContact(&phoneBook, (struct Contact) {"Jane", "555-5678"});
    addContact(&phoneBook, (struct Contact) {"Bob", "555-9012"});

    removeContact(&phoneBook, 0);

    int index = findContact(&phoneBook, "Jane");
    if (index != -1) {
      printContact(phoneBook.contacts[index]);
    }

    return 0;
  }