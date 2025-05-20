//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Invasive Adventure Game!\n");

    //Initialize variables
    int invasionLevel = 0;
    char answer[10];

    //Ask for player name
    printf("What is your name?\n");
    char name[20];
    scanf("%s", name);

    printf("Hi %s! You wake up to find that your city is being invaded by aliens.\n", name);

    //Ask player if they want to fight or flee
    printf("Do you want to fight or flee?\n");
    scanf("%s", answer);

    if(strcmp(answer, "fight")==0)
    {
        invasionLevel += 10;
        printf("You have successfully fought off the first wave of aliens!\n");
    }
    else
    {
        printf("You flee from the aliens but your invasion level has increased by 5.\n");
        invasionLevel += 5;
    }

    //Ask player if they want to find allies or go solo
    printf("Do you want to find allies or go solo?\n");
    scanf("%s", answer);

    if(strcmp(answer, "allies")==0)
    {
        invasionLevel += 7;
        printf("You have found a group of allies and together you are able to fend off the aliens!\n");
    }
    else
    {
        printf("You decide to go solo but it proves to be too difficult - your invasion level increases by 10.\n");
        invasionLevel += 10;
    }

    //Ask player if they want to take the fight to the aliens or defend their city
    printf("Do you want to take the fight to the aliens or defend your city?\n");
    scanf("%s", answer);

    if(strcmp(answer, "take")==0)
    {
        invasionLevel += 15;
        printf("You launch a surprise attack on the aliens and successfully defeat them - congratulations, you have saved your city!\n");
    }
    else
    {
        printf("You defend your city but it takes a heavy toll - your invasion level increases by 20.\n");
        invasionLevel += 20;
    }

    //Display final results
    if(invasionLevel >= 30)
    {
        printf("Oh no %s, the aliens have successfully invaded your city. Better luck next time.", name);
    }
    else
    {
        printf("Congratulations %s, you have successfully defended your city against the alien invasion!", name);
    }

    return 0;
}