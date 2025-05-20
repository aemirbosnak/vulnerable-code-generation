//FormAI DATASET v1.0 Category: Mailing list manager ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
   char name[50];
   char email[50];
   struct node *next;
};

typedef struct node Node;

void addNode(Node **head_ref) {
   Node *new_node = (Node*)malloc(sizeof(Node));
   printf("Enter name: ");
   scanf("%s", new_node->name);
   printf("Enter email: ");
   scanf("%s", new_node->email);
   new_node->next = NULL;
   
   if(*head_ref == NULL) {
      *head_ref = new_node;
      return;
   }
   
   Node *ptr = *head_ref;
   
   while(ptr->next != NULL) {
      ptr = ptr->next;
   }
   
   ptr->next = new_node;
}

void display(Node **head_ref) {
   if(*head_ref == NULL) {
      printf("List is empty");
      return;
   }
   
   printf("Name \t Email\n");
   
   Node *ptr = *head_ref;
   
   while(ptr != NULL) {
      printf("%s \t %s\n", ptr->name, ptr->email);
      ptr = ptr->next;
   }
}

void search(Node **head_ref) {
   if(*head_ref == NULL) {
      printf("List is empty");
      return;
   }
   
   char search_email[50];
   printf("Enter the email to search: ");
   scanf("%s", search_email);
   
   Node *ptr = *head_ref;
   int found = 0;
   
   while(ptr != NULL) {
      if(strcmp(ptr->email, search_email) == 0) {
         printf("Name: %s\n", ptr->name);
         found = 1;
         break;
      }
      
      ptr = ptr->next;
   }
   
   if(found == 0) {
      printf("Email not found!\n");
   }
}

void delete(Node **head_ref) {
   if(*head_ref == NULL) {
      printf("List is empty");
      return;
   }
   
   char del_email[50];
   printf("Enter the email to delete: ");
   scanf("%s", del_email);
   
   Node *prev = NULL;
   Node *ptr = *head_ref;
   int found = 0;
   
   while(ptr != NULL) {
      if(strcmp(ptr->email, del_email) == 0) {
         found = 1;
         break;
      }
      
      prev = ptr;
      ptr = ptr->next;
   }
   
   if(found == 0) {
      printf("Email not found!\n");
      return;
   }
   
   if(prev == NULL) {
      *head_ref = ptr->next;
   } else {
      prev->next = ptr->next;
   }
   
   free(ptr);
   printf("Email %s deleted successfully\n", del_email);
}

int main() {
   Node *head = NULL;
   int option = 0;
   
   do {
      printf("\n\n*** MAILING LIST MANAGER ***\n");
      printf("1. Add New Email\n");
      printf("2. Display All Emails\n");
      printf("3. Search Email\n");
      printf("4. Delete Email\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &option);
      
      switch(option) {
         case 1:
            addNode(&head);
            break;
         case 2:
            display(&head);
            break;
         case 3:
            search(&head);
            break;
         case 4:
            delete(&head);
            break;
         case 5:
            printf("Goodbye!\n");
            break;
         default:
            printf("Invalid Option! Try Again...\n\n");
      }
   } while(option != 5);
   
   return 0;
}