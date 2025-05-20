//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char name[20];
    int choice;

    //player introduction
    printf("Welcome to the Dark Forest Adventure Game!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello %s. You are lost in a dark forest and need to find your way back home.\n", name);

    //game introduction
    printf("\nYou start walking and you come across a fork in the road.\n");
    printf("Which way do you choose?\n");
    printf("1. Left\n");
    printf("2. Right\n");
    scanf("%d", &choice);

    //chance of death
    if(choice == 1)
    {
        printf("\nYou have chosen to go left.\n");
        printf("You continue on, but soon you realize that the forest is getting thicker and the air is getting colder.\n");
        printf("You feel like you are being followed.. but before you can turn around, a pack of wolves jumps out and attacks you.\n");
        printf("You have died.\n");
    }
    else if(choice == 2)
    {
        printf("\nYou have chosen to go right.\n");
        printf("You continue on, but soon you realize that the forest is getting darker and you cannot see what is in front of you.\n");
        printf("You hear a faint noise in the distance. It sounds like singing..\n");
        printf("Do you follow the noise?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &choice);

        //chance of death
        if(choice == 1)
        {
            printf("\nYou have chosen to follow the noise.\n");
            printf("You walk towards the noise and soon you come across a group of people singing and dancing around a fire.\n");
            printf("You approach them, but as you get closer you realize that they are not human.. they are creatures with horns and fangs.\n");
            printf("Before you can turn around, they grab you and offer you as a sacrifice to their god.\n");
            printf("You have died.\n");
        }
        else if(choice == 2)
        {
            printf("\nYou have chosen to not follow the noise.\n");
            printf("You continue on and soon you come across a small cabin in the woods.\n");
            printf("Do you enter the cabin?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);

            //chance of death
            if(choice == 1)
            {
                printf("\nYou have chosen to enter the cabin.\n");
                printf("You walk inside and there is an old woman sitting by the fire.\n");
                printf("She offers you a warm meal and a bed for the night.\n");
                printf("Do you accept her offer?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d", &choice);

                if(choice == 1)
                {
                    printf("\nYou have chosen to accept the old woman's offer.\n");
                    printf("You eat the warm meal and rest in the bed for the night.\n");
                    printf("In the morning, the old woman shows you the way out of the forest and you make it back home safely.\n");
                    printf("Congratulations %s, you have completed the Dark Forest Adventure Game!\n", name);
                }
                else if(choice == 2)
                {
                    printf("\nYou have chosen to not accept the old woman's offer.\n");
                    printf("You continue on through the forest and soon you come across a pack of wolves.\n");
                    printf("They attack you and you have died.\n");
                }
            }
            else if(choice == 2)
            {
                printf("\nYou have chosen to not enter the cabin.\n");
                printf("You continue on through the forest and soon you come across a pack of wolves.\n");
                printf("They attack you and you have died.\n");
            }
        }
    }

    return 0;
}