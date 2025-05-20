//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    int health = 100;
    int score = 0;
    int treasure = 0;
    int enemy = 0;

    srand(time(0));
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You are a brave adventurer on a quest to find the hidden treasure.\n");
    printf("Along the way, you will encounter various obstacles and enemies.\n");
    printf("Your goal is to find the treasure and return home safely.\n\n");

    while(1)
    {
        printf("You are in a dark, damp cave.\n");
        printf("To your left is a narrow passageway.\n");
        printf("To your right is a large, ominous door.\n");
        printf("What do you do?\n");
        printf("1. Go left\n");
        printf("2. Go right\n");
        printf("3. Stay put\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(rand() % 2 == 0)
                {
                    printf("You find a hidden passage that leads you deeper into the cave.\n");
                }
                else
                {
                    printf("You hit a dead end and have to turn back.\n");
                }
                break;

            case 2:
                if(rand() % 2 == 0)
                {
                    printf("The door is locked and you cannot open it.\n");
                }
                else
                {
                    printf("You open the door and find a room filled with treasure!\n");
                    treasure = 1;
                }
                break;

            case 3:
                printf("You decide to stay put for a while.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        if(treasure == 1 && enemy == 0)
        {
            printf("Congratulations! You have found the treasure and completed your quest.\n");
            printf("You return home safely with your newfound riches.\n");
            break;
        }
        else if(health <= 0)
        {
            printf("Game Over. You have lost all your health and must start over.\n");
            break;
        }
        else
        {
            printf("You continue on your journey...\n");
        }
    }

    return 0;
}