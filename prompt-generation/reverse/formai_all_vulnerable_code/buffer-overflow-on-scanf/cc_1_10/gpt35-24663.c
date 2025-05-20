//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 50 // Maximum capacity of the conveyor belt
#define MAX_BAGS 100    // Maximum number of bags in the system

int conveyor_belt[MAX_CAPACITY]; // Array to represent conveyor belt
int front = -1, rear = -1;        // Indexes to keep track of queue elements

void addItemToBelt(int item)
{
  if ((front == 0 && rear == MAX_CAPACITY - 1) || (front == rear + 1))
  {
    printf("\n\nError: Conveyor belt full! Baggage with tag number %d will be missed.\n\n", item);
    return;
  }
  else if (rear == -1)
  {
    front = rear = 0;
  }
  else if (rear == MAX_CAPACITY - 1)
  {
    rear = 0;
  }
  else
  {
    rear++;
  }

  conveyor_belt[rear] = item;

  printf("\nBaggage with tag number %d added to conveyor belt.\n\n", item);
}

int removeItemFromBelt()
{
  if (front == -1)
  {
    printf("\n\nError: Conveyor belt is empty!\n\n");
    return -1;
  }

  int tag = conveyor_belt[front];

  if (front == rear)
  {
    front = rear = -1;
  }
  else if (front == MAX_CAPACITY - 1)
  {
    front = 0;
  }
  else
  {
    front++;
  }

  printf("\nBaggage with tag number %d removed from conveyor belt.\n\n", tag);

  return tag;
}

void displayConveyorBelt()
{
  if (front == -1)
  {
    printf("\n\nConveyor belt is empty!\n\n");
    return;
  }

  printf("\n\nContents of conveyor belt: \n");

  if (rear >= front)
  {
    for (int i = front; i <= rear; i++)
    {
      printf("%d ", conveyor_belt[i]);
    }
  }
  else
  {
    for (int i = front; i < MAX_CAPACITY; i++)
    {
      printf("%d ", conveyor_belt[i]);
    }

    for (int i = 0; i <= rear; i++)
    {
      printf("%d ", conveyor_belt[i]);
    }
  }

  printf("\n\n");
}

int main()
{
  printf("====== Airport Baggage Handling Simulation ======\n\n");

  int num_bags;
  printf("Enter the number of bags to add to the conveyor belt: ");
  scanf("%d", &num_bags);

  for (int i = 0; i < num_bags; i++)
  {
    int tag;
    printf("\nEnter the tag number for baggage %d: ", i + 1);
    scanf("%d", &tag);
    addItemToBelt(tag);
  }

  displayConveyorBelt();

  printf("Removing baggage from conveyor belt...\n\n");

  while (front != -1)
  {
    removeItemFromBelt();
    displayConveyorBelt();
  }

  printf("\n\nSimulation complete!\n\n");

  return 0;
}