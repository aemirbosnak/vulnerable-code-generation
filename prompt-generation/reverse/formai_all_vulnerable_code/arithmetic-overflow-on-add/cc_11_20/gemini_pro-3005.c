//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
  char name[32];
  char number[16];
  char address[64];
  char email[32];
};

struct phonebook {
  int num_contacts;
  struct contact contacts[100];
};

int main() {
  struct phonebook pb;
  pb.num_contacts = 0;

  while (1) {
    printf("Welcome to the Funny Phone Book!\n");
    printf("1. Add a contact\n");
    printf("2. Search for a contact\n");
    printf("3. Delete a contact\n");
    printf("4. List all contacts\n");
    printf("5. Quit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (pb.num_contacts == 100) {
          printf("Sorry, the phone book is full!\n");
        } else {
          printf("Enter the contact's name: ");
          scanf("%s", pb.contacts[pb.num_contacts].name);
          printf("Enter the contact's number: ");
          scanf("%s", pb.contacts[pb.num_contacts].number);
          printf("Enter the contact's address: ");
          scanf(" %[^\n]%*c", pb.contacts[pb.num_contacts].address);
          printf("Enter the contact's email: ");
          scanf("%s", pb.contacts[pb.num_contacts].email);
          pb.num_contacts++;
        }
        break;
      case 2:
        printf("Enter the contact's name: ");
        char name[32];
        scanf("%s", name);
        int found = 0;
        for (int i = 0; i < pb.num_contacts; i++) {
          if (strcmp(pb.contacts[i].name, name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", pb.contacts[i].name);
            printf("Number: %s\n", pb.contacts[i].number);
            printf("Address: %s\n", pb.contacts[i].address);
            printf("Email: %s\n", pb.contacts[i].email);
            found = 1;
            break;
          }
        }
        if (!found) {
          printf("Contact not found!\n");
        }
        break;
      case 3:
        printf("Enter the contact's name: ");
        char name2[32];
        scanf("%s", name2);
        int found2 = 0;
        for (int i = 0; i < pb.num_contacts; i++) {
          if (strcmp(pb.contacts[i].name, name2) == 0) {
            for (int j = i; j < pb.num_contacts - 1; j++) {
              pb.contacts[j] = pb.contacts[j + 1];
            }
            pb.num_contacts--;
            found2 = 1;
            printf("Contact deleted!\n");
            break;
          }
        }
        if (!found2) {
          printf("Contact not found!\n");
        }
        break;
      case 4:
        if (pb.num_contacts == 0) {
          printf("Phone book is empty!\n");
        } else {
          printf("Contacts:\n");
          for (int i = 0; i < pb.num_contacts; i++) {
            printf("%s\n", pb.contacts[i].name);
          }
        }
        break;
      case 5:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid choice!\n");
        break;
    }
  }

  return 0;
}