//FormAI DATASET v1.0 Category: Table Game ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Function to get user's input */
int getUserInput() {
    int user_input;
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &user_input);
    return user_input;
}

/* Function to get computer's random number */
int getComputerInput() {
    srand(time(NULL));
    return rand() % 10 + 1;
}

/* Function to compare user's and computer's numbers and determine winner */
void determineWinner(int user_input, int comp_input) {
    if(user_input > comp_input) {
        printf("Congratulations! You won!\n");
    } else if(comp_input > user_input) {
        printf("Sorry, you lost!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    int user_input, comp_input;
    
    printf("Welcome to the Table Game!\n\n");
    
    /* Loop to play multiple rounds */
    while(1) {
        /* Get user's input */
        user_input = getUserInput();
        
        /* Get computer's input */
        comp_input = getComputerInput();
        
        /* Print both inputs */
        printf("Your input: %d\n", user_input);
        printf("Computer's input: %d\n", comp_input);
        
        /* Determine winner */
        determineWinner(user_input, comp_input);
        
        /* Ask user if they want to play another round */
        printf("\nWould you like to play another round? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if(choice != 'y') break;
    }
    
    printf("\nThanks for playing the Table Game!");
    
    return 0;
}