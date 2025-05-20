//FormAI DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
   char email[50];
   struct node* next;
};

struct node* head = NULL;

void insert(char email[]) {
   struct node* new_node = (struct node*)malloc(sizeof(struct node));
   strcpy(new_node->email, email);
   new_node->next = head;
   head = new_node;
}

void delete(char email[]) {
   if (head == NULL) return;
   if (strcmp(head->email, email) == 0) {
      struct node* temp = head;
      head = head->next;
      free(temp);
      return;
   }
   struct node* current_node = head;
   while (current_node->next != NULL) {
      if (strcmp(current_node->next->email, email) == 0) {
         struct node* temp = current_node->next;
         current_node->next = current_node->next->next;
         free(temp);
         return;
      }
      current_node = current_node->next;
   }
   printf("Email not found.\n");
}

void display() {
   struct node* current_node = head;
   if (current_node == NULL) {
      printf("Mailing list is empty.\n");
      return;
   }
   printf("Current Mailing List:\n");
   while (current_node != NULL) {
      printf("%s\n", current_node->email);
      current_node = current_node->next;
   }
}

int main() {
   int choice;
   char email[50];
   while (1) {
      printf("\nMailing List Manager\n");
      printf("1. Add email\n");
      printf("2. Remove email\n");
      printf("3. Display all emails\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1: 
            printf("Enter email: ");
            scanf("%s", email);
            insert(email);
            break;
         case 2:
            printf("Enter email: ");
            scanf("%s", email);
            delete(email);
            break;
         case 3:
            display();
            break;
         case 4:
            exit(0);
         default:
            printf("Invalid choice.\n");
      }
   }
   return 0;
}