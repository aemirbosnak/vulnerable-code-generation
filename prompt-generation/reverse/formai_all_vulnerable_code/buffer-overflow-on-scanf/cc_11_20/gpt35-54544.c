//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <string.h>

int main()
{
    char name[20];
    int choice;
    int health = 100;
    
    printf("Welcome to the adventure game. What is your name?\n");
    scanf("%s", name);
    printf("Hello %s, are you ready to begin your adventure?\n", name);

    printf("1. Yes\n");
    printf("2. No\n");

    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Great! Let's begin...\n");

        printf("You are in a dark forest. You see a path to your left and a path to your right. Which way do you go?\n");

        printf("1. Left\n");
        printf("2. Right\n");

        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("You walk down the left path and come across a river. Do you cross the river or follow the path along the river?\n");

            printf("1. Cross the river\n");
            printf("2. Follow the path\n");

            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("You successfully cross the river and continue on your journey. You come across a group of bandits. What do you do?\n");

                printf("1. Fight the bandits\n");
                printf("2. Try to sneak past\n");

                scanf("%d", &choice);

                if(choice == 1)
                {
                    printf("You fight the bandits and emerge victorious. However, you were wounded in the battle and lose 20 health points. You have %d health points left.\n", health-20);
                }
                else if(choice == 2)
                {
                    printf("You try to sneak past the bandits but they catch you. You have to fight them and lose 30 health points. You have %d health points left.\n", health-30);
                }
            }
            else if(choice == 2)
            {
                printf("You follow the path along the river and come across a hidden cave. Do you enter the cave or continue on the path?\n");

                printf("1. Enter the cave\n");
                printf("2. Continue on the path\n");

                scanf("%d", &choice);

                if(choice == 1)
                {
                    printf("You enter the cave and find a chest full of gold. Congratulations, you win the game!\n");
                }
                else if(choice == 2)
                {
                    printf("You continue on the path and come across a group of bandits. What do you do?\n");

                    printf("1. Fight the bandits\n");
                    printf("2. Try to sneak past\n");

                    scanf("%d", &choice);

                    if(choice == 1)
                    {
                        printf("You fight the bandits and emerge victorious. However, you were wounded in the battle and lose 20 health points. You have %d health points left.\n", health-20);
                    }
                    else if(choice == 2)
                    {
                        printf("You try to sneak past the bandits but they catch you. You have to fight them and lose 30 health points. You have %d health points left.\n", health-30);
                    }
                }
            }
        }
        else if(choice == 2)
        {
            printf("You walk down the right path and come across a group of bandits. What do you do?\n");

            printf("1. Fight the bandits\n");
            printf("2. Try to sneak past\n");

            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("You fight the bandits and emerge victorious. However, you were wounded in the battle and lose 20 health points. You have %d health points left.\n", health-20);
            }
            else if(choice == 2)
            {
                printf("You try to sneak past the bandits but they catch you. You have to fight them and lose 30 health points. You have %d health points left.\n", health-30);
            }
        }
    }
    else if(choice == 2)
    {
        printf("Maybe next time. Goodbye.\n");
    }
    else
    {
        printf("I'm sorry, that's not a valid choice. Please try again.\n");
    }

    return 0;
}