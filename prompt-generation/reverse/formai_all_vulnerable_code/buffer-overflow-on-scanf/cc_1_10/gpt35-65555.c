//FormAI DATASET v1.0 Category: Phone Book ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct PhoneBook {
   char name[50];
   char phone_number[15];
   struct PhoneBook *next;
}*head;

void addContact(char name[], char phone_number[]);
void displayContacts();
void deleteContact(char name[]);
void searchContact(char name[]);

int main() {
   int choice;
   char name[50], phone_number[15];

   while(1) {
      printf("\n----- C Phone Book -----\n");
      printf("1. Add Contact\n");
      printf("2. Display Contacts\n");
      printf("3. Delete Contact\n");
      printf("4. Search Contact\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Phone Number: ");
            scanf("%s", phone_number);
            addContact(name, phone_number);
            break;

         case 2:
            displayContacts();
            break;

         case 3:
            printf("Enter Name: ");
            scanf("%s", name);
            deleteContact(name);
            break;

         case 4:
            printf("Enter Name: ");
            scanf("%s", name);
            searchContact(name);
            break;

         case 5:
            exit(0);

         default:
            printf("Invalid Choice!\n");
      }
   }
}

void addContact(char name[], char phone_number[]) {
   struct PhoneBook *node, *temp;

   // Create a new node for the input data
   node = (struct PhoneBook *)malloc(sizeof(struct PhoneBook));
   strcpy(node->name, name);
   strcpy(node->phone_number, phone_number);
   node->next = NULL;

   // If head is NULL then make this node as head
   if(head == NULL)
      head = node;
   else {
      // Traverse till the last node and add new node at the end
      temp = head;
      while(temp->next != NULL)
         temp = temp->next;
      temp->next = node;
   }
   printf("Contact Added Successfully!\n");
}

void displayContacts() {
   struct PhoneBook *temp;

   // If list is empty
   if(head == NULL)
      printf("Phone Book is Empty!\n");
   else {
      printf("Name\tPhone Number\n");
      printf("-----------------------\n");

      // Traverse the list and print all the nodes
      temp = head;
      while(temp != NULL) {
         printf("%s\t%s\n", temp->name, temp->phone_number);
         temp = temp->next;
      }
   }
}

void deleteContact(char name[]) {
   struct PhoneBook *temp, *prev;

   // If list is empty
   if(head == NULL) {
      printf("Phone Book is Empty!\n");
      return;
   }

   // Traverse the list till we find the node to be deleted
   temp = head;
   prev = NULL;
   while(temp != NULL && strcmp(temp->name, name) != 0) {
      prev = temp;
      temp = temp->next;
   }

   // If node not found
   if(temp == NULL) {
      printf("Contact \"%s\" not found!\n", name);
      return;
   }

   // If node is the first node
   if(prev == NULL)
      head = temp->next;
   else
      prev->next = temp->next;

   // Delete the node and free the memory
   free(temp);
   printf("Contact \"%s\" deleted successfully!\n", name);
}

void searchContact(char name[]) {
   struct PhoneBook *temp;

   // If list is empty
   if(head == NULL) {
      printf("Phone Book is Empty!\n");
      return;
   }

   // Traverse the list till we find the node to be searched
   temp = head;
   while(temp != NULL && strcmp(temp->name, name) != 0)
      temp = temp->next;

   // If node not found
   if(temp == NULL)
      printf("Contact \"%s\" not found!\n", name);
   else
      printf("Contact \"%s\" found. Phone Number: %s\n", temp->name, temp->phone_number);
}