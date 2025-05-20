//FormAI DATASET v1.0 Category: Linked list operations ; Style: creative
#include<stdio.h>
#include<stdlib.h>

//Node Definition
struct node {
   int data;
   struct node *next;
};
typedef struct node NODE;


//Function to insert at the beginning of the linked list
void insert_beginning(NODE **head,int data){
   NODE *newNode;
   newNode = (NODE*)malloc(sizeof(NODE));
   newNode->data = data;
   newNode->next = (*head);
   (*head) = newNode;
}

//Function to insert at the end of the linked list
void insert_end(NODE **head,int data){
   NODE *newNode,*temp;
   newNode = (NODE*)malloc(sizeof(NODE));
   newNode->data = data;
   newNode->next = NULL;
   if((*head) == NULL)
      (*head) = newNode;
   else {
      temp = (*head);
      while(temp->next != NULL)
         temp = temp->next;
      temp->next = newNode;
   }
}

//Function to delete the first node of the linked list
void delete_beginning(NODE **head){
   NODE *temp;
   if((*head) == NULL)
      printf("Linked List is empty\n");
   else {
      temp = (*head);
      (*head) = temp->next;
      free(temp);
   }
}

//Function to delete the last node of the linked list
void delete_end(NODE **head){
   NODE *temp,*prev;
   if((*head) == NULL)
      printf("Linked List is empty\n");
   else if((*head)->next == NULL) {
      temp = (*head);
      (*head) = NULL;
      free(temp);
   }
   else {
      temp = (*head);
      while(temp->next != NULL) {
         prev = temp;
         temp = temp->next;
      }
      prev->next = NULL;
      free(temp);
   }
}

//Function to print the linked list
void display(NODE *head){
   NODE *temp;
   if(head == NULL)
      printf("Linked List is empty\n");
   else {
      temp = head;
      while(temp != NULL) {
         printf("%d ",temp->data);
         temp = temp->next;
      }
      printf("\n");
   }
}

//Main Function
int main() {
   NODE *head;
   head = NULL;
   int choice, data;
   do {
      printf("1. Insert at beginning\n");
      printf("2. Insert at end\n");
      printf("3. Delete from beginning\n");
      printf("4. Delete from end\n");
      printf("5. Display\n");
      printf("6. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice) {
         case 1: printf("Enter the data to be inserted: ");
                 scanf("%d",&data);
                 insert_beginning(&head,data);
                 break;
         case 2: printf("Enter the data to be inserted: ");
                 scanf("%d",&data);
                 insert_end(&head,data);
                 break;
         case 3: delete_beginning(&head);
                 break;
         case 4: delete_end(&head);
                 break;
         case 5: printf("Linked List: ");
                 display(head);
                 break;
         case 6: printf("Exiting the program!\n");
                 break;
         default: printf("Invalid choice\n");
      }
   }while(choice != 6);
   return 0;
}