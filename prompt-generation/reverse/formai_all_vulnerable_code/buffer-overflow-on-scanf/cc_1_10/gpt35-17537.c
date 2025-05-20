//FormAI DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Address {
  char street[50];
  char city[20];
  int zip;
};

struct PhoneBook {
  char name[20];
  char phone[12];
  struct Address address;
};

void addContact(struct PhoneBook *book);
void displayContact(struct PhoneBook book);
void searchContact(struct PhoneBook *book);

int main() {
  int choice = 0, count = 0;
  struct PhoneBook book[100];

  while (1) {
    printf("Welcome to the Curious Phone Book!\n");
    printf("1. Add Contact\n");
    printf("2. Display Contact\n");
    printf("3. Search Contact\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (count == 100) {
          printf("Phone book is full. Delete some contacts before adding new ones.\n");
        } else {
          addContact(&book[count]);
          count++;
        }
        break;
      case 2:
        printf("Phone Book Contacts:\n");
        for (int i = 0; i < count; i++) {
          displayContact(book[i]);
        }
        break;
      case 3:
        searchContact(book);
        break;
      case 4:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid Choice. Try again.\n");
    }
  }
}

void addContact(struct PhoneBook *book) {
  printf("Enter Contact Name: ");
  scanf("%s", book->name);
  printf("Enter Contact Phone: ");
  scanf("%s", book->phone);
  printf("Enter Contact Street Address: ");
  scanf("%s", book->address.street);
  printf("Enter Contact City: ");
  scanf("%s", book->address.city);
  printf("Enter Contact Zip Code: ");
  scanf("%d", &book->address.zip);
}

void displayContact(struct PhoneBook book) {
  printf("Name: %s\n", book.name);
  printf("Phone: %s\n", book.phone);
  printf("Address: %s, %s, %d\n", book.address.street, book.address.city, book.address.zip);
}

void searchContact(struct PhoneBook *book) {
  char search[20];
  int found = 0;

  printf("Enter Name to Search: ");
  scanf("%s", search);

  for (int i = 0; i < 100; i++) {
    if (strcmp(book[i].name, search) == 0) {
      printf("Contact Found:\n");
      displayContact(book[i]);
      found = 1;
    }
  }

  if (!found) {
    printf("Contact Not Found.\n");
  }
}