//FormAI DATASET v1.0 Category: Dice Roller ; Style: creative
#include<stdio.h>
#include<stdlib.h>              // Needed for rand() and srand()
#include<time.h>                // Needed for time() operator
void welcome();
void roll_dice(int dice_x, int dice_y); // Function prototype

int main()
{
    int dice_x,dice_y;                  // Dice variables
    char choice;                        // User choice variable
    
    welcome();                          // Printing welcome message
    
   // Outer loop to repeat the game
    do{
        // User input for number of dice
        printf("Enter number of dice to roll: ");
        scanf("%d",&dice_x);
        
        // Error handling for invalid input
        if(dice_x <= 0){
            printf("\nInvalid input! Number of dice should be a positive integer.\n");
            continue;
        }
        
        // User input for number of sides for each dice
        printf("Enter number of sides for each dice: ");
        scanf("%d",&dice_y);
        
        // Error handling for invalid input
        if(dice_y <= 0){
            printf("\nInvalid input! Number of sides for each dice should be a positive integer.\n");
            continue;
        }
        
        // Function to roll the dice and print the result
        roll_dice(dice_x,dice_y);
        
        // User prompt for another game
        printf("\nDo you want to play again? (y/n)\n");
        getchar();                              // To clear input buffer
        scanf("%c",&choice);
    }while(choice == 'y' || choice == 'Y');      // Repeat game
    
    printf("\nThanks for playing!\n");
    
    return 0;
}

// Function to print welcome message
void welcome(){
    printf("*******************************************\n");
    printf("Welcome to C Dice Roller!\n");
    printf("*******************************************\n\n");
}

// Function to roll the dice and print the result
void roll_dice(int dice_x, int dice_y){
    int i,result;
    
    // Random seed generation
    srand(time(NULL));
    
    // Loop to print result of each dice roll
    printf("\nResult of rolling %d dice with %d sides each:\n",dice_x,dice_y);
    for(i=1;i<=dice_x;i++){
        result = rand()%dice_y + 1;          // Random number generation
        printf("Dice %d: %d\n",i,result);
    }
}