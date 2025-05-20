//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// define the size of the airport baggage conveyor belt
#define MAX_BAGS 50

// function prototypes
void addBaggage(int id);
void removeBaggage();
void displayBaggage();

// declare an integer array to store the baggage
int conveyorBelt[MAX_BAGS];

// declare variables to store the front and rear positions of the conveyor belt
int front = -1;
int rear = -1;

int main()
{
    // declare variables to store user input
    int choice, id;
    bool running = true;

    printf("***Airport Baggage Handling Simulation***\n\n");

    while (running)
    {
        // display menu
        printf("1. Add baggage\n");
        printf("2. Remove baggage\n");
        printf("3. Display baggage\n");
        printf("4. Quit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                // ask user for baggage id
                printf("\nEnter baggage ID: ");
                scanf("%d", &id);
                addBaggage(id);
                break;
            case 2:
                removeBaggage();
                break;
            case 3:
                displayBaggage();
                break;
            case 4:
                running = false;
                printf("\nProgram terminated.\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}

void addBaggage(int id)
{
    // check if conveyor belt is full
    if (rear == MAX_BAGS - 1)
    {
        printf("\nConveyor belt is full.\n");
    }
    // if conveyor belt is not full, add baggage to rear of the belt
    else
    {
        if (front == -1)
        {
            front = 0;
        }        
        rear++;
        conveyorBelt[rear] = id;
        printf("\nBaggage with ID %d added to conveyor belt.\n", id);
    }
}

void removeBaggage()
{
    // check if conveyor belt is empty
    if (front == -1 || front > rear)
    {
        printf("\nNo baggage on conveyor belt.\n");
    }
    // if conveyor belt is not empty, remove baggage from front of the belt
    else
    {
        printf("\nBaggage with ID %d removed from conveyor belt.\n", conveyorBelt[front]);
        front++;
    }
}

void displayBaggage()
{
    // check if conveyor belt is empty
    if (front == -1)
    {
        printf("\nNo baggage on conveyor belt.\n");
    }
    // if conveyor belt is not empty, display all baggage IDs on the belt
    else
    {
        printf("\nBaggage on conveyor belt: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", conveyorBelt[i]);
        }
        printf("\n");
    }
}