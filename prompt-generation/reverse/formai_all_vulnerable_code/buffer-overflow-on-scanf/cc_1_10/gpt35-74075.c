//FormAI DATASET v1.0 Category: Dice Roller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between 1 to 6
int rollDice(){
    int random_number = 1 + rand() % 6;
    return random_number;
}

int main(){
    int numDice, numRolls;
    char decision;
    
    printf("Welcome to the Dice Roller\n");
    printf("How many dice would you like to roll at once? ");
    scanf("%d", &numDice);
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls);
    
    while(1){
        printf("-----------------------\n");
        printf("Press enter to roll the dice.\n");
        printf("Enter 'q' to quit.\n");
        
        decision = getchar();
        
        if(decision == '\n'){
            int total = 0;
            
            for(int i = 1; i <= numDice; i++){
                int result = rollDice();
                
                printf("Die %d: %d\n", i, result);
                total += result;
            }
            
            printf("Total: %d\n", total);
        }
        else if(decision == 'q'){
            printf("Thanks for rolling with us!\n");
            break;
        }
        else{
            printf("Invalid input.\n");
        }
    }

    return 0;
}