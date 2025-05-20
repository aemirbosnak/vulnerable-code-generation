//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function prototypes
void welcome();
int generateRandomNumber(int);
void playGame(int);

int main() {
    welcome();
    int level;
    printf("Select difficulty level: \n1. Easy\n2. Medium\n3. Hard\n");
    scanf("%d", &level);
    fflush(stdin);
    if(level > 3 || level < 1) {
        printf("Invalid choice. Please try again.");
        return 0;
    }
    playGame(level);
    return 0;
}

// function for welcome screen
void welcome() {
    printf("\n********************************************");
    printf("\n*                                          *");
    printf("\n*   Welcome to the Future Pursuit Game     *");
    printf("\n*                                          *");
    printf("\n********************************************\n\n");
}

// function to generate a random number based on difficulty level
int generateRandomNumber(int level) {
    int maxLimit;
    switch(level) {
        case 1:
            maxLimit = 10;
            break;
        case 2:
            maxLimit = 20;
            break;
        case 3:
            maxLimit = 50;
            break;
        default:
            maxLimit = 5;
    }
    srand(time(0));
    int num = rand() % maxLimit + 1;
    return num;
}

// function to play the game
void playGame(int level) {
    printf("\nYou have to guess a number between 1 and %d\n", generateRandomNumber(level));
    printf("You have 3 tries only!\n");
    int guess, numTries = 3;
    while(numTries--) {
        printf("\nEnter your guess:\n");
        scanf("%d", &guess);
        fflush(stdin);
        if(guess == generateRandomNumber(level)) {
            printf("\nCongratulations! You guessed the right number.\n");
            return;
        } else {
            printf("Incorrect guess. ");
            if(guess < generateRandomNumber(level)) {
                printf("Guess higher.\n");
            } else {
                printf("Guess lower.\n");
            }
        }
    }
    printf("\nOops! You couldn't guess the number within 3 attempts.\n");
    return;
}