//FormAI DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
  char name[30];
  char phone_number[20];
};

int main() {
  int option, i, j, found;
  char search_name[30];
  struct contact *phone_book = NULL;
  int num_contacts = 0;
  
  do {
    printf("\nC Phone Book\n");
    printf("1. Add Contact\n");
    printf("2. Display All Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("Enter an option (1-5): ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        {
          // Add a contact
          struct contact new_contact;
          printf("\nEnter a name: ");
          scanf("%s", new_contact.name);
          printf("Enter a phone number: ");
          scanf("%s", new_contact.phone_number);

          // Add the new contact to the phone book
          num_contacts++;
          phone_book = realloc(phone_book, num_contacts * sizeof(struct contact));
          phone_book[num_contacts-1] = new_contact;

          printf("Contact added successfully!\n");
        }
        break;

      case 2:
        // Display all contacts
        printf("\nAll Contacts:\n");
        for (i = 0; i < num_contacts; i++) {
          printf("%s - %s\n", phone_book[i].name, phone_book[i].phone_number);
        }
        break;

      case 3:
        // Search for a contact
        printf("\nEnter the name to search for: ");
        scanf("%s", search_name);
        found = 0;
        for (i = 0; i < num_contacts; i++) {
          if (strcmp(search_name, phone_book[i].name) == 0) {
            printf("%s - %s\n", phone_book[i].name, phone_book[i].phone_number);
            found = 1;
          }
        }
        if (!found) {
          printf("Contact not found!\n");
        }
        break;

      case 4:
        // Delete a contact
        printf("\nEnter the name to delete: ");
        scanf("%s", search_name);
        found = 0;
        for (i = 0; i < num_contacts; i++) {
          if (strcmp(search_name, phone_book[i].name) == 0) {
            // Shift all the contacts down one position to remove the deleted contact
            for (j = i; j < num_contacts - 1; j++) {
              phone_book[j] = phone_book[j+1];
            }
            num_contacts--;
            phone_book = realloc(phone_book, num_contacts * sizeof(struct contact));
            found = 1;
            printf("Contact deleted successfully!\n");
          }
        }
        if (!found) {
          printf("Contact not found!\n");
        }
        break;

      case 5:
        // Exit the program
        printf("\nExiting C Phone Book. Goodbye!\n");
        free(phone_book);
        break;

      default:
        printf("Invalid option. Please try again.\n");
    }
  } while(option != 5);

  return 0;
}