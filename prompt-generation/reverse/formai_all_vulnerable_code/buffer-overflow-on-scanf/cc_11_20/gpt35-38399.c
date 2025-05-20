//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Setting seed for random numbers
    srand(time(0));
    
    int choice, score = 0;
    //Running the program in a loop until user decides to quit
    while(1) {
        //Printing menu
        printf("Welcome to Peaceful Game!\n");
        printf("1. Play Game\n");
        printf("2. View Score\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                //Player selects game mode
                printf("\nSelect game mode:\n");
                printf("1. Easy\n");
                printf("2. Medium\n");
                printf("3. Hard\n");
                printf("Enter your choice: ");
                int mode;
                scanf("%d", &mode);
                
                //Setting parameters based on selected game mode
                int max_num;
                int num_attempts;
                if(mode == 1) {
                    max_num = 10;
                    num_attempts = 5;
                }
                else if(mode == 2) {
                    max_num = 50;
                    num_attempts = 7;
                }
                else if(mode == 3) {
                    max_num = 100;
                    num_attempts = 10;
                }
                else {
                    printf("Invalid choice!\n");
                    break;
                }
                
                //Generating random number
                int num = rand() % max_num + 1;
                printf("\nGuess a number between 1 and %d\n", max_num);
                int guess, attempts_left = num_attempts;
                while(attempts_left > 0) {
                    printf("\nAttempts left: %d\n", attempts_left);
                    printf("Enter your guess: ");
                    scanf("%d", &guess);
                    if(guess < 1 || guess > max_num) {
                        printf("Invalid guess!\n");
                        continue;
                    }
                    if(guess == num) {
                        printf("Congratuations! You guessed the number!\n");
                        score += attempts_left * 10;
                        printf("Your score: %d\n", score);
                        break;
                    }
                    else {
                        printf("Incorrect guess! ");
                        if(guess < num) {
                            printf("Guess a higher number.\n");
                        }
                        else {
                            printf("Guess a lower number.\n");
                        }
                        attempts_left--;
                    }
                }
                if(attempts_left == 0) {
                    printf("You ran out of attempts. The number was %d.\n", num);
                }
                break;
                
            case 2:
                //Displaying score
                printf("Your score: %d\n", score);
                break;
                
            case 3:
                //Exiting program
                printf("Thank you for playing!\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}