//FormAI DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int data;
   struct Node* next;
} Node;

Node* createNode(int data){
   Node* new_node = (Node*)malloc(sizeof(Node));
   new_node->data = data;
   new_node->next = NULL;
   return new_node;
}

void addNode(Node** head, int data){
   if(*head == NULL){
      *head = createNode(data);
      return;
   }
   Node* temp = *head;
   while(temp->next != NULL)
      temp = temp->next;
   temp->next = createNode(data);
}

void display(Node* head){
   if(head == NULL){
      printf("Linked list is empty.\n");
      return;
   }
   Node* temp = head;
   printf("Linked list: ");
   while(temp != NULL){
      printf("%d ",temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int main(){
   Node* head = NULL;
   int choice,data;
   printf("Welcome to the futuristic world of Linked List operations.\n");
   while(1){
      printf("1. Insert at end.\n");
      printf("2. Display.\n");
      printf("3. Exit.\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
         case 1: printf("Enter data: ");
                 scanf("%d",&data);
                 addNode(&head,data);
                 break;
         case 2: display(head);
                 break;
         case 3: printf("Power off...\n");
                 exit(0);
         default: printf("Invalid choice.\n");
      }
   }
   return 0;
}