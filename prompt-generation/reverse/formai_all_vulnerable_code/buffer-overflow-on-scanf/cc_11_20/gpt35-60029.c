//FormAI DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int num1, num2, num3, guess1, guess2, guess3, tries = 0;
    char name[20];
    
    // get player name
    printf("Welcome to the C Table Game! Please enter your name: ");
    scanf("%s", name);
    
    // generate random numbers between 1 and 10
    srand(time(0));
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;
    num3 = rand() % 10 + 1;
    
    // explain the rules
    printf("\nHello, %s! Here's how to play: \n", name);
    printf("I have chosen three numbers between 1 and 10. Your job is to guess them in as few tries as possible. \n");
    printf("Every time you make a guess, I will tell you if each number is higher, lower, or the same as my number. \n");
    printf("Let's get started!\n");
    
    // ask player for their guess and compare to the random numbers
    do {
        printf("Guess # %d:\n", tries + 1);
        printf("Enter your three guesses separated by spaces: ");
        scanf("%d %d %d", &guess1, &guess2, &guess3);
        
        // compare guesses to random numbers
        if (guess1 == num1) {
            printf("Congratulations! Your first guess is correct!\n");
        } else if (guess1 < num1) {
            printf("Your first guess is too low.\n");
        } else {
            printf("Your first guess is too high.\n");
        }
        
        if (guess2 == num2) {
            printf("Congratulations! Your second guess is correct!\n");
        } else if (guess2 < num2) {
            printf("Your second guess is too low.\n");
        } else {
            printf("Your second guess is too high.\n");
        }
        
        if (guess3 == num3) {
            printf("Congratulations! Your third guess is correct!\n");
        } else if (guess3 < num3) {
            printf("Your third guess is too low.\n");
        } else {
            printf("Your third guess is too high.\n");
        }
        
        // increment tries
        tries++;
        
        // check for win condition
        if (guess1 == num1 && guess2 == num2 && guess3 == num3) {
            printf("Congratulations, %s! You win! It took you %d tries.\n", name, tries);
            return 0;
        } else {
            printf("Try again!\n");
        }
        
    } while (tries < 10); // maximum 10 tries
    
    // if 10 tries are reached without a win, game over
    printf("Game over, %s! You ran out of tries. The correct numbers were %d, %d, and %d.\n", name, num1, num2, num3);
    
    return 0;
}