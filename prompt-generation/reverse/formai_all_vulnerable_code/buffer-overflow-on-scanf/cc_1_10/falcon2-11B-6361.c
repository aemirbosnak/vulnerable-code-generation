//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
    int choice;
    int i;
    char player_name[20];
    
    printf("Welcome to the Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s",player_name);
    printf("Hello %s!\n",player_name);
    
    printf("\nThe game begins...\n");
    printf("\nYou find yourself in a dark forest. You hear rustling in the bushes nearby. What do you do?\n");
    printf("1. Go towards the sound\n");
    printf("2. Stay put\n");
    
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\nYou stumble upon a friendly rabbit. He asks for your help.\n");
        printf("1. Help him\n");
        printf("2. Ignore him\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\nYou help the rabbit. He leads you to a hidden treasure.\n");
            printf("Congratulations! You won the game.\n");
            exit(0);
        }
        else if(choice==2)
        {
            printf("\nThe rabbit disappears and you hear a low growl. A bear appears and attacks you.\n");
            printf("You die.\n");
            exit(0);
        }
        else
        {
            printf("\nInvalid choice.\n");
        }
    }
    else if(choice==2)
    {
        printf("\nYou sit and wait. Suddenly, a group of wolves appears and attacks you.\n");
        printf("You die.\n");
        exit(0);
    }
    else
    {
        printf("\nInvalid choice.\n");
    }
    return 0;
}