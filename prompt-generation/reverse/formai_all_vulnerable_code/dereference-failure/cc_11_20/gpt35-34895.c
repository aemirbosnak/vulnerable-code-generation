//FormAI DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBook {
  char name[50];
  char number[20];
};

int main() {
  int choice, i, count = 0;
  struct PhoneBook *phonebook;
  char name[50], number[20];

  printf("Welcome to the Phone Book\n");

  while (1) {
    printf("\nPlease choose an option:\n1. Add contact\n2. Search contact\n3. Display all contacts\n4. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter number: ");
        scanf("%s", number);

        if (count == 0) {
          phonebook = (struct PhoneBook*) malloc(sizeof(struct PhoneBook));
        } else {
          phonebook = (struct PhoneBook*) realloc(phonebook, (count+1)*sizeof(struct PhoneBook));
        }

        strcpy(phonebook[count].name, name);
        strcpy(phonebook[count].number, number);

        printf("Contact added successfully!\n");
        count++;
        break;

      case 2:
        printf("Enter a name to search: ");
        scanf("%s", name);

        for (i=0; i<count; i++) {
          if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
            break;
          }
        }

        if (i == count) {
          printf("Contact not found.\n");
        }
        break;

      case 3:
        printf("Contacts:\n");

        for (i=0; i<count; i++) {
          printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
        }

        if (count == 0) {
          printf("No contacts stored.\n");
        }
        break;

      case 4:
        printf("Thank you for using the Phone Book.\n");
        free(phonebook);
        exit(0);
        break;

      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}