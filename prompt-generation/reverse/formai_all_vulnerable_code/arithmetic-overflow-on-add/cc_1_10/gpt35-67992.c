//FormAI DATASET v1.0 Category: Dice Roller ; Style: funny
// Welcome to my Dice Roller program!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int die;
    int sides;
    int rollAgain = 1;
    srand(time(0)); // Seed the random number generator with time
    
    printf("\n------DICE ROLLER PROGRAM------\n");
    printf("Welcome to the one and only, Dice Roller!\n");
    printf("We have all sorts of dice and you can roll as many as you want.\n");
    printf("Are you ready to try your luck?(y/n)\n");
    char answer = getchar();
    if(answer == 'y' || answer == 'Y'){
        printf("\nGreat! Let's get started.\n");
        
        while(rollAgain){ // Keep rolling until the user wants to stop
            printf("\nChoose a die to roll:\n");
            printf("1 - D4\n");
            printf("2 - D6\n");
            printf("3 - D8\n");
            printf("4 - D10\n");
            printf("5 - D12\n");
            printf("6 - D20\n");
            printf("7 - D100\n");
            scanf("%d", &die);
            
            printf("\nHow many sides does your die have?\n");
            scanf("%d", &sides);
            
            int result = (rand() % sides) + 1;
            printf("\nYou rolled a %d!\n", result);
            
            printf("\nRoll again?(y/n)\n");
            char answer2 = getchar(); // Gets a whitespace character from the previous input
            answer2 = getchar();
            if(answer2 == 'n' || answer2 == 'N'){
                rollAgain = 0;
            }
        }
        
        printf("\nThanks for rolling with us! Good luck next time!\n");
    }
    else if(answer == 'n' || answer == 'N'){
        printf("\nNo worries! Come back anytime you're ready.\n");
    }
    else{ // Handling invalid input
        printf("\nSorry, I don't understand that. Please try again.\n");
    }
    return 0;
}