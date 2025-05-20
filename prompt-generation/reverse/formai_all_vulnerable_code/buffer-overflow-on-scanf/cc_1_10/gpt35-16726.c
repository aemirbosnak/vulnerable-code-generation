//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds){
    int milliSeconds = 1000 * seconds;
    clock_t startTime = clock();
    while((clock() - startTime) < milliSeconds){}
}

int main(){
    srand(time(NULL));
    int ghostPosition = 0;
    int playerPosition = 5;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are in the middle of a dark and spooky haunted house.\n");
    printf("Your mission is to find the exit without getting caught by the ghosts that roam the halls.\n");
    printf("Good luck!\n");

    while(ghostPosition != playerPosition){
        printf("You are currently at position %d. Which direction would you like to move? (1 - Left, 2 - Right, 3 - Stay):\n", playerPosition);
        int direction;
        scanf("%d", &direction);

        switch(direction){
            case 1:
                if(playerPosition == 1){
                    printf("Oops! You hit a wall.\n");
                }else{
                    playerPosition--;
                }
                break;
            case 2:
                if(playerPosition == 10){
                    printf("Oops! You hit a wall.\n");
                }else{
                    playerPosition++;
                }
                break;
            case 3:
                printf("You stay in place.\n");
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }

        ghostPosition += rand() % 3 - 1;
        if(ghostPosition < 1){
            ghostPosition = 1;
        }else if(ghostPosition > 10){
            ghostPosition = 10;
        }

        if(ghostPosition == playerPosition){
            printf("Oh no! You ran into a ghost and died.\n");
            printf("GAME OVER\n");
            return 0;
        }

        printf("You hear ghostly sounds coming from direction %d.\n", ghostPosition);
        delay(1);
    }

    printf("Congratulations! You found the exit and escaped the haunted house!\n");
    printf("You win!\n");

    return 0;
}