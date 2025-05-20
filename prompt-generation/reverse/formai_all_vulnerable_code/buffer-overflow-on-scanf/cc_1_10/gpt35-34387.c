//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main()
{
    char playerName[50];
    int playerAge;
    char location[50];

    printf("Welcome to the peaceful adventure game!\n");
    printf("What is your name?\n");
    scanf("%s", playerName);

    printf("Nice to meet you, %s!\n", playerName);
    printf("How old are you?\n");
    scanf("%d", &playerAge);

    printf("You are %d years old. Let's begin our journey.\n", playerAge);
    printf("You find yourself in a peaceful countryside surrounded by trees, with a beautiful river flowing nearby.\n");
    printf("Where do you want to go? (Type 'river' or 'trees')\n");
    scanf("%s", location);

    if(strcmp(location, "river") == 0)
    {
        printf("You walk towards the river and sit down by the bank.\n");
        printf("You see a school of fish swimming in the water.\n");
        printf("Do you want to go for a swim? (Type 'yes' or 'no')\n");
        char swimChoice[3];
        scanf("%s", swimChoice);

        if(strcmp(swimChoice, "yes") == 0)
        {
            printf("You jump into the water and feel refreshed.\n");
            printf("The fish swim away from you, but you catch a glimpse of a shiny object.\n");
            printf("Do you want to investigate? (Type 'yes' or 'no')\n");
            char objectChoice[3];
            scanf("%s", objectChoice);

            if(strcmp(objectChoice, "yes") == 0)
            {
                printf("You swim towards the object and find a beautiful gold ring.\n");
                printf("Congratulations, you found treasure!\n");
            }
            else
            {
                printf("You continue to enjoy your swim.\n");
            }
        }
        else
        {
            printf("You decide to enjoy the scenery without going for a swim.\n");
        }
    }
    else if(strcmp(location, "trees") == 0)
    {
        printf("You walk towards the trees and sit down under a tall oak.\n");
        printf("You hear the song of birds and the rustling of leaves.\n");
        printf("Do you want to take a nap? (Type 'yes' or 'no')\n");
        char napChoice[3];
        scanf("%s", napChoice);

        if(strcmp(napChoice, "yes") == 0)
        {
            printf("You fall asleep and have a peaceful dream.\n");
            printf("You wake up feeling refreshed.\n");
            printf("You notice a squirrel staring at you.\n");
            printf("Do you want to feed it? (Type 'yes' or 'no')\n");
            char squirrelChoice[3];
            scanf("%s", squirrelChoice);

            if(strcmp(squirrelChoice, "yes") == 0)
            {
                printf("You share your sandwich with the squirrel.\n");
                printf("It looks happy and runs away.\n");
            }
            else
            {
                printf("You enjoy the company of the squirrel, but decide not to feed it.\n");
            }
        }
        else
        {
            printf("You decide to enjoy the scenery without taking a nap.\n");
        }
    }
    else
    {
        printf("I'm sorry, I don't understand where you want to go.\n");
    }

    return 0;
}