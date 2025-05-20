//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void displayScene(int);
int main(){
    int choice,randNum;
    srand(time(NULL));
    printf("\n\n\t\t\tWelcome to the Medieval Adventure Game!\n\n");
    printf("You are a brave knight who is on a mission to save the princess from the evil king.\n");
    printf("You are currently standing at the entrance of the castle.\n");
    printf("Choose a number between 1 and 3 to decide which path to take: ");
    scanf("%d",&choice);
    randNum=rand()%3+1;
    if(choice==randNum){
        printf("\nYou have chosen wisely and your path is clear!\n");
        printf("You have successfully entered the castle!\n");
        printf("You are now in the courtyard facing the castle entrance.\n\n");
        displayScene(1);
        printf("Choose a number between 1 and 3 to decide which direction to take: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("\nYou have decided to take the left path\n");
            displayScene(2);
            printf("Choose a number between 1 and 3 to decide which path to take: ");
            scanf("%d",&choice);
            if(choice==2){
                printf("\nYou have chosen wisely and have avoided the traps!\n");
                displayScene(3);
                printf("Suddenly you hear the sound of footsteps approaching. Do you want to:\n");
                printf("1. Hide behind the boulder.\n");
                printf("2. Confront the person.\n");
                printf("Enter your choice: ");
                scanf("%d",&choice);
                if(choice==1){
                    printf("\nYou have successfully evaded the person and moved ahead!\n");
                    printf("You are finally at the entrance of the room where the princess is kept!\n\n");
                    displayScene(5);
                    printf("You have to fight the guard and free the princess!\n");
                    printf("Do you want to:\n");
                    printf("1. Attack the guard.\n");
                    printf("2. Sneak up behind the guard and knock him out.\n");
                    printf("Enter your choice: ");
                    scanf("%d",&choice);
                    if(choice==2){
                        printf("\nYou have successfully freed the princess and saved her from the evil king!\n\n");
                        displayScene(6);
                        printf("Thanks for playing the Medieval Adventure Game!\n");
                    }
                    else{
                        printf("\nYou fought bravely, but unfortunately you were not able to save the princess!\n");
                        printf("Better luck next time!\n\n");
                        displayScene(7);
                    }
                }
                else{
                    printf("\nYou have been caught and now you are the prisoner of the king!\n");
                    printf("GAME OVER\n\n");
                    displayScene(7);
                }
            }
            else{
                printf("\nOops! You fell into a trap and you have been captured!\n");
                printf("GAME OVER\n\n");
                displayScene(4);
            }
        }
        else{
            printf("\nYou have decided to take the right path\n");
            displayScene(2);
            printf("Choose a number between 1 and 3 to decide which path to take: ");
            scanf("%d",&choice);
            if(choice==1){
                printf("\nYou have fallen into a trap and have been captured by the evil king!\n");
                printf("GAME OVER\n\n");
                displayScene(4);
            }
            else{
                printf("\nYou have chosen wisely and have avoided the traps!\n\n");
                displayScene(3);
                printf("Suddenly you hear the sound of footsteps approaching. Do you want to:\n");
                printf("1. Hide behind the boulder.\n");
                printf("2. Confront the person.\n");
                printf("Enter your choice: ");
                scanf("%d",&choice);
                if(choice==1){
                    printf("\nYou have successfully evaded the person and moved ahead!\n");
                    printf("You are finally at the entrance of the room where the princess is kept!\n\n");
                    displayScene(5);
                    printf("You have to fight the guard and free the princess!\n");
                    printf("Do you want to:\n");
                    printf("1. Attack the guard.\n");
                    printf("2. Sneak up behind the guard and knock him out.\n");
                    printf("Enter your choice: ");
                    scanf("%d",&choice);
                    if(choice==2){
                        printf("\nYou have successfully freed the princess and saved her from the evil king!\n\n");
                        displayScene(6);
                        printf("Thanks for playing the Medieval Adventure Game!\n");
                    }
                    else{
                        printf("\nYou fought bravely, but unfortunately you were not able to save the princess!\n");
                        printf("Better luck next time!\n\n");
                        displayScene(7);
                    }
                }
                else{
                    printf("\nYou have been caught and now you are the prisoner of the king!\n");
                    printf("GAME OVER\n\n");
                    displayScene(7);
                }
            }
        }
    }
    else{
        printf("\nOops! You have chosen the wrong path and have fallen into a trap.\n");
        printf("GAME OVER\n\n");
        displayScene(4);
    }
    return 0;
}
void displayScene(int sceneNum){
    switch(sceneNum){
        case 1: printf("\n***********************************");
                printf("\n*          Castle Entrance        *");
                printf("\n***********************************\n");
                break;
        case 2: printf("\n***********************************");
                printf("\n*            Courtyard           *");
                printf("\n***********************************\n");
                break;
        case 3: printf("\n***********************************");
                printf("\n*             Corridor           *");
                printf("\n***********************************\n");
                break;
        case 4: printf("\n***********************************");
                printf("\n*           Trapped Room         *");
                printf("\n***********************************\n");
                break;
        case 5: printf("\n***********************************");
                printf("\n*           Guarded Room         *");
                printf("\n***********************************\n");
                break;
        case 6: printf("\n***********************************");
                printf("\n*         Successful Ending      *");
                printf("\n***********************************\n");
                break;
        case 7: printf("\n***********************************");
                printf("\n*           Unsuccessful Ending  *");
                printf("\n***********************************\n");
                break;
        default: printf("\nUnknown Scene!\n");
    }
}