//FormAI DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

int length(struct node *head) {
   int count = 0;
   struct node *current = head;
   while(current != NULL) {
      count++;
      current = current -> next;
   }
   return count;
}

void display(struct node *head) {
   printf("\nElements of the Linked List:\n");
   struct node *current = head;
   while(current != NULL) {
      printf("%d -> ", current -> data);
      current = current -> next;
   }
   printf("NULL\n");
}

void insertAtBeginning(struct node **head, int data) {
   struct node *newNode = (struct node*) malloc(sizeof(struct node));
   newNode -> data = data;
   newNode -> next = *head;
   *head = newNode;
}

void insertAtEnd(struct node **head, int data) {
   struct node *newNode = (struct node*) malloc(sizeof(struct node));
   newNode -> data = data;
   newNode -> next = NULL;
   if(*head == NULL) {
      *head = newNode;
      return;
   }
   struct node *current = *head;
   while(current -> next != NULL) {
      current = current -> next;
   }
   current -> next = newNode;
}

void insertAtPosition(struct node **head, int data, int position) {
   int len = length(*head);
   if(position < 1 || position > len + 1) {
      printf("\nInvalid position!\n");
      return;
   }
   if(position == 1) {
      insertAtBeginning(head, data);
      return;
   }
   if(position == len + 1) {
      insertAtEnd(head, data);
      return;
   }
   struct node *newNode = (struct node*) malloc(sizeof(struct node));
   newNode -> data = data;
   struct node *current = *head;
   for(int i = 1; i < position - 1; i++) {
      current = current -> next;
   }
   newNode -> next = current -> next;
   current -> next = newNode;
}

void deleteAtBeginning(struct node **head) {
   if(*head == NULL) {
      printf("\nEmpty Linked List!\n");
      return;
   }
   struct node *temp = *head;
   *head = temp -> next;
   free(temp);
}

void deleteAtEnd(struct node **head) {
   if(*head == NULL) {
      printf("\nEmpty Linked List!\n");
      return;
   }
   if((*head) -> next == NULL) {
      free(*head);
      *head = NULL;
      return;
   }
   struct node *current = *head;
   while(current -> next -> next != NULL) {
      current = current -> next;
   }
   free(current -> next);
   current -> next = NULL;
}

void deleteAtPosition(struct node **head, int position) {
   int len = length(*head);
   if(position < 1 || position > len) {
      printf("\nInvalid position!\n");
      return;
   }
   if(position == 1) {
      deleteAtBeginning(head);
      return;
   }
   if(position == len) {
      deleteAtEnd(head);
      return;
   }
   struct node *current = *head;
   for(int i = 1; i < position - 1; i++) {
      current = current -> next;
   }
   struct node *temp = current -> next;
   current -> next = temp -> next;
   free(temp);
}

int main() {
   struct node *head = NULL;
   int choice, data, position;

   while(1) {
      printf("\nEnter your choice:\n");
      printf("1. Insert at beginning\n");
      printf("2. Insert at end\n");
      printf("3. Insert at position\n");
      printf("4. Delete from beginning\n");
      printf("5. Delete from end\n");
      printf("6. Delete from position\n");
      printf("7. Display\n");
      printf("8. Exit\n");

      scanf("%d", &choice);

      switch(choice) {
         case 1:
            printf("\nEnter data to be inserted: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
         case 2:
            printf("\nEnter data to be inserted: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
         case 3:
            printf("\nEnter data to be inserted: ");
            scanf("%d", &data);
            printf("Enter the position for insertion: ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            break;
         case 4:
            deleteAtBeginning(&head);
            break;
         case 5:
            deleteAtEnd(&head);
            break;
         case 6:
            printf("\nEnter the position for deletion: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
         case 7:
            display(head);
            break;
         case 8:
            exit(0);
         default:
            printf("\nInvalid choice!\n");
      }
   }
   return 0;
}