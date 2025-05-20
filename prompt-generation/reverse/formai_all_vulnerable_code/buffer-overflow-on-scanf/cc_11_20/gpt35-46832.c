//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_ADDRESS_LENGTH 200
#define MAX_LIST_SIZE 100

struct contact {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
  char phone[MAX_PHONE_LENGTH];
  char address[MAX_ADDRESS_LENGTH];
};

struct mailingList {
  struct contact contacts[MAX_LIST_SIZE];
  int size;
};

int main() {
  struct mailingList list;
  list.size = 0;

  int menuSelection = 0;
  while (menuSelection != 5) {
    printf("Menu:\n");
    printf("1. Add contact\n");
    printf("2. Remove contact\n");
    printf("3. Print all contacts\n");
    printf("4. Search for contact\n");
    printf("5. Quit\n");
    printf("Enter selection: ");
    scanf("%d", &menuSelection);

    switch (menuSelection) {
      case 1: { // add contact
        if (list.size == MAX_LIST_SIZE) {
          printf("Error: list is full.\n");
          break;
        }

        struct contact newContact;

        printf("Enter name: ");
        scanf("%s", newContact.name);

        printf("Enter email: ");
        scanf("%s", newContact.email);

        printf("Enter phone number: ");
        scanf("%s", newContact.phone);

        printf("Enter address: ");
        scanf("%s", newContact.address);

        list.contacts[list.size] = newContact;
        list.size++;

        printf("Contact added.\n");
        break;
      }
      case 2: { // remove contact
        if (list.size == 0) {
          printf("Error: list is empty.\n");
          break;
        }

        printf("Enter name: ");
        char removeName[MAX_NAME_LENGTH];
        scanf("%s", removeName);

        int removeIndex = -1;
        for (int i = 0; i < list.size; i++) {
          if (strcmp(list.contacts[i].name, removeName) == 0) {
            removeIndex = i;
            break;
          }
        }

        if (removeIndex == -1) {
          printf("Error: no contact with name %s found.\n", removeName);
          break;
        }

        for (int i = removeIndex + 1; i < list.size; i++) {
          list.contacts[i - 1] = list.contacts[i];
        }
        list.size--;

        printf("Contact removed.\n");
        break;
      }
      case 3: { // print all contacts
        if (list.size == 0) {
          printf("Error: list is empty.\n");
          break;
        }

        printf("List of contacts:\n");
        for (int i = 0; i < list.size; i++) {
          struct contact currentContact = list.contacts[i];
          printf("Name: %s\n", currentContact.name);
          printf("Email: %s\n", currentContact.email);
          printf("Phone: %s\n", currentContact.phone);
          printf("Address: %s\n\n", currentContact.address);
        }
        break;
      }
      case 4: { // search for contact
        if (list.size == 0) {
          printf("Error: list is empty.\n");
          break;
        }

        printf("Enter name: ");
        char searchName[MAX_NAME_LENGTH];
        scanf("%s", searchName);

        int searchIndex = -1;
        for (int i = 0; i < list.size; i++) {
          if (strcmp(list.contacts[i].name, searchName) == 0) {
            searchIndex = i;
            break;
          }
        }

        if (searchIndex == -1) {
          printf("Error: no contact with name %s found.\n", searchName);
          break;
        }

        struct contact searchedContact = list.contacts[searchIndex];
        printf("%s\n%s\n%s\n%s\n",
          searchedContact.name,
          searchedContact.email,
          searchedContact.phone,
          searchedContact.address
        );
        break;
      }
      case 5: // quit
        printf("Quitting...\n");
        break;
      default:
        printf("Error: invalid menu selection.\n");
        break;
    }
  }

  return 0;
}