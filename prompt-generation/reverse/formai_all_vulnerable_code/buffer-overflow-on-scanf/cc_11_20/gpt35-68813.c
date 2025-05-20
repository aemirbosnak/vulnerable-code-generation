//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main()
{
    char name[50];
    int age;
    int room = 1;
    char answer[50];

    printf("Welcome to the Text-Based Adventure Game! \n\n");
    printf("What is your name? ");
    scanf("%s", name);

    printf("\nHello, %s! How old are you? ", name);
    scanf("%d", &age);

    printf("\nGreat! Let's start the game! \n\n");

    while(room != 0)
    {
        if(room == 1)
        {
            printf("You find yourself in a forest. There are three paths in front of you. Which one will you take? \n\n");
            printf("1. The left path \n");
            printf("2. The middle path \n");
            printf("3. The right path \n\n");
            printf("Enter your choice: ");
            scanf("%s", answer);

            if(strcmp(answer, "1") == 0)
            {
                printf("\nYou encounter a group of goblins. They attack you and you die. Game Over!");
                room = 0;
            }
            else if(strcmp(answer, "2") == 0)
            {
                printf("\nYou find a treasure chest! Congrats, you have won the game!");
                room = 0;
            }
            else if(strcmp(answer, "3") == 0)
            {
                printf("\nYou see a beautiful waterfall. There is a cave behind it. Do you want to go in? \n\n");
                printf("1. Yes \n");
                printf("2. No \n\n");
                printf("Enter your choice: ");
                scanf("%s", answer);

                if(strcmp(answer, "1") == 0)
                {
                    printf("\nYou enter the cave and find a secret passage. You follow it and find the treasure chest! Congrats, you have won the game!");
                    room = 0;
                }
                else if(strcmp(answer, "2") == 0)
                {
                    printf("\nYou decide not to go in and continue on your adventure.");
                    room = 2;
                }
                else
                {
                    printf("\nInvalid input. Please enter 1 or 2.");
                }
            }
            else
            {
                printf("\nInvalid input. Please enter 1, 2, or 3.");
            }
        }
        else if(room == 2)
        {
            printf("\nYou come across a river. \n");
            printf("Do you: \n\n");
            printf("1. Build a raft and cross the river \n");
            printf("2. Try to swim across the river \n");
            printf("3. Follow the river downstream \n\n");
            printf("Enter your choice: ");
            scanf("%s", answer);

            if(strcmp(answer, "1") == 0)
            {
                printf("\nYou successfully build a raft and Cross the river. \n");
                room = 1;
            }
            else if(strcmp(answer, "2") == 0)
            {
                printf("\nYou try to swim across the river but the current is too strong. You drown. Game Over!");
                room = 0;
            }
            else if(strcmp(answer, "3") == 0)
            {
                printf("\nYou follow the river downstream and spot a bridge in the distance. \n");
                room = 3;
            }
            else
            {
                printf("\nInvalid input. Please enter 1, 2, or 3.");
            }
        }
        else if(room == 3)
        {
            printf("\nYou reach the bridge and see a guard. \n");
            printf("What do you do? \n\n");
            printf("1. Bribe the guard \n");
            printf("2. Fight the guard \n");
            printf("3. Try to sneak past the guard \n\n");
            printf("Enter your choice: ");
            scanf("%s", answer);

            if(strcmp(answer, "1") == 0)
            {
                printf("\nYou give the guard some gold and he lets you pass. You continue on your adventure. \n");
                room = 1;
            }
            else if(strcmp(answer, "2") == 0)
            {
                printf("\nYou try to fight the guard but he is too strong. You die. Game Over!");
                room = 0;
            }
            else if(strcmp(answer, "3") == 0)
            {
                printf("\nYou try to sneak past the guard but he catches you. You die. Game Over!");
                room = 0;
            }
            else
            {
                printf("\nInvalid input. Please enter 1, 2, or 3.");
            }
        }
    }
    
    printf("\nThank you for playing, %s! Come back soon!", name);

    return 0;
}