//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int rand_num()
{
    return rand() % 6 + 1;
}

// Function to roll the dice
void roll_dice()
{
    int dice1, dice2;
    srand(time(NULL));
    dice1 = rand_num();
    dice2 = rand_num();
    printf("Rolling the dice...\n");
    printf("Dice 1: %d\n", dice1);
    printf("Dice 2: %d\n", dice2);
    printf("Total: %d\n", dice1 + dice2);
}

int main()
{
    int choice;
    char ch;
    do
    {
        printf("Welcome to the Cyberpunk Dice Roller!\n\n");
        printf("1. Roll the dice\n2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                roll_dice();
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &ch);
    }
    while(ch == 'y' || ch == 'Y');
    return 0;
}