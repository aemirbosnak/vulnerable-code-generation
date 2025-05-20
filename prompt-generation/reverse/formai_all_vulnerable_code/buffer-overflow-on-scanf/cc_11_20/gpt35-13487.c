//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    int chosenRoom = 0;
    int ghostLocation = rand() % 5 + 1;
    int hasKey = 0;

    printf("\nWelcome to the Haunted House Simulator!\n\n");
    printf("You find yourself standing in front of a spooky mansion. You're not sure if you should enter, but something draws you inside.");

    while (chosenRoom != 7)
    {
        printf("\n\nYou're standing in the main hallway. You can see six doors. Which one do you want to enter?\n");
        printf("1 - Living Room\n");
        printf("2 - Kitchen\n");
        printf("3 - Bathroom\n");
        printf("4 - Master Bedroom\n");
        printf("5 - Basement\n");
        printf("6 - Attic\n");
        printf("7 - Exit the Haunted House\n\n");

        scanf("%d", &chosenRoom);

        switch (chosenRoom)
        {
            case 1:
                printf("\nYou entered the Living Room.\n");
                if (ghostLocation == 1)
                {
                    printf("BOO! You just encountered a ghost!\n");
                    printf("GAME OVER!\n");
                    return 0;
                }
                break;
            case 2:
                printf("\nYou entered the Kitchen.\n");
                if (ghostLocation == 2)
                {
                    printf("BOO! You just encountered a ghost!\n");
                    printf("GAME OVER!\n");
                    return 0;
                }
                break;
            case 3:
                printf("\nYou entered the Bathroom.\n");
                if (ghostLocation == 3)
                {
                    printf("BOO! You just encountered a ghost!\n");
                    printf("GAME OVER!\n");
                    return 0;
                }
                break;
            case 4:
                printf("\nYou entered the Master Bedroom.\n");
                if (ghostLocation == 4)
                {
                    printf("BOO! You just encountered a ghost!\n");
                    printf("GAME OVER!\n");
                    return 0;
                }
                else if (hasKey == 0)
                {
                    hasKey = 1;
                    printf("You found a key!\n");
                }
                break;
            case 5:
                printf("\nYou entered the Basement.\n");
                if (ghostLocation == 5)
                {
                    printf("BOO! You just encountered a ghost!\n");
                    printf("GAME OVER!\n");
                    return 0;
                }
                break;
            case 6:
                printf("\nYou entered the Attic.\n");
                if (hasKey == 0)
                {
                    printf("The door is locked. You need a key to enter here.\n");
                }
                else
                {
                    printf("You found a treasure chest!\n");
                    printf("You're rich! Congratulations!\n");
                    return 0;
                }
                break;
            case 7:
                printf("\nYou decided to leave the Haunted House. Hope you had a good time!\n");
                break;
            default:
                printf("\nInvalid choice, try again.\n");
                break;
        }
    }

    return 0;
}