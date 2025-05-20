//FormAI DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include<stdio.h>
#define MAXSIZE 10 //defining maximum size of Queue

//function to add an element to the Queue
void enqueue(int queue[], int *rear, int *data)
{
  if(*rear == MAXSIZE-1)
  {
    printf("Queue is full!\n");
  }
  else
  {
    queue[++(*rear)] = *data;
    printf("Added %d to the Queue.\n", *data);
  }
}

//function to remove an element from the Queue
void dequeue(int queue[], int *front, int *rear)
{
  if(*front > *rear)
  {
    printf("Queue is empty!\n");
  }
  else
  {
    printf("Removed %d from the Queue.\n", queue[(*front)++]);
  }
}

//function to display the elements of the Queue
void display(int queue[], int *front, int *rear)
{
  if(*front > *rear)
  {
    printf("Queue is empty!\n");
  }
  else
  {
    printf("Elements in the Queue are:\n");
    for(int i=*front;i<=*rear;i++)
    {
      printf("%d\n", queue[i]);
    }
  }
}

int main()
{
  int queue[MAXSIZE], rear=-1, front=0, choice, data;
  do{
    printf("\n===========================\n");
    printf("Please select an Option:\n");
    printf("1. Add element to Queue\n");
    printf("2. Remove element from Queue\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
    printf("===========================\n");
    printf("Choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1: printf("Enter the element: ");
              scanf("%d", &data);
              enqueue(queue, &rear, &data);
              break;

      case 2: dequeue(queue, &front, &rear);
              break;

      case 3: display(queue, &front, &rear);
              break;

      case 4: printf("Thank you!\n");
              break;
      
      default: printf("Invalid Choice!\n");
               break;
    }
  }while(choice!=4);
  return 0;
}