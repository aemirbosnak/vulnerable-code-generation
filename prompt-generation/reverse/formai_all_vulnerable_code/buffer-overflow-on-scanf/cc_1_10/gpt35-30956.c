//FormAI DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phonebook {
   char name[50];
   char number[15];
   struct phonebook *next;
} Phonebook;


Phonebook *head = NULL;

void addContact(char name[], char number[]) {
   Phonebook *temp = (Phonebook*) malloc(sizeof(Phonebook));
   strcpy(temp->name, name);
   strcpy(temp->number, number);
   temp->next = head;
   head = temp;
   printf("Contact added successfully!\n");
}

void searchContact(char name[]) {
   Phonebook *temp = head;
   int found = 0;
   while(temp != NULL) {
      if(strcmp(temp->name, name) == 0) {
         found = 1;
         printf("Name: %s\nNumber: %s\n", temp->name, temp->number);
         break;
      }
      temp = temp->next;
   }
   if(!found) {
      printf("No contact with that name found.\n");
   }
}

void deleteContact(char name[]) {
   Phonebook *temp = head, *prev;
   int found = 0;
   if(temp != NULL && strcmp(temp->name, name) == 0) {
      head = temp->next;
      free(temp);
      printf("Contact deleted successfully!\n");
      found = 1;
      return;
   } 
   while(temp != NULL) {
      if(strcmp(temp->name, name) == 0) {
         found = 1;
         prev->next = temp->next;
         free(temp);
         printf("Contact deleted successfully!\n");
         break;
      }
      prev = temp;
      temp = temp->next;
   }
   if(!found) {
      printf("No contact with that name found.\n");
   }
}

void displayContacts() {
   Phonebook *temp = head;
   if(temp == NULL) {
      printf("No contacts available.\n");
      return;
   }
   printf("Name\tNumber\n");
   while(temp != NULL) {
      printf("%s\t%s\n", temp->name, temp->number);
      temp = temp->next;
   }
}

int main() {
   int choice;
   char name[50], number[15];
   printf("Welcome to the Phone Book!\n");
   do {
      printf("\nWhat would you like to do?\n");
      printf("1. Add a contact\n2. Search for a contact\n3. Delete a contact\n4. Display all contacts\n5. Quit\n");
      scanf("%d", &choice);
      switch(choice) {
         case 1: 
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            addContact(name, number);
            break;
         case 2:
            printf("Enter name to search for: ");
            scanf("%s", name);
            searchContact(name);
            break;
         case 3:
            printf("Enter name to delete: ");
            scanf("%s", name);
            deleteContact(name);
            break;
         case 4:
            displayContacts();
            break;
         case 5:
            printf("Goodbye!");
            exit(0);
         default:
            printf("Invalid choice.");
            break;
      }
   } while(choice != 5);
   return 0;
}