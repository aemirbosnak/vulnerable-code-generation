//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char name[20];
    char location = 'A';

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while (location != 'F')
    {
        switch (location)
        {
            case 'A':
                printf("You are in the forest.\n");
                printf("You see a clearing ahead.\n");
                printf("You see a path to the right and a path to the left.\n");
                printf("What do you want to do? (1 for right, 2 for left): ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    location = 'B';
                }
                else if (choice == 2)
                {
                    location = 'C';
                }
                else
                {
                    printf("Invalid input.\n");
                }
                break;

            case 'B':
                printf("You are in the clearing.\n");
                printf("You see a tree in the center of the clearing.\n");
                printf("You see a path to the front and a path to the right.\n");
                printf("What do you want to do? (1 for front, 2 for right): ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    location = 'E';
                }
                else if (choice == 2)
                {
                    location = 'A';
                }
                else
                {
                    printf("Invalid input.\n");
                }
                break;

            case 'C':
                printf("You are on the path to the left.\n");
                printf("You see a bridge ahead.\n");
                printf("You see a path to the right and a path to the back.\n");
                printf("What do you want to do? (1 for right, 2 for back): ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    location = 'D';
                }
                else if (choice == 2)
                {
                    location = 'B';
                }
                else
                {
                    printf("Invalid input.\n");
                }
                break;

            case 'D':
                printf("You are on the bridge.\n");
                printf("You see the finish line ahead.\n");
                printf("You have won the game!\n");
                location = 'F';
                break;

            case 'E':
                printf("You are at the tree.\n");
                printf("You see a path to the right and a path to the back.\n");
                printf("What do you want to do? (1 for right, 2 for back): ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    location = 'F';
                }
                else if (choice == 2)
                {
                    location = 'B';
                }
                else
                {
                    printf("Invalid input.\n");
                }
                break;
        }
    }

    return 0;
}