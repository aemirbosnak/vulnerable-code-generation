//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <string.h>

int main()
{
    char player_name[20];
    int choice;

    printf("Welcome to the Adventure Game!\n");
    printf("Enter your name: ");
    scanf("%s", player_name);

    printf("Hello, %s! Let's begin.\n", player_name);

    printf("You find yourself in a dark forest. There are two paths in front of you.\n");
    printf("Which one do you choose?\n");
    printf("1. Left\n");
    printf("2. Right\n");

    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("You chose the left path. As you walk along the path, you suddenly come across a river.\n");
        printf("What do you do?\n");
        printf("1. Try to cross the river\n");
        printf("2. Follow the river\n");

        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("You try to cross the river but it turns out to be too dangerous. You slip and fall in. Game Over!\n");
        }
        else if (choice == 2)
        {
            printf("You follow the river and soon you come across a village. You are safe for now. Congrats, you won the game!\n");
        }
        else
        {
            printf("Invalid choice. Game Over!\n");
        }
    }
    else if (choice == 2)
    {
        printf("You chose the right path. You soon find yourself at the entrance of a cave.\n");
        printf("What do you do?\n");
        printf("1. Enter the cave\n");
        printf("2. Return to the forest\n");

        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("You enter the cave and find a treasure chest. Congrats, you won the game!\n");
        }
        else if (choice == 2)
        {
            printf("You return to the forest but get lost. Game Over!\n");
        }
        else
        {
            printf("Invalid choice. Game Over!\n");
        }
    }
    else
    {
        printf("Invalid choice. Game Over!\n");
    }

    return 0;
}