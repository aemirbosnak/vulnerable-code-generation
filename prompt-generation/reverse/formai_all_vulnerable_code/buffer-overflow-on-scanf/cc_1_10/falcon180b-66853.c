//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct node
{
  int data;
  struct node* next;
};

struct node* front = NULL, *rear = NULL;

void enqueue(int val)
{
  struct node* temp = (struct node*) malloc(sizeof(struct node));

  if(temp == NULL)
  {
    printf("\nQueue is full!!");
    exit(0);
  }

  temp->data = val;
  temp->next = NULL;

  if(front == NULL)
  {
    front = temp;
    rear = temp;
  }
  else
  {
    rear->next = temp;
    rear = temp;
  }
}

void dequeue()
{
  struct node* temp = front;

  if(front == NULL)
  {
    printf("\nQueue is empty!!");
    exit(0);
  }

  front = front->next;

  if(front == NULL)
  {
    rear = NULL;
  }

  printf("\nThe deleted element is %d", temp->data);
  free(temp);
}

void display()
{
  struct node* temp = front;

  if(front == NULL)
  {
    printf("\nQueue is empty!!");
    exit(0);
  }

  printf("\nThe elements in the queue are: ");

  while(temp!= NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

void main()
{
  int ch, val;

  while(1)
  {
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
      case 1:
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &val);
        enqueue(val);
        break;

      case 2:
        dequeue();
        break;

      case 3:
        display();
        break;

      case 4:
        exit(0);

      default:
        printf("\nInvalid choice!!");
    }
  }
}