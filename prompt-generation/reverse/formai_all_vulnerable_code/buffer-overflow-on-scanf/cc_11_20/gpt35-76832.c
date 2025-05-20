//FormAI DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <string.h>

struct Contact {
  char name[50];
  char phone[15];
};

int main() {
  struct Contact phonebook[100];
  int num_contacts = 0;
  int choice;

  do {
    printf("Phone Book Menu\n");
    printf("1. Add a Contact\n");
    printf("2. Search for a Contact\n");
    printf("3. Display all Contacts\n");
    printf("4. Exit\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1: // Add a Contact
        printf("Enter name: ");
        scanf("%s", phonebook[num_contacts].name);
        printf("Enter phone number (no dashes or spaces): ");
        scanf("%s", phonebook[num_contacts].phone);
        printf("Contact added successfully!\n");
        num_contacts++;
        break;

      case 2: // Search for a Contact
        printf("Enter name to search for: ");
        char search_name[50];
        scanf("%s", search_name);
        for(int i=0; i<num_contacts; i++) {
          if(strcmp(search_name, phonebook[i].name) == 0) {
            printf("%s's phone number is: %s\n", search_name, phonebook[i].phone);
            break;
          }
          else if(i == num_contacts-1) {
            printf("Contact not found.\n");
          }
        }
        break;

      case 3: // Display all Contacts
        if(num_contacts == 0) {
          printf("Phone book is empty.\n");
        }
        else {
          printf("Contacts in phone book:\n");
          for(int i=0; i<num_contacts; i++) {
            printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
          }
        }
        break;

      case 4: // Exit
        printf("Exiting phone book.\n");
        break;

      default: // Invalid choice
        printf("Invalid choice. Try again.\n");
    }

    printf("\n");

  } while(choice != 4);

  return 0;
}