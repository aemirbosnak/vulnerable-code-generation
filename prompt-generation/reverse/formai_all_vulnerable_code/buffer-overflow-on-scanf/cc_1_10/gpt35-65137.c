//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMenu()
{
    printf("\n\nWelcome to the Haunted House Simulator!\n");
    printf("======================================\n");
    printf("1. Walk into the Haunted House\n");
    printf("2. Leave the Haunted House\n");
    printf("======================================\n");
    printf("Enter your choice (1 or 2): ");
}

void printInside()
{
    printf("\nYou enter the Haunted House.\n");
    printf("As you walk inside, you hear a creaking noise and feel a cold wind on your face.\n");
    printf("You look around and see old and dusty furniture, cobwebs, and cracked windows.\n");
    printf("Suddenly, something grabs your arm and you feel a chill run down your spine...\n\n");
}

void printExit()
{
    printf("\nYou exit the Haunted House...\n");
    printf("As you walk away, you look back and see the old and creepy house, and wonder what secrets it holds...\n\n");
}

int main()
{
    int choice;
    srand(time(NULL));
    int randomNumber = rand() % 10 + 1;

    while(1)
    {
        printMenu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printInside();
                if(randomNumber <= 5)
                {
                    printf("You hear a loud scream and see a ghostly figure in front of you!\n");
                }
                else
                {
                    printf("You hear a strange noise and see a shadow moving in the corner of your eye...\n");
                }
                break;

            case 2:
                printExit();
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}