//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to simulate a coin toss
int coinToss() {
    return rand() % 2; //Returns either 0 or 1
}

//Function to simulate moving forward
void moveForward() {
    printf("You moved forward\n");
}

//Function to simulate moving left
void moveLeft() {
    printf("You moved left\n");
}

//Function to simulate moving right
void moveRight() {
    printf("You moved right\n");
}

//Function to simulate encountering a ghost
void encounterGhost() {
    printf("You encountered a ghost! Run away!\n");
}

//Function to simulate encountering a treasure chest
void encounterTreasure() {
    printf("You found a treasure! Congrats!\n");
}

int main() {
    srand(time(NULL)); //Seed the random number generator
    
    int numSteps = 10; //Player starts with 10 steps
    int numTreasuresFound = 0; //Player starts with 0 treasures found
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are currently standing outside a spooky mansion.\n");
    printf("Are you ready to enter? (y/n): ");
    
    char choice;
    scanf("%c", &choice);
    
    if (choice == 'y') {
        printf("Let the adventure begin!\n");
        
        //Loop for the game
        while (numSteps > 0) {
            
            //Simulate a coin toss to determine where to move
            int coin = coinToss();
            
            if (coin == 0) {
                moveForward();
                numSteps--;
                
                //Simulate a chance to encounter a ghost
                int ghost = coinToss();
                
                if (ghost == 0) {
                    encounterGhost();
                    numSteps -= 3;
                }
                
                //Simulate a chance to encounter a treasure
                int treasure = coinToss();
                
                if (treasure == 0) {
                    encounterTreasure();
                    numTreasuresFound++;
                }
                
            } else if (coin == 1) {
                int direction = coinToss();
                
                if (direction == 0) {
                    moveLeft();
                    numSteps--;
                    
                    //Simulate a chance to encounter a ghost
                    int ghost = coinToss();
                    
                    if (ghost == 0) {
                        encounterGhost();
                        numSteps -= 3;
                    }
                    
                    //Simulate a chance to encounter a treasure
                    int treasure = coinToss();
                    
                    if (treasure == 0) {
                        encounterTreasure();
                        numTreasuresFound++;
                    }
                    
                } else if (direction == 1) {
                    moveRight();
                    numSteps--;
                    
                    //Simulate a chance to encounter a ghost
                    int ghost = coinToss();
                    
                    if (ghost == 0) {
                        encounterGhost();
                        numSteps -= 3;
                    }
                    
                    //Simulate a chance to encounter a treasure
                    int treasure = coinToss();
                    
                    if (treasure == 0) {
                        encounterTreasure();
                        numTreasuresFound++;
                    }
                    
                }
            }
            
            //Check if player has run out of steps
            if (numSteps <= 0) {
                printf("You ran out of steps and did not find all the treasures. Better luck next time!\n");
                break;
            }
            
            //Check if player has found all the treasures
            if (numTreasuresFound == 3) {
                printf("You found all the treasures and completed the game! Great job!\n");
                break;
            }
            
            //Output current number of steps and treasures found
            printf("You have %d steps remaining\n", numSteps);
            printf("You have found %d out of 3 treasures\n", numTreasuresFound);
        }
        
    } else {
        printf("Game over. Goodbye!\n");
    }
    
    return 0;
}