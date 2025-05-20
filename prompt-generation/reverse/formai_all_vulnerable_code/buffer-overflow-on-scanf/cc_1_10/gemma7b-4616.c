//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, score = 0;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Welcome to the Dungeon of Doom, %s! Prepare for a quest!", name);

    while (1)
    {
        printf("\nWhat would you like to do? (1) Attack, (2) Defend, (3) Cast Spell, (4) Retreat:");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("You attacked the enemy. You dealt %d damage.", score);
                score++;
                break;
            case 2:
                printf("You defended against the enemy. You avoided damage.");
                break;
            case 3:
                printf("You cast a spell on the enemy. You inflicted %d damage.", score);
                score++;
                break;
            case 4:
                printf("You retreated. You left the dungeon.");
                break;
            default:
                printf("Invalid input. Please try again.");
        }

        if (score >= 5)
        {
            printf("Congratulations, %s! You have defeated the boss and saved the world!", name);
            break;
        }

        if (choice == 4)
        {
            printf("Are you sure you want to retreat? (Y/N)");
            char confirm;
            scanf(" %c", &confirm);

            if (confirm == 'Y')
            {
                printf("You retreated. You left the dungeon.");
                break;
            }
        }
    }

    return;
}