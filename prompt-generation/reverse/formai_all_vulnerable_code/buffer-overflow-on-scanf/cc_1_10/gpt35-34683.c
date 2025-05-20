//FormAI DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

struct Node* head = NULL;

void insert_beginning(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
   printf("Element added successfully!\n");
}

void insert_end(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = NULL;
   if(head == NULL) {
      head = new_node;
      printf("Element added successfully!\n");
      return;
   }
   struct Node* curr_node = head;
   while(curr_node->next != NULL) {
      curr_node = curr_node->next;
   }
   curr_node->next = new_node;
   printf("Element added successfully!\n");
}

void delete_beginning() {
   if(head == NULL) {
      printf("List is empty!\n");
      return;
   }
   struct Node* temp = head;
   head = head->next;
   free(temp);
   printf("Element deleted from beginning successfully!\n");
}

void delete_end() {
   if(head == NULL) {
      printf("List is empty!\n");
      return;
   }
   if(head->next == NULL) {
      free(head);
      head = NULL;
      printf("Element deleted from end successfully!\n");
      return;
   }
   struct Node* curr_node = head;
   while(curr_node->next->next != NULL) {
      curr_node = curr_node->next;
   }
   free(curr_node->next);
   curr_node->next = NULL;
   printf("Element deleted from end successfully!\n");
}

void display() {
   if(head == NULL) {
      printf("List is empty!\n");
      return;
   }
   struct Node* curr_node = head;
   printf("Elements in the list are: ");
   while(curr_node != NULL) {
      printf("%d ", curr_node->data);
      curr_node = curr_node->next;
   }
   printf("\n");
}

void main() {
   int choice, element;
   printf("1. Insert at beginning\n");
   printf("2. Insert at end\n");
   printf("3. Delete from beginning\n");
   printf("4. Delete from end\n");
   printf("5. Display\n");
   printf("6. Exit\n");
   while(1) {
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            printf("Enter the element to be inserted at beginning: ");
            scanf("%d", &element);
            insert_beginning(element);
            break;
         case 2:
            printf("Enter the element to be inserted at end: ");
            scanf("%d", &element);
            insert_end(element);
            break;
         case 3:
            delete_beginning();
            break;
         case 4:
            delete_end();
            break;
         case 5:
            display();
            break;
         case 6:
            printf("Exiting program!");
            exit(0);
            break;
         default:
            printf("Invalid choice! Try again.\n");
      }
   }
}