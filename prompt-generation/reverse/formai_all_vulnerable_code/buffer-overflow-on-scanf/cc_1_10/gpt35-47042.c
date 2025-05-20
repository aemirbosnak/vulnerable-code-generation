//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice, count = 0;
    srand(time(0));
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You are standing in front of a large, old house.\n");
    printf("What do you want to do?\n");
    printf("1. Knock on the door\n");
    printf("2. Walk around the house\n");
    printf("3. Run away\n");
    printf("Please enter your choice: ");

    scanf("%d", &choice);

    if (choice == 1) {
        printf("You knock on the door and it slowly creaks open.\n");
        printf("Do you want to go inside?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("As you enter the house, you notice that it is very dark and spooky.\n");
            printf("The door slams shut behind you and you hear a loud noise coming from upstairs.\n");
            printf("Do you want to go upstairs to investigate?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("Please enter your choice: ");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("As you climb the stairs, you feel a cold breeze.\n");
                printf("You reach the top of the stairs and find a room with a ghostly figure.\n");
                printf("The ghostly figure seems to be trapped and needs your help.\n");
                printf("Do you want to help the ghost?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                printf("Please enter your choice: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("Congratulations! You have helped the ghost find peace!\n");
                }
                else {
                    printf("You run out of the house scared to death!\n");
                }
            }
            else {
                printf("You hear strange noises, and run out of the house!\n");
            }
        }
        else {
            printf("You run away scared to death!\n");
        }

    }
    else if (choice == 2) {
        printf("You walk around the house and find a creepy graveyard.\n");
        printf("Do you want to explore the graveyard?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("As you walk through the graveyard, you hear strange noises.\n");
            printf("You notice that the graves are shaking, and then zombies start to rise up!\n");
            printf("Do you want to fight the zombies or run away?\n");
            printf("1. Fight\n");
            printf("2. Run away\n");
            printf("Please enter your choice: ");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You fight the zombies with all your might and win!\n");
            }
            else {
                printf("You run away scared to death!\n");
            }
        }
        else {
            printf("You go back to your car and drive away scared to death!\n");
        }
    }
    else {
        printf("You run away from the house scared to death!\n");
    }

    return 0;
}