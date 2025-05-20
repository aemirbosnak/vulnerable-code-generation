//FormAI DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h> 

struct contact {
   char name[50];
   char phone_number[20];
   char email[50];
};

void add_contact(struct contact book[], int *size) {
   printf("Enter contact name: ");
   scanf("%s", &(book[*size].name));
   printf("Enter phone number: ");
   scanf("%s", &(book[*size].phone_number));
   printf("Enter email: ");
   scanf("%s", &(book[*size].email));
   (*size)++;
   printf("Contact added successfully.\n");
}

void delete_contact(struct contact book[], int *size) {
   char name[50];
   printf("Enter contact name to delete: ");
   scanf("%s", name);
   int found_index = -1;
   for(int i=0; i<*size; i++) {
      if(strcmp(name, book[i].name) == 0) {
         found_index = i;
         break;
      }
   }
   if(found_index == -1) {
      printf("Contact not found.\n");
      return;
   }
   for(int i=found_index; i<(*size)-1; i++) {
      book[i] = book[i+1];
   }
   (*size)--;
   printf("Contact deleted successfully.\n");
}

void display_contact(struct contact book[], int size) {
   for(int i=0; i<size; i++) {
      printf("Name: %s\n", book[i].name);
      printf("Phone Number: %s\n", book[i].phone_number);
      printf("Email: %s\n", book[i].email);
      printf("\n");
   }
}

int main() {
   int option, size=0;
   struct contact phone_book[100];
   while(1) {
      printf("Cyberpunk Phone Book Menu\n");
      printf("1. Add Contact\n");
      printf("2. Delete Contact\n");
      printf("3. Display Contacts\n");
      printf("4. Exit\n\n");
      printf("Enter option: ");
      scanf("%d", &option);
      switch(option) {
         case 1:
            add_contact(phone_book, &size);
            break;
         case 2:
            delete_contact(phone_book, &size);
            break;
         case 3:
            display_contact(phone_book, size);
            break;
         case 4:
            exit(0);
         default:
            printf("Invalid option.\n");
      }
   }
   return 0;
}