//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char playerName[20];
    int choice;
    
    printf("Welcome to the adventure game!\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("Hello %s, let's begin!\n", playerName);
    printf("You wake up in a forest...\n");
    printf("What do you want to do?\n");
    printf("1. Explore the forest.\n");
    printf("2. Make a shelter.\n");
    printf("3. Wait for help.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("\nAs you explore the forest, you stumble upon a river.\n");
            printf("What do you want to do?\n");
            printf("1. Cross the river.\n");
            printf("2. Follow the river downstream.\n");
            printf("3. Return to the forest.\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            
            if(choice == 1){
                printf("\nYou try to cross the river but the current is too strong.\n");
                printf("You are swept downstream and hit your head on a rock.\n");
                printf("You die instantly.\n");
            }
            else if(choice == 2){
                printf("\nYou follow the river downstream and come across a village.\n");
                printf("Congratulations! You have survived!\n");
            }
            else if(choice == 3){
                printf("\nYou return to the forest and continue wandering aimlessly.\n");
                printf("You eventually die of starvation and thirst.\n");
            }
            else{
                printf("\nInvalid choice! Restart the game to try again.\n");
            }
            break;

        case 2:
            printf("\nYou gather some branches and leaves and make a shelter.\n");
            printf("The shelter is not very comfortable but it will do for now.\n");
            printf("What do you want to do?\n");
            printf("1. Go out and explore.\n");
            printf("2. Stay in the shelter.\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if(choice == 1){
                printf("\nAs you explore the forest, you stumble upon a river.\n");
                printf("What do you want to do?\n");
                printf("1. Cross the river.\n");
                printf("2. Follow the river downstream.\n");
                printf("3. Return to the shelter.\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if(choice == 1){
                    printf("\nYou try to cross the river but the current is too strong.\n");
                    printf("You are swept downstream and hit your head on a rock.\n");
                    printf("You die instantly.\n");
                }
                else if(choice == 2){
                    printf("\nYou follow the river downstream and come across a village.\n");
                    printf("Congratulations! You have survived!\n");
                }
                else if(choice == 3){
                    printf("\nYou return to the shelter and wait for help.\n");
                    printf("Days turn into weeks and weeks turn into months but no help arrives.\n");
                    printf("You eventually die of old age and loneliness.\n");
                }
                else{
                    printf("\nInvalid choice! Restart the game to try again.\n");
                }
            }
            else if(choice == 2){
                printf("\nYou stay in the shelter and wait for help.\n");
                printf("Days turn into weeks and weeks turn into months but no help arrives.\n");
                printf("You eventually die of old age and loneliness.\n");
            }
            else{
                printf("\nInvalid choice! Restart the game to try again.\n");
            }
            break;

        case 3:
            printf("\nYou wait for help but no one arrives.\n");
            printf("Days turn into weeks and weeks turn into months but no help arrives.\n");
            printf("You eventually die of old age and loneliness.\n");
            break;

        default:
            printf("\nInvalid choice! Restart the game to try again.\n");
            break;
    }

    printf("\nThanks for playing!\n");
    return 0;
}