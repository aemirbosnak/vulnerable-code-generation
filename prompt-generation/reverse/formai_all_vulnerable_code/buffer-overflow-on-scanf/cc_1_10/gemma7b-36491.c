//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char name[20];
    int health = 100;
    int room = 1;

    printf("Welcome to the Text-Based Adventure Game, %s!\n", name);
    printf("You are in Room %d.\n", room);

    while (health > 0)
    {
        // Display available options
        printf("Please choose an option:\n");
        printf("1. Go north\n");
        printf("2. Go south\n");
        printf("3. Go east\n");
        printf("4. Go west\n");

        // Get the user's choice
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice)
        {
            case 1:
                room++;
                printf("You traveled north to Room %d.\n", room);
                break;
            case 2:
                room--;
                printf("You traveled south to Room %d.\n", room);
                break;
            case 3:
                printf("You traveled east, but there is nothing there.\n");
                break;
            case 4:
                printf("You traveled west, but there is nothing there.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Check if the user has won or lost
        if (room == 5)
        {
            printf("Congratulations, you have won the game!\n");
            health = 0;
        }
        else if (health < 0)
        {
            printf("You have lost the game. Game Over!\n");
            health = 0;
        }
    }

    return 0;
}