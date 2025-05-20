//FormAI DATASET v1.0 Category: Phone Book ; Style: surprised
#include <stdio.h>
#include <string.h>

struct Contact {
   char name[50];
   char phone[15];
   char email[50];
};

struct Contact phoneBook[100];

int numContacts = 0;

void addContact() {
   struct Contact newContact;

   // Get name
   printf("Enter name: ");
   scanf("%s", newContact.name);

   // Get phone number
   printf("Enter phone number: ");
   scanf("%s", newContact.phone);

   // Get email address
   printf("Enter email address: ");
   scanf("%s", newContact.email);

   phoneBook[numContacts] = newContact;
   numContacts++;

   printf("Contact added successfully!\n");
}

void displayContacts() {
   if (numContacts == 0) {
      printf("No contacts to display.\n");
   } else {
      printf("CONTACT LIST:\n\n");
      printf("%-20s %-20s %s\n", "Name", "Phone Number", "Email");

      for (int i = 0; i < numContacts; i++) {
         struct Contact currentContact = phoneBook[i];

         printf("%-20s %-20s %s\n", currentContact.name, currentContact.phone, currentContact.email);
      }
   }
}

int main() {
   char choice;

   printf("Welcome to your phone book! \n");

   do {
      printf("Enter an option: \n");
      printf("1. Add a contact\n");
      printf("2. View all contacts\n");
      printf("3. Exit\n");
      scanf(" %c", &choice);

      switch(choice) {
         case '1':
            addContact();
            break;
         case '2':
            displayContacts();
            break;
         case '3':
            printf("Goodbye!\n");
            break;
         default:
            printf("Invalid option, please try again.\n");
            break;
      }
   } while (choice != '3');

   return 0;
}