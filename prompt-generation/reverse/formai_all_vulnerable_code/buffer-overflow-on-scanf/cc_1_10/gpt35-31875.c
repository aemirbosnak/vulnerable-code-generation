//FormAI DATASET v1.0 Category: Memory management ; Style: active
#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *next;
}*start = NULL, *temp = NULL, *newnode = NULL;

void create_node()
{
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("Enter Number :");
   scanf("%d", &newnode->data);
   newnode->next=NULL;
}

void insert()
{
   create_node();
   if(start==NULL)
   {
      start=newnode;
      temp=newnode;
   }
   else
   {
      temp->next=newnode;
      temp=newnode;
   }
}

void display()
{
   if(start==NULL)
   {
      printf("List is Empty\n");
   }
   else
   {
      temp=start;
      while(temp!=NULL)
      {
         printf("%d\t", temp->data);
         temp=temp->next;
      }
   }
}

void deallocate_memory()
{
   struct node *temp1; 
   while (start != NULL) 
   { 
       temp1 = start; 
       start = start->next; 
       free(temp1); 
   } 
}

int main()
{
   int choice=0;
   while(choice!=4)
   {
      printf("\n1.Insert Number into List\n2.Display List\n3.Clear Memory for List\n4.Exit");
      printf("\nEnter Your Choice : ");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1:
            insert();
            break;
         case 2:
            display();
            break;
         case 3:
            deallocate_memory();
            printf("Memory is Deallocated for the List\n");
            break;
         case 4:
            exit(0);
            break;
         default:
            printf("Please Enter Valid Option \n");
            break;
      }
   }
   return 0;
}