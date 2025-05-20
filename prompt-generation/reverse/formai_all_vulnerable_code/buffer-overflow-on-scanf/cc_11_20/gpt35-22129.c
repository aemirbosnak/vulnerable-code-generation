//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int choice, outcome;
    char name[20];
    srand(time(NULL));

    printf("Welcome to the adventure game!\n");
    printf("What's your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s!\n", name);
    printf("You find yourself in a dark, creepy forest.\n");
    printf("What would you like to do?\n");
    printf("1. Walk deeper into the forest.\n");
    printf("2. Look for a way out of the forest.\n");
    printf("3. Build a shelter and stay the night.\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("You continue walking deeper into the forest.\n");
            printf("Suddenly, you hear a loud growl.\n");
            outcome = rand() % 3;
            if(outcome == 0){
                printf("A bear attacks you and you lose the game.\n");
            }
            else{
                printf("You manage to avoid the bear and continue on your journey.\n");
                printf("You come across a river.\n");
                printf("What would you like to do?\n");
                printf("1. Try to cross the river.\n");
                printf("2. Follow the river downstream.\n");
                scanf("%d", &choice);
                if(choice == 1){
                    outcome = rand() % 2;
                    if(outcome == 0){
                        printf("You successfully cross the river.\n");
                        printf("Congratulations! You've won the game!\n");
                    }
                    else{
                        printf("You fall in the river and drown. Game over.\n");
                    }
                }
                else if(choice == 2){
                    printf("You follow the river downstream and eventually reach civilization.\n");
                    printf("Congratulations! You've won the game!\n");
                }
                else{
                    printf("Invalid choice. Game over.\n");
                }
            }
            break;

        case 2:
            printf("You look for a way out of the forest.\n");
            printf("After wandering for hours, you come across a road.\n");
            printf("What would you like to do?\n");
            printf("1. Follow the road.\n");
            printf("2. Stay in the forest.\n");
            scanf("%d", &choice);
            if(choice == 1){
                printf("You follow the road and eventually reach civilization.\n");
                printf("Congratulations! You've won the game!\n");
            }
            else if(choice == 2){
                printf("You continue wandering in the forest and get lost.\n");
                printf("Game over.\n");
            }
            else{
                printf("Invalid choice. Game over.\n");
            }
            break;

        case 3:
            printf("You build a shelter and stay the night.\n");
            printf("In the middle of the night, you hear strange noises.\n");
            outcome = rand() % 2;
            if(outcome == 0){
                printf("You're attacked by wolves and lose the game.\n");
            }
            else{
                printf("The noises turn out to be harmless.\n");
                printf("You wake up the next morning and continue on your journey.\n");
                printf("You come across a river.\n");
                printf("What would you like to do?\n");
                printf("1. Try to cross the river.\n");
                printf("2. Follow the river downstream.\n");
                scanf("%d", &choice);
                if(choice == 1){
                    outcome = rand() % 2;
                    if(outcome == 0){
                        printf("You successfully cross the river.\n");
                        printf("Congratulations! You've won the game!\n");
                    }
                    else{
                        printf("You fall in the river and drown. Game over.\n");
                    }
                }
                else if(choice == 2){
                    printf("You follow the river downstream and eventually reach civilization.\n");
                    printf("Congratulations! You've won the game!\n");
                }
                else{
                    printf("Invalid choice. Game over.\n");
                }
            }
            break;

        default:
            printf("Invalid choice. Game over.\n");
            break;
    }

    return 0;
}