//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int choice;
    int computer_choice;

    srand(time(0));

    printf("Welcome to the Rock-Paper-Scissors Game!\n");
    printf("Please choose your option:\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            computer_choice = rand() % 3 + 1;
            break;
        case 2:
            computer_choice = 2;
            break;
        case 3:
            computer_choice = rand() % 2 + 3;
            break;
        default:
            computer_choice = rand() % 3 + 1;
    }

    printf("Computer's choice: %d\n", computer_choice);

    if(choice == computer_choice)
    {
        printf("It's a draw!\n");
    }
    else if(choice == 1 && computer_choice == 3)
    {
        printf("You win!\n");
    }
    else if(choice == 2 && computer_choice == 1)
    {
        printf("You win!\n");
    }
    else if(choice == 3 && computer_choice == 2)
    {
        printf("You win!\n");
    }
    else
    {
        printf("You lose!\n");
    }

    return 0;
}