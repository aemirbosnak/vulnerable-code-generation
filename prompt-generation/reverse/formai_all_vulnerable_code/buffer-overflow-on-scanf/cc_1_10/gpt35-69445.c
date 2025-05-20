//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void moveUp(int, int*, int*, int*);
void moveDown(int, int*, int*, int*);

int main()
{
    int n, floor = 0, dest, direction;
    char ch;

    printf("Enter the number of floors in the building: ");
    scanf("%d", &n);

    printf("\n");
    printf("--------------------------------------------------------------------\n");
    printf("|                          Welcome to Love Elevator                |\n");
    printf("--------------------------------------------------------------------\n");

    while(1)
    {
        printf("\n");
        printf("Current floor: %d\n", floor);

        printf("Select destination floor: ");
        scanf("%d", &dest);

        if(dest == floor)
        {
            printf("Elevator is already on the selected floor\n");
            continue;
        }

        direction = (dest > floor) ? 1 : -1;

        printf("Elevator moving...\n");

        if(direction == 1)
            moveUp(dest, &floor, &direction, &n);

        else
            moveDown(dest, &floor, &direction, &n);

        printf("\n");

        printf("Reached destination floor %d\n", floor);

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &ch);

        if(ch == 'n' || ch == 'N')
        {
            printf("\n--------------------------------------------------------------------\n");
            printf("|                             Please Visit Again                    |\n");
            printf("--------------------------------------------------------------------\n");
            break;
        }
    }

    return 0;
}

void moveUp(int dest, int *floor, int *direction, int *n)
{
    while(*floor != dest)
    {
        (*floor)++;
        printf("Floor: %d\n", *floor);

        if(*floor == *n)
        {
            printf("Elevator reached the top floor and can't go further up\n");
            (*floor)--;
            (*direction) = -1;
            break;
        }
    }
}

void moveDown(int dest, int *floor, int *direction, int *n)
{
    while(*floor != dest)
    {
        (*floor)--;
        printf("Floor: %d\n", *floor);

        if(*floor == 0)
        {
            printf("Elevator reached the ground floor and can't go further down\n");
            (*floor)++;
            (*direction) = 1;
            break;
        }
    }
}