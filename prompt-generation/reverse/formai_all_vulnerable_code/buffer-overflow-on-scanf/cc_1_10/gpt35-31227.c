//FormAI DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to roll a dice
int rollDice(){
    return (rand() % 6) + 1;
}

//Main function
int main(){

    srand(time(NULL));
    int numRolls = 0, choice = 0;
    char response;

    printf("Welcome to the Dice Roller!\n");

    //Main loop
    while(1){
        
        printf("\nPlease select an option:\n");
        printf("1. Roll a dice.\n");
        printf("2. Exit program.\n");
        scanf("%d", &choice);

        //User chooses to roll a dice
        if(choice == 1){

            printf("\nHow many times would you like to roll the dice?\n");
            scanf("%d", &numRolls);
            printf("\n");

            for(int i = 0; i < numRolls; i++){
                printf("Roll #%d: %d\n", i + 1, rollDice());
            }

            printf("\n");

        }
        //User chooses to exit program
        else if(choice == 2){
            printf("\nAre you sure you want to exit? (y/n)\n");
            scanf(" %c", &response);

            if(response == 'y' || response == 'Y'){
                printf("\nThank you for using the Dice Roller!\n");
                break;
            }
            else{
                continue;
            }

        }
        //User selects an invalid option
        else{
            printf("\nInvalid selection, please try again.\n");
            continue;
        }
    }

    return 0;
}