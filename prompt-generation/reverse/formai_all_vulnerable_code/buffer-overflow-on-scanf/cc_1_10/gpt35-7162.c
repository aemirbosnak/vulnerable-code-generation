//FormAI DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
   char email[50];
   struct node *next;
}*head;

void addToList(char *email) {
   struct node *newEmail = (struct node*) malloc(sizeof(struct node));
   strcpy(newEmail->email, email);
   newEmail->next = head;
   head = newEmail;
}

void displayList() {
   struct node *temp = head;
   while(temp != NULL) {
      printf("%s\n", temp->email);
      temp = temp->next;
   }
}

void searchEmail(char *email) {
   struct node *temp = head;
   while(temp != NULL) {
      if(strcmp(temp->email, email) == 0) {
         printf("Email %s found in the list.\n", email);
         return;
      }
      temp = temp->next;
   }
   printf("Email %s not found in the list.\n", email);
}

int main() {
   char email[50];
   char choice;
   head = NULL;
   while(1) {
      printf("\n------------------------------------------------\n");
      printf("\n              Mailing List Manager               \n");
      printf("\n------------------------------------------------\n");
      printf("\n      1. Add Email to List                       \n");
      printf("\n      2. Display List                             \n");
      printf("\n      3. Search Email in List                     \n");
      printf("\n      4. Exit Program                              \n");
      printf("\n------------------------------------------------\n");
      printf("\nEnter Choices (1/2/3/4): ");
      scanf(" %c", &choice);
      switch(choice) {
         case '1':
            printf("Enter Email to Add: ");
            scanf("%s", email);
            addToList(email);
            break;
         case '2':
            printf("\nMailing List:\n");
            displayList();
            break;
         case '3':
            printf("Enter Email to Search: ");
            scanf("%s", email);
            searchEmail(email);
            break;
         case '4':
            printf("Thank you for using Mailing List Manager.\n");
            exit(0);
            break;
         default:
            printf("Invalid Choice. Please Enter Choices (1/2/3/4)\n");
            break;
      }
   }
   return 0;
}