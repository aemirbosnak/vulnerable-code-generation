//FormAI DATASET v1.0 Category: Linked list operations ; Style: secure
#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *next;
};

typedef struct node Node;

Node *head=NULL;

void insert_beg(int value){
   Node *newNode;
   newNode=(Node*)malloc(sizeof(Node));
   newNode->data=value;
   if(head==NULL)
      newNode->next=NULL;
   else
      newNode->next=head;

   head=newNode;
   printf("\nInsertion successful");
}


void insert_end(int value){
   Node *newNode,*temp;
   newNode=(Node*)malloc(sizeof(Node));
   newNode->data=value;
   newNode->next=NULL;
   if(head==NULL)
      head=newNode;
   else{
      temp=head;
      while(temp->next!=NULL)
         temp=temp->next;

      temp->next=newNode;
   }
   printf("\nInsertion successful");
}

void insert_pos(int value,int pos){
   Node *newNode,*temp;
   int i;
   newNode=(Node*)malloc(sizeof(Node));
   newNode->data=value;
   if(pos==1){
      newNode->next=head;
      head=newNode;
   }else{
      temp=head;
      for(i=2;i<=pos-1;i++){
         temp=temp->next;
         if(temp==NULL){
            printf("\nPosition not found");
            return;
         }
      }
      newNode->next=temp->next;
      temp->next=newNode;
   }
   printf("\nInsertion successful");
}

void delete_beg(){
   Node *temp;
   if(head==NULL){
      printf("\nList is empty");
      return;
   }

   temp=head;
   head=head->next;
   free(temp);
   printf("\nDeletion successful");
}

void delete_end(){
   Node *temp1,*temp2;
   if(head==NULL){
      printf("\nList is empty");
      return;
   }

   if(head->next==NULL){
      free(head);
      head=NULL;
      printf("\nDeletion successful");
      return;
   }

   temp1=head;
   temp2=head->next;
   while(temp2->next!=NULL){
      temp1=temp2;
      temp2=temp2->next;
   }

   free(temp2);
   temp1->next=NULL;
   printf("\nDeletion successful");
}

void delete_pos(int pos){
   Node *temp1,*temp2;
   if(head==NULL){
      printf("\nList is empty");
      return;
   }

   if(pos==1){
      temp1=head;
      head=head->next;
      free(temp1);
   }else{
      temp1=head;
      temp2=head->next;
      int i;
      for(i=2;i<=pos-1;i++){
         temp1=temp2;
         temp2=temp2->next;
         if(temp2==NULL){
            printf("\nPosition not found");
            return;
         }
      }
      temp1->next=temp2->next;
      free(temp2);
   }
   printf("\nDeletion successful");
}

void search(int value){
   Node *temp;
   int pos=1;
   if(head==NULL){
      printf("\nList is empty");
      return;
   }

   temp=head;
   while(temp!=NULL && temp->data!=value){
      temp=temp->next;
      pos++;
   }

   if(temp!=NULL){
      printf("\n%d found at position %d",value,pos);
   }else{
      printf("\n%d not found in the list",value);
   }
}


void display(){
   Node *temp;
   if(head==NULL){
      printf("\nList is empty");
      return;
   }

   temp=head;
   printf("\nList elements are:\n");
   while(temp!=NULL){
      printf("%d\t",temp->data);
      temp=temp->next;
   }
}


int main(){

   int option,value,position;
   while(1){
      printf("\n\n*****MENU*****\n");
      printf("1. Insert at beginning\n");
      printf("2. Insert at end\n");
      printf("3. Insert at any position\n");
      printf("4. Delete from beginning\n");
      printf("5. Delete from end\n");
      printf("6. Delete from any position\n");
      printf("7. Search for an element\n");
      printf("8. Display the list\n");
      printf("9. Exit\n");
      printf("\nChoose an option: ");
      scanf("%d",&option);

      switch(option){
         case 1:
            printf("\nEnter value to insert:");
            scanf("%d",&value);
            insert_beg(value);
            break;
         case 2:
            printf("\nEnter value to insert:");
            scanf("%d",&value);
            insert_end(value);
            break; 
         case 3:
            printf("\nEnter value to insert:");
            scanf("%d",&value);
            printf("\nEnter position to insert:");
            scanf("%d",&position);
            insert_pos(value,position);
            break; 
         case 4:
            delete_beg();
            break;
         case 5:
            delete_end();
            break;
         case 6:
            printf("\nEnter position to delete:");
            scanf("%d",&position);
            delete_pos(position);
            break;
         case 7:
            printf("\nEnter element to search:");
            scanf("%d",&value);
            search(value);
            break;
         case 8:
            display();
            break;
         case 9:
            printf("\nExiting...");
            exit(0);
            break;
         default:
            printf("\nInvalid option");
            break;
      }
   }
   return 0;
}